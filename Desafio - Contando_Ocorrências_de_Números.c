#include <stdio.h>


typedef struct {
    int num;
    int rep;
} repetition;

int numbers[10];
int main(){

    int number;
    for(number = 0; number < 10; number++) {
        scanf("%d", &numbers[number]);
    }

    int i, j, num_repetitions = 0;
    repetition repetitions[10];

    for(i = 0; i < 10; i++) {
        int entrada = 0;
        for(j = 0; j < num_repetitions; j++) {
            if(numbers[i] == repetitions[j].num) {
                entrada = 1;
                repetitions[j].rep++;
                break;
            }
        }
        if(!entrada) {
            repetitions[num_repetitions].num = numbers[i];
            repetitions[num_repetitions].rep = 1;
            num_repetitions++;
        }
    }

    for(i = 0; i < num_repetitions; i++) {
        printf("%d => %d\n",repetitions[i].num, repetitions[i].rep);
    }
    return 0;
}
