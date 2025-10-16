#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "getinstall.c"

// Main wget command
void wget_command(const char *arg) {
    if(!arg || strlen(arg) == 0) {
        printf("Usage: wget <github link>\n");
        return;
    }

    // Extract filename from URL
    const char *filename = strrchr(arg, '/');
    if(filename) filename++;
    else filename = arg;

    printf("Downloading from: %s\n", arg);
    sleep(2); // simulate download

    // downloaded file goes into userdata, NOT lib
    if(install_file(filename, 0)) {
        printf("Downloaded %s successfully to userdata!\n", filename);
    }
}
