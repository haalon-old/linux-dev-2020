#include <stdint.h>
#include "buf.h"

int main(void)
{
    int *volatile p = 0;
    buf_trunc(p, PTRDIFF_MAX);
    // error caught by BUF_ABORT
    buf_free(p);

    return 0;
}
