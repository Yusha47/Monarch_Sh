#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile = freopen("F:\\GIT\\input.txt", "r", stdin);

    if (inputFile == NULL) {
        perror("Error opening the file");
        return 1;
    }

    char line[1000];
    int lineCount = 0;

    printf("Line No. of double number declarations are: ");

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        lineCount++;

        // Use strstr to check if the line contains "double" and "double" again
        if (strstr(line, "double") != NULL && strstr(line, "double") != strstr(line, "double*")) {
            printf("%d ", lineCount);
        }
    }

    fclose(inputFile);

    return 0;
}
