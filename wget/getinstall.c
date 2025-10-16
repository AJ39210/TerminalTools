#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define FS_ROOT "src/FS_main"
#define LIB_DIR FS_ROOT"/lib"
#define USER_DIR FS_ROOT"/userdata"

// Ensure folder exists
static void ensure_dir(const char *path) {
    struct stat st;
    if(stat(path, &st) != 0 || !S_ISDIR(st.st_mode)) {
        mkdir(path, 0755);
    }
}

// Install a file or app
// is_app = 1 → install in lib
// is_app = 0 → install in userdata
int install_file(const char *filename, int is_app) {
    ensure_dir(LIB_DIR);
    ensure_dir(USER_DIR);

    char dest[1024];
    if(is_app)
        snprintf(dest, sizeof(dest), "%s/%s", LIB_DIR, filename);
    else
        snprintf(dest, sizeof(dest), "%s/%s", USER_DIR, filename);

    FILE *f = fopen(dest, "w");
    if(!f) {
        printf("Failed to install %s\n", filename);
        return 0;
    }
    fprintf(f, "# Mock file for %s\n", filename);
    fclose(f);
    printf("Installed %s to %s\n", filename, is_app ? "lib" : "userdata");
    return 1;
}
