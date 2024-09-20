#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "Sorter.h"
#include <StructuresForOnegin.h>

int StrCmp(char* str1, char* str2);
void AddrSwapper(char** a, char** b);
int CmpAndCleanBuff(const char refer);
int ReverseStrCmp(char* str1, char* str2);

void Sorter(struct Book* Onegin)
{
$$$ assert(Onegin);

    printf("Enter r to reverse sort or another button to common sort \n");
    if(CmpAndCleanBuff('r'))
        for(int i = 0; i < Onegin->count_lines; i++)
        {
            for(int j = 0; j < Onegin->count_lines - 1 - i; j++)
            {
                if(ReverseStrCmp(Onegin->adreses[j], Onegin->adreses[j+1]))
                {
                    AddrSwapper(&(Onegin->adreses[j]), &(Onegin->adreses[j+1]));
                }
            }
        }

else
    for(int i = 0; i < Onegin->count_lines; i++)
    {
        for(int j = 0; j < Onegin->count_lines - 1 - i; j++)
        {
            if(StrCmp(Onegin->adreses[j], Onegin->adreses[j+1]))
            {
                AddrSwapper(&(Onegin->adreses[j]), &(Onegin->adreses[j+1]));
            }
        }
    }
}

int StrCmp(char *str1, char *str2)
{
    int i = 0, j = 0;

    while(1)
    {
//$$$     printf("%d \n", __LINE__); //!!txlib!! $$ $meow(hello)

        while(isalpha(str1[i]) == 0 && str1[i] != '\0')     i++;
        while(isalpha(str2[j]) == 0 && str2[j] != '\0')     j++;

        if(str2[j] == '\0')                       return 1;
        if(str1[i] == '\0')                       return 0;
        if(tolower(str1[i]) > tolower(str2[j]))   return 1;
        if(tolower(str1[i]) < tolower(str2[j]))   return 0;

        i++;
        j++;
    }

    return 0;
}

int ReverseStrCmp(char* str1, char* str2)
{
    int i = 0, j = 0;

    while(str1[i] != '\0') i++;
    while(str2[j] != '\0') j++;

    while(i >= 0 && j >= 0)
    {
        while(isalpha(str1[i]) == 0 && str1[i] != '\0')     i--;
        while(isalpha(str2[j]) == 0 && str2[j] != '\0')     j--;

        if(tolower(str1[i]) > tolower(str2[j]))   return 1;
        if(tolower(str1[i]) < tolower(str2[j]))   return 0;
        i--;
        j--;
    }

    return 0;
}

void AddrSwapper(char **a, char **b)
{
    char* c = *a;
    *a = *b;
    *b = c;
}

int CmpAndCleanBuff(const char refer)
{
    int choise = ((getchar()) == refer);
    int reset = '\0';

    while((reset = getchar()) != EOF && reset != '\n')
        ;

    return choise;
}
