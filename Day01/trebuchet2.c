#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int isnumber(char* c);

int main() {
    FILE* file = fopen("input.txt", "r");
    char* line = NULL;
    size_t len = 0;
    size_t read;
    int answer = 0;

    // Check File Empty
    if (file == NULL) {
        perror("Error Opening File");
        return 1;
    }

    // Read each line
    while ((read = getline(&line, &len, file)) != -1) {
        int firstDigit = -1, lastDigit = -1;

        // Search for first digit using isnumber function
        for (size_t i = 0; i < read; i++) {
            if (isnumber(&line[i]) != 0) {
                firstDigit = isnumber(&line[i]);
                break;
            }
        }

        // Search for last digit using isnumber function
        for (ssize_t i = read - 1; i >= 0; i--) {
            if (isnumber(&line[i]) != 0) {
                lastDigit = isnumber(&line[i]);
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

int isnumber(char* c)
{
    //Convert from ASCII
    if(*c > 48 && *c < 58)
        return (*c)-48;
    
    //Check for all possible substring digit equivalents
    switch(*c){
        //One
      case 'o':
        if(*(c+1)=='n'&& *(c+2)=='e')
            return 1;
        break;
        //Two
      case 't':
        if(*(c+1)=='w'&& *(c+2)=='o')
            return 2;
        //Three
        if(*(c+1)=='h'&& *(c+2)=='r')
            if(*(c+3)=='e'&& *(c+4)=='e')
            return 3;
        break;
      case 'f':
        //Four
        if(*(c+1)=='o'&& *(c+2)=='u'&& *(c+3)=='r')
            return 4;
        //Five
        if(*(c+1)=='i'&& *(c+2)=='v'&& *(c+3)=='e')
            return 5;
        break;
      case 's':
        //Six
        if(*(c+1)=='i'&& *(c+2)=='x')
            return 6;
        //Seven
        if(*(c+1)=='e'&& *(c+2)=='v')
            if(*(c+3)=='e'&& *(c+4)=='n')
            return 7;
        break;
      case 'e':
        //Eight
        if(*(c+1)=='i'&& *(c+2)=='g')
            if(*(c+3)=='h'&& *(c+4)=='t')
            return 8;
        break;
      case 'n':
      //Nine
        if(*(c+1)=='i'&& *(c+2)=='n'&& *(c+3)=='e')
            return 9;
    }
    return 0;
}