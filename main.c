#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define MAX 1000

int concat_idx = 0;

void handleLine(char* line, char* concat) {
    printf("[%s]\n", line);

    memcpy(concat + concat_idx, line, strlen(line));
    concat_idx += strlen(line);
}

void handleConcat(char* concat) {
    printf("[%s]\n", concat);
    free(concat);
}

int main() {
    // Open file.
    FILE *file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read file line by line.
    // Output each line.
    char line[N];
    char* concat = (char*) malloc(N*MAX);
    memset(concat, 0x0, N*MAX);
    int i = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            handleLine(line, concat);
            i = 0;
            memset(line, 0x0, N);
            continue;
        }

        line[i] = ch;
        i++;
    }
    handleLine(line, concat);
    handleConcat(concat);

    // Cleanup everything.
    memset(concat, 0x0, N*MAX);
    fclose(file);

    return 0;
}
