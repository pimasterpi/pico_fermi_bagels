#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    /* [0] Generate Random Sequence */

    /* [0.0] Seed RNG */

    srand(time(NULL));

    /* [0.1] Store Sequence As Separate Digits */

    int sequence[4] = {0};

    /* [0.2] Store Sequence As Number of Individual Digits */

    int seq_int[10] = {0};

    /* [0.3] Generate Sequence & Assign Values  */

    for (int i = 0; i < 4; i++) {
        sequence[i] = rand() % 10;
        seq_int[sequence[i]]++;
    }

    /* [1] Variables For Guess */

    /* [1.0] Guess As One Number */

    int input = 0;

    /* [1.1] Guess As Separate Digits */

    int guess[4] = {0};

    /* [2] Variables For Guess Validity */

    /* [2.0] Store Number of Picos Per Number */

    int pico_print[10] = {0};

    /* [2.1] Stores Fermi Value of Digits */

    int is_fermi[4] = {0};

    /* [2.2] Store Total Picos */

    int pico = 0;

    /* [2.3] Store Total Fermis */

    int fermi = 0;

    /* [3] Begin Game */

    printf("Pico Fermi Bagels\nPlease input a 4-digit number to begin\n");

    while (1) {

        /* [4] Zero Values of Variables For Guess Validity */

        /* [4.0] Zero "pico_print" */

        for (int i = 0; i < 10; i++) {
            if (pico_print[i]) {
                pico_print[i] = 0;
            }
        }

        /* [4.1] Zero "is_fermi" */

        for (int i = 0; i < 4; i++) {
            if (is_fermi[i]) {
                is_fermi[i] = 0;
            }
        }

        /* [4.2] Zero "pico" */

        pico = 0;

        /* [4.3] Zero "pico" */

        fermi = 0;

        /* [5] Receive Guess */

        /* [5.0] Read Input From Console */

        scanf("%d", &input);

        /* [5.1] Translate From "input" to "guess" form */

        for (int i = 3; i > 0; i--) {
            guess[i] = input % 10;
            input /= 10;
        }
        guess[0] = input % 10;

        /* [5.2] Check For Any Fermis */

        for (int i = 0; i < 4; i++) {
            if (sequence[i] == guess[i]) {
                is_fermi[i]++;
                fermi++;
            }
        }

        /* [5.3] Check For Any Picos */

        for (int i = 0; i < 4; i++) {
            if ((!is_fermi[i]) && (seq_int[guess[i]]) && (pico_print[guess[i]] != seq_int[guess[i]])) {
                for (int j = 0; j < 4; j++) {
                    if ((guess[i] == sequence[j]) && (!is_fermi[j])) {
                        pico_print[guess[i]]++;
                        pico++;
                        break;
                    }
                }
            }
        }

        /* [6] Print Validity of Guess*/

        /* [6.0] Print "Bagels" If No Valid Guesses */
        /* Else Print Correct Number of "Fermi"s or "Pico"s  */

        if (!(fermi + pico)) {
            printf("Bagels");
        }
        else {
            for (int i = 0; i < fermi; ++i) {
                printf("Fermi ");
            }

            /* [6.1] Break Loop If Guess Is Completely Correct */

            if (fermi == 4) {
                break;
            }

            for (int i = 0; i < pico; ++i) {
                printf("Pico ");
            }
        }

        /* [6.2] Finish Printout If Guess Is Partially Correct Or Incorrect */

        printf("\n");
    }

    return 0;
}
