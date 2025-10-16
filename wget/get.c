#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "getinstall.c" // helper functions

void wget_command(const char *arg) {
    if(!arg || strlen(arg) == 0) {
        printf("Usage: wget <URL>\n");
        return;
    }

    // Extract filename from URL
    const char *filename = strrchr(arg, '/');
    if(filename) filename++;
    else filename = arg;

    printf("Downloading from: %s\n", arg);
    sleep(2); // simulate download

    // Downloads go to userdata folder
    if(install_file(filename, 0)) {  // 0 = userdata
        printf("Downloaded %s successfully to userdata!\n", filename);
    }
}
