#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_LENGTH 256

int main() {
    char *lines[MAX_LINES];
    int count = 0;
    char input[MAX_LENGTH];

    printf("Micro Text Editor (type ':q' to quit)\n");

    while(1) {
        printf("> ");
        if(!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0; // remove newline

        if(strcmp(input, ":q") == 0) break;

        if(count < MAX_LINES) {
            lines[count] = strdup(input);
            count++;
        } else {
            printf("Maximum lines reached!\n");
        }
    }

    // Save file
    char filename[128];
    printf("Save as: ");
    if(!fgets(filename, sizeof(filename), stdin)) return 0;
    filename[strcspn(filename, "\n")] = 0;

    FILE *f = fopen(filename, "w");
    if(!f) {
        printf("Failed to save file.\n");
        return 1;
    }
    for(int i=0;i<count;i++) {
        fprintf(f, "%s\n", lines[i]);
        free(lines[i]);
    }
    fclose(f);
    printf("File saved: %s\n", filename);
    return 0;
}
