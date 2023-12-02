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
        int possible = 1;
        int amount = 0;

        char* pointer;

        for(pointer = strtok(str, " :,;\n"); pointer != NULL; pointer = strtok(NULL, " :,;\n")){
            if(pointer[0] - '0' < 10){
                amount = atoi(pointer);

            }
            else{
                switch(pointer[0]){
                    case 'r': if(amount > 12) {possible = 0;} break;
                    case 'g': if(amount > 13) {possible = 0;} break;
                    case 'b': if(amount > 14) {possible = 0;} break;
                }
            }
            //If that number of balls isn't possible skip the rest of the line
            if(!possible){
                break;
            }
        }
        if(possible){
            answer += id;
        }
        id++; 
    }

    fclose(file);

    printf("The Answer is %d\n", answer);

    return 0;
}