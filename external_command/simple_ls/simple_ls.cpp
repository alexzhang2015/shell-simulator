#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
 
static char *dup_str(const char *s) {
    size_t n = strlen(s) + 1;
    char *t = (char*) malloc(n);
    if (t) {
        memcpy(t, s, n);
    }
    return t;
}
 
static char **get_all_files(const char *path) {
    DIR *dir;
    struct dirent *dp;
    char **files;
    size_t alloc, used;
 
    if (!(dir = opendir(path))) {
        goto error;
    }
 
    used = 0;
    alloc = 10;
    if (!(files = (char**) malloc(alloc * sizeof *files))) {
        goto error_close;
    }
 
    while ((dp = readdir(dir))) {
        if (used + 1 >= alloc) {
            size_t new_thing = alloc / 2 * 3;
            char **tmp = (char**) realloc(files, new_thing * sizeof *files);
            if (!tmp) {
                goto error_free;
            }
            files = tmp;
            alloc = new_thing;
        }
        if (!(files[used] = dup_str(dp->d_name))) {
            goto error_free;
        }
        ++used;
    }
 
    files[used] = NULL;
 
    closedir(dir);
    return files;
 
error_free:
    while (used--) {
        free(files[used]);
    }
    free(files);
 
error_close:
    closedir(dir);
 
error:
    return NULL;
}
 
int main(int argc, char **argv) {
    char **files;
    size_t i;
 
    if (argc != 2) {
        fprintf(stderr, "Usage: %s DIRECTORY\n", argv[0]);
        return EXIT_FAILURE;
    }
 
    files = get_all_files(argv[1]);
    if (!files) {
        fprintf(stderr, "%s: %s: something went wrong\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }
 
    for (i = 0; files[i]; ++i) {
        printf("%s\n", files[i]);
    }
 
    for (i = 0; files[i]; ++i) {
        free(files[i]);
    }
    free(files);
 
    return EXIT_SUCCESS;
}