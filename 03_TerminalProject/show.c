#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns 0 if nothing to show with these offsets
int show(WINDOW *win, FILE *f, int height, int width, int line_off, int col_off)
{
    int lastchar;
    werase(win);
    fseek(f,0,SEEK_SET); // posistion at the file beginning

    // skip first 'line_off' lines
    for (int i = 0; i < line_off;)
    {
        lastchar = fgetc(f);
        if(lastchar == '\n') i++;
        if(lastchar == EOF) return 0;
    }

    int new_width = width + col_off;
    char buf[new_width];
    memset(buf, 0, new_width);

    int nonempty_cols = 0;
    for (int i = 0; i < height; ++i)
    {
        
        if(fgets(buf, new_width, f) != NULL)
            if(strlen(buf) > col_off)
            {
                wprintw(win, "%s", buf + col_off);
                nonempty_cols++;
            }
            else
                wprintw(win, "%c", '\n');
        else
            return nonempty_cols*i;

    }
    wrefresh(win);
    return nonempty_cols;
}

#define WIN_TITLE_OFFSET 2
// why is it not in curses.h?
#define KEY_ESCAPE 27

void control_loop(FILE *f, char *filename)
{
    initscr();

    //don't buffer characters
    //make them available as soon as the user types them
    cbreak();

    noecho();
    printw("File: %s\n", filename);
    for (int i = 0; i < COLS; ++i)
        addch('_');

    refresh();

    int curr_line=0, curr_col=0;

    int rows = LINES - WIN_TITLE_OFFSET;
    WINDOW *win = newwin(rows, COLS, WIN_TITLE_OFFSET, 0);

    keypad(win, TRUE);
    scrollok(win, TRUE);
    // scrollok(win, TRUE);
    show(win,f, rows, COLS, curr_line, curr_col);

    int c = wgetch(win);
    int status = 1;
    while (c != KEY_ESCAPE) {
        if ((c == ' ' || c == KEY_DOWN) && status) curr_line++;
        if (c == KEY_UP) curr_line = curr_line == 0 ? 0 : curr_line-1;
        if (c == KEY_RIGHT && status) curr_col++;
        if (c == KEY_LEFT) curr_col = curr_col == 0 ? 0 : curr_col-1;

        if (c == KEY_NPAGE && status) curr_line += rows;
        if (c == KEY_PPAGE) curr_line = curr_line < rows ? 0 : curr_line-rows;

        status = show(win,f, rows, COLS, curr_line, curr_col);
        c = wgetch(win); 
    }

    delwin(win);
    endwin();
}


int main (int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: show filename\n");
        return 1;
    }
    
    FILE *f = fopen(argv[1], "r");

    setlocale(LC_ALL, "");
    control_loop(f, argv[1]);
    fclose(f);
} 
