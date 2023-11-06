#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

void handleLine(char* line) {
    printf("[%s]\n", line);
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
    int i = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            handleLine(line);
            i = 0;
            memset(line, 0x0, N);
            continue;
        }

        line[i] = ch;
        i++;
    }
    handleLine(line);

    // Cleanup everything.
    fclose(file);

    return 0;
}
