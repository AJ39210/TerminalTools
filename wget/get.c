#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getinstall.c" // use the helper functions

// Main wget command
void wget_command(const char *arg) {
    if(!arg || strlen(arg) == 0) {
        printf("Usage: wget <github link>\n");
        return;
    }

    // For simplicity, extract the filename from URL
    const char *filename = strrchr(arg, '/');
    if(filename) filename++; // skip '/'
    else filename = arg;

    printf("Downloading from: %s\n", arg);
    sleep(2); // simulate download

    // install in userdata folder
    if(install_file(filename, 0)) {
        printf("Downloaded %s successfully!\n", filename);
    }
}
