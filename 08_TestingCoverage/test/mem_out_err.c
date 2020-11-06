#include <stdint.h>
#include "buf.h"

int main(void)
{
    int *volatile p = 0;
    size_t max = (PTRDIFF_MAX - sizeof(struct buf)) / sizeof(*p) + 1;
    buf_grow(p, max);
    buf_grow(p, max);
    // error caught by BUF_ABORT
    buf_free(p);

    return 0;
}
