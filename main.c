#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));

    int sequence[4] = {0};

    for (int i = 0; i < 4; ++i) {
        sequence[i] = rand() % 10;
        printf("%d", sequence[i]);
    }
    printf("\n");

    int guess[4] = {0};
    int pico_arr[10] = {0};


    scanf("%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);



    return 0;
}
