#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE* file;
    char str[256];
    int answer = 0;
    int id = 1;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while(fgets(str, sizeof str, file) != NULL){
        int amount = 0;
        int red = 0;
        int green = 0;
        int blue = 0;

        char* pointer;

        for(pointer = strtok(str, " :,;\n"); pointer != NULL; pointer = strtok(NULL, " :,;\n")){
            if(pointer[0] - '0' < 10){
                amount = atoi(pointer);

            }
            else{
                switch(pointer[0]){
                    case 'r': if(amount > red) {red = amount;} break;
                    case 'g': if(amount > green) {green = amount;} break;
                    case 'b': if(amount > blue) {blue = amount;} break;
                }
            }
        }
        answer += (red * green * blue);
        id++; 
    }

    fclose(file);

    printf("The Answer is %d\n", answer);

    return 0;
}