#include <glib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 81

int comparator(gpointer a, gpointer b, gpointer hash) {
    gpointer v1 = g_hash_table_lookup(hash, (char *) a);
    gpointer v2 = g_hash_table_lookup(hash, (char *) b);
    // sort in descending order
    return GPOINTER_TO_INT(v2) - GPOINTER_TO_INT(v1);
}

int main(int argc, char** argv) {
    char buf[MAXLEN];
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

    while(fgets(buf, MAXLEN, stdin)) {
        // printf("%-4d: %s",i++, buf);
        
        char ** words = g_strsplit_set(buf, " \t\n\r,.()[]{}<>\\/\"\';:+-*=#%", 0);
        for(int i = 0; words[i]; i++) {
            if(words[i][0] == '\0') continue;

            gpointer n = g_hash_table_lookup(hash, words[i]);
            if(n)
            {
                int nn = GPOINTER_TO_INT(n) + 1;
                g_hash_table_insert(hash, g_strdup(words[i]), GINT_TO_POINTER(nn));
            }
            else
                g_hash_table_insert(hash, g_strdup(words[i]), GINT_TO_POINTER(1));  
        }
        g_strfreev(words);
    }

    GList* keys = g_list_sort_with_data(g_hash_table_get_keys(hash), (GCompareDataFunc)comparator, hash);
    for (GList* it = keys; it; it = it->next) {
        gpointer v = g_hash_table_lookup(hash, it->data);
        printf("%-5d: %s\n", GPOINTER_TO_INT(v), (char *)it->data);
    }

    g_hash_table_destroy(hash);
    g_list_free(keys);

    return 0;
}