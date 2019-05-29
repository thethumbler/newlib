#include <stdint.h>

#define MAXNAMELEN 256

struct dirent {
    size_t d_ino;   // FIXME 
    char d_name[MAXNAMELEN];
    int d_type; /* FIXME */
};

typedef struct {
    int dd_fd;
} DIR;

DIR *opendir(const char *fn);
int closedir(DIR *dir);
struct dirent *readdir(DIR *dir);

#define DT_UNKNOWN  0
#define DT_FIFO     1
#define DT_CHR      2
#define DT_DIR      3
#define DT_BLK      4
#define DT_REG      5
#define DT_LNK      6
#define DT_SOCK     7

int scandir(const char *dirp, struct dirent ***namelist,
              int (*filter)(const struct dirent *),
              int (*compar)(const struct dirent **, const struct dirent **));
int alphasort(const struct dirent **a, const struct dirent **b);
int versionsort(const struct dirent **a, const struct dirent **b);
