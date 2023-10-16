#include <stdio.h>
#include <stdlib.h>

void combo_finder(int score) {
    int i, j, k, l;

    printf("Score: %d\n", score);
    printf("TD: %d, FG: %d, Safety: %d, TD+2ptConv: %d, TD+1ptFG: %d\n", i, j, k, l, i + l + 1);
}

int main() {
    int score;

    printf("Enter Score to find the combos, otherwise enter 0 to exit: ");
    scanf("%d", &score);

    while (score > 0) {
        combo_finder(score);

        printf("Enter a score (0 to terminate): ");
        scanf("%d", &score);
    }

    return 0;
}
