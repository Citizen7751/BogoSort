/* MIT License
   Copyright (c) 2026- Citizen7751
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


#define TXT_MAX_LEN 4096

char txt[TXT_MAX_LEN] = {0};


void get_input_txt(void)
{
    printf("> ");
    fgets(txt, TXT_MAX_LEN, stdin);
    txt[strlen(txt) - 1] = '\0';
}


void print_txt_randomcase(void)
{
    unsigned int i;

    srand(time(NULL));

    for (i = 0; i < strlen(txt); i++) {
        printf("%c",
               isalpha(txt[i])
               ? (rand() % 2
                  ? tolower(txt[i])
                  : toupper(txt[i]))
               : txt[i]);
    }
}


int main(void)
{
    get_input_txt();
    print_txt_randomcase();

    while(getchar() != '\n');
    return 0;
}
