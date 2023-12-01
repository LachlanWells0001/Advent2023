#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int answer = 0;

    // Check File Empty
    if (file == NULL) {
        perror("Error Opening File");
        return 1;
    }

    // Read each line
    while ((read = getline(&line, &len, file)) != -1) {
        int firstDigit = -1, lastDigit = -1;

        // Search for first digit
        for (size_t i = 0; i < read; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                firstDigit = line[i] - '0';
                break;
            }
        }

        // Search for last digit
        for (ssize_t i = read - 1; i >= 0; i--) {
            if (line[i] >= '0' && line[i] <= '9') {
                lastDigit = line[i] - '0';
                break;
            }
        }

        // Check if valid digits were found
        if (firstDigit != -1 && lastDigit != -1) {
            // Add to total
            answer += (firstDigit * 10 + lastDigit);
        }
    }

    fclose(file);
    if (line) {
        free(line);
    }

    printf("The Answer is %d\n", answer);

    return 0;
}
