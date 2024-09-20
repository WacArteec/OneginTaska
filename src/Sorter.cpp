#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "Sorter.h"
#include <StructuresForOnegin.h>

int StrCmp(char* str1, char* str2);
void AddrSwapper(char** a, char** b);

void Sorter(struct Book* Onegin)
{
$$$ assert(Onegin);

    for(int i = 0; i < Onegin->count_lines; i++)
    {
        for(int j = 0; j < Onegin->count_lines - 1 - i; j++)
        {
            if(StrCmp(Onegin->adreses[j], Onegin->adreses[j+1]))
            {
//$$$              printf("%d\n", StrCmp(Onegin->adreses[j], Onegin->adreses[j+1]));
//$$$              printf("%d \n", __LINE__);
//$$$             printf(" %s = ", Onegin->adreses[j]);
                AddrSwapper(&(Onegin->adreses[j]), &(Onegin->adreses[j+1]));
//$$$             printf(" %s \n", Onegin->adreses[j]);
            }
        }
        //printf("\n %d \n", i);
    }
}

// isalpha

int StrCmp(char *str1, char *str2)
{
    int i = 0, j = 0;
    while(1)
    {
//$$$     printf("%d \n", __LINE__); //!!txlib!! $$ $meow(hello)
/*        while(isalpha(str1[i]) == 0 && str1[i] != '\0')
        {
            i+=1;
$$$         printf("HUY %d \n", i);
        }
        while(isalpha(str2[j]) == 0 && str2[j] != '\0')
        {
            j+=1;
//$$$         printf("%d \n", __LINE__);
        }*/
        if(str2[j] == '\0')     return 1;
        if(str1[i] == '\0')     return 0;
        if(tolower(str1[i]) > tolower(str2[j]))   return 1;
        if(tolower(str1[i]) < tolower(str2[j]))   return 0;
        i++;
        j++;
    }
    return 0;
}

void AddrSwapper(char **a, char **b)
{
    char* c = *a;
    *a = *b;
    *b = c;
}
