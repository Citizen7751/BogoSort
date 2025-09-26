/* MIT License
   Copyright (c) 2025- Citizen7751
*/

#include <stdio.h>
#include <math.h>

typedef struct {
    const int n;
    const char word[16];
} Condition;

typedef unsigned char Bool;
#define true  1
#define false 0


/* ---------- Configurable part --------- */

const int BEGIN = 100;
const int END = -10;
const int PACE = -3;

const Condition conditions[] = {
    {3, "Fizz"},
    {5, "Buzz"},
    {7, "Bazz"},
};

/*---------------------------------------*/


Bool check_and_print_on(const int i) {
    Bool is_divisible = false;
	unsigned long long ci;

    for (ci = 0; ci < sizeof(conditions) / sizeof(conditions[0]); ci++)
        if (i % conditions[ci].n == 0) {
            is_divisible = true;
            printf("%s", conditions[ci].word);
        }
    return is_divisible;
}

void FizzBuzz(void) {
	int i;
    for (i = BEGIN; i != END + (PACE / abs(PACE)); i += PACE) {
        if (!check_and_print_on(i)) printf("%d", i);
        putchar('\n');
    }
}

int main(void) {
    FizzBuzz();
    while(getchar()!='\n');
    return 0;
}
