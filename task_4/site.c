#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>


struct stat sb2;
// https://linux.die.net/man/3/nftw
static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf)
{
  // https://linux.die.net/man/2/stat
  if (stat(fpath, &sb2) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    printf("%-3s %2d %7jd   %-40s %-3d %-10s  I-node: %-7ld\n",
        (tflag == FTW_D) ?   "D"   : (tflag == FTW_DNR) ? "DNR" :
        (tflag == FTW_DP) ?  "DP"  : (tflag == FTW_F) ?   "F" :
        (tflag == FTW_NS) ?  "NS"  : (tflag == FTW_SL) ?  "SL" :
        (tflag == FTW_SLN) ? "SLN" : "???",
        ftwbuf->level, (intmax_t) sb->st_size,
        fpath, ftwbuf->base, fpath + ftwbuf->base, (long) sb2.st_ino);
    return 0;           /* To tell nftw() to continue */
}

int
main(int argc, char *argv[])
{
    int flags = 0;

   if (argc > 2 && strchr(argv[2], 'd') != NULL)
        flags |= FTW_DEPTH;
    if (argc > 2 && strchr(argv[2], 'p') != NULL)
        flags |= FTW_PHYS;

   if (nftw(".", display_info, 20, 0) == -1) {
        perror("nftw");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
