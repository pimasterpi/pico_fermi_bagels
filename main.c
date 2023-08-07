#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));

    int sequence[4] = {0};
    int seq_int[10] = {0};



    for (int i = 0; i < 4; i++) {
        sequence[i] = rand() % 10;
        seq_int[sequence[i]]++;
    }
    printf("\n");

    int input = 0;
    int guess[4] = {0};

    int pico_print[10] = {0};
    int print[4] = {0};

    int pico = 0;
    int fermi = 0;

    while (1) {
        for (int i = 0; i < 10; i++) {
            if (pico_print[i]) {
                pico_print[i] = 0;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (print[i]) {
                print[i] = 0;
            }
        }

        pico = 0;
        fermi = 0;


        scanf("%d", &input);

        for (int i = 3; i > 0; i--) {
            guess[i] = input % 10;
            input /= 10;
        }
        guess[0] = input % 10;

        for (int i = 0; i < 4; i++) {
            if (sequence[i] == guess[i]) {
                print[i]++;
                fermi++;
            }
        }

        for (int i = 0; i < 4; i++) {
            if ((!print[i]) && (seq_int[guess[i]]) && (pico_print[guess[i]] != seq_int[guess[i]])) {
                for (int j = 0; j < 4; j++) {
                    if ((guess[i] == sequence[j]) && (!print[j])) {
                        pico_print[guess[i]]++;
                        pico++;
                    }
                }
            }
        }

        if (!(fermi + pico)) {
            printf("Bagels");
        }
        else {
            for (int i = 0; i < fermi; ++i) {
                printf("Fermi ");
            }

            if (fermi == 4) {
                break;
            }

            for (int i = 0; i < pico; ++i) {
                printf("Pico ");
            }
        }
        printf("\n");
    }

    return 0;
}
