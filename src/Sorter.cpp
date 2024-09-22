#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "Sorter.h"
#include <StructuresForOnegin.h>

int StrCmp(char* str1, char* str2);
void AddrSwapper(void **a, void **b);
int CmpAndCleanBuff(const char refer);
int ReverseStrCmp(struct Lines str1, struct Lines str2);

// func pointer

void Sorter(struct Book* Onegin)
{
    printf("COUNT_LINES %d\n", Onegin->count_lines);
$$$ assert(Onegin);

    printf("Enter r to reverse sort or another button to common sort \n");
    if(CmpAndCleanBuff('r'))
        for(size_t i = 0; i < Onegin->count_lines; i++)
        {
            for(size_t j = 0; j < Onegin->count_lines - 1 - i; j++)
            {
                if(ReverseStrCmp(Onegin->str[j], Onegin->str[j+1]) > 0)
                {
                    AddrSwapper((void**)&(Onegin->str[j].adr), (void**)&(Onegin->str[j+1].adr));
                }
            }
        }
    else
        for(size_t i = 0; i < Onegin->count_lines; i++)
        {
            for(size_t j = 0; j < Onegin->count_lines - 1 - i; j++)
            {
                if(StrCmp(Onegin->str[j].adr, Onegin->str[j+1].adr) > 0)
                {
                    AddrSwapper((void**)&(Onegin->str[j].adr), (void**)&(Onegin->str[j+1].adr));
                }
            }
        }
}

int StrCmp(char* str1, char* str2)
{
    int i = 0, j = 0;
    printf("COMPARE_ENTER %s %s\n", str1,str2);
//$$$     printf("%d \n", __LINE__); //!!txlib!! $$ $meow(hello)

        while (isalpha(str1[i]) == 0 && str1[i] != '\0')     i++;
        while (isalpha(str2[j]) == 0 && str2[j] != '\0')     j++;

        while (str1[i] == str2[j] && str1[i] != '\0' && str2[j] != '\0')
        {
            i++;
            j++;
        }
        printf("COMAPRE %s %s res=%d\n", str1, str2, str1[i] - str2[j]);
        return (str1[i] - str2[j]);

    return 0;
}

int ReverseStrCmp(struct Lines str1, struct Lines str2)
{
//$$$ printf("i = %d \n",str1.len);
    int i = str1.len;
    int j = str2.len;

    while (isalpha(str1.adr[i]) == 0 && i >= 0)     i--;
    while (isalpha(str2.adr[j]) == 0 && j >= 0)     j--;

    while (str1.adr[i] == str2.adr[j] && i >= 0 && j >= 0)
    {
        i--;
        j--;
    }


    printf(" _%d_  _%d_\n", str1.adr[i], str2.adr[j]);
    printf("\n %s ___ %s \n", str1.adr, str2.adr);
    printf("%d\n", str1.adr[i] - str2.adr[j]);

    return (str1.adr[i] - str2.adr[j]);

    return 0;
}

void AddrSwapper(void **a, void **b)
{
    void* c = *a;
    *a = *b;
    *b = c;
}

int CmpAndCleanBuff(const char refer)
{
    int choise = ((getchar()) == refer);
    int reset = '\0';

    while ((reset = getchar()) != EOF && reset != '\n') {}

    return choise;
}
