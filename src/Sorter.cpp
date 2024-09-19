#include <stdio.h>
#include <assert.h>

#include "Sorter.h"
#include <StructuresForOnegin.h>

int StrCmp(char* str1, char* str2);
void AddrSwapper(char** a, char** b);

void Sorter(struct Book* Onegin)
{
$$$ assert(Onegin);
    for(int i = 0; i < Onegin->count_lines; i++)
    {
        for(int j = 0; j < Onegin->count_lines - i; j++)
        {
            if(StrCmp(Onegin->adreses[j], Onegin->adreses[j+1]))
            {
                printf(" %d = ", Onegin->adreses[j]);
                AddrSwapper(&(Onegin->adreses[j]), &(Onegin->adreses[j+1]));
                printf(" %d \n", Onegin->adreses[j]);
            }
        }
        printf("\n %d \n", i);
    }
}

// isalpha

int StrCmp(char *str1, char *str2)
{
    int i = 0;
    while(1)
    {
        //printf("%d \n", __LINE__); //!!txlib!! $$ $meow(hello)

        if(str1[i] != str2[i])  return (str1[i] - str2[i]);
        if(str2[i] == '\0')     return 0;
        if(str1[i] == '\0')     return 1;
        i+=1;
    }
    return 0;
}

void AddrSwapper(char **a, char **b)
{
    char* c = *a;
    *a = *b;
    *b = c;
}
