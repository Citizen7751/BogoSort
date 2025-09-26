/* MIT License
   Copyright (c) 2024- Citizen7751
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int Uint;
typedef unsigned char Bool;
#define true  1
#define false 0


#ifdef _WIN32
  #include <windows.h>
#elif __linux__
  #include <unistd.h>
  void Sleep(Uint d) {
     usleep(d * 1000);
  }
#endif


Bool is_sorted(double* arr, const Uint* l) {
	Uint i;
    for (i = 1; i < *l; i++)
        if (arr[i-1] > arr[i]) return false;
    return true;
}

void swap(double* a, double* b) {
    double c = *a;
    *a = *b;
    *b = c;
}

void mix_elements(double* arr, const Uint* l) {

    Uint i1, i2;
	Uint i;
    for (i = 0; i < *l; i++) {
        i1 = rand() % *l;
        i2 = rand() % *l;
        swap(&arr[i1], &arr[i2]);
    }
}

void print_elements(double* arr, const Uint* l, const char endc) {
	Uint i;
    for (i = 0; i < *l; i++)
        printf("%lf ", arr[i]);
    putchar(endc);
}


/* -------------------------------------------- */

void BogoSort_Verbose(double* arr, const Uint* l, Uint* i) {
    while(!is_sorted(arr, l)) {
        mix_elements(arr, l);
        (*i)++;
        print_elements(arr, l, '\r');
        Sleep(300);
    }
}

void BogoSort_Quiet(double* arr, const Uint* l, Uint* i) {
    while (!is_sorted(arr, l)) {
        mix_elements(arr, l);
        (*i)++;
    }
}

/* -------------------------------------------- */

int main(void) {

    double arr[] = { 3.501, 8.9843, 2.2114, 1.9981 };
    const Uint length = sizeof(arr)/sizeof(arr[0]);
    Uint iterations = 0;

    srand(time(NULL));
    
    printf("Original arrangement:\n");
    print_elements(arr, &length, '\n');

    BogoSort_Verbose(arr, &length, &iterations);
    /* BogoSort_Quiet(arr, &length, &iterations); */

	printf("\nSorted arrangement:\n");
    print_elements(arr, &length, '\n');


    printf("\nDone in %u iterations(s).\nPress Enter to exit.\n", iterations);
    while (getchar()!='\n');
    return EXIT_SUCCESS;
}
