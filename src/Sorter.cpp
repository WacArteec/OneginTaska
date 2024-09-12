#include "Sorter.h"
#include <StructuresForOnegin.h>

void Sorter(struct Book *Onegin)
{
    for(int i = 0; i < Onegin->count_lines-1; i++)
    {
        for(int j = 0; j < Onegin->count_lines - 1 - i; j++)
        {
            if(StrCmp(Onegin, j)) AddrSwapper(Onegin, j);
        }
    }
}

int StrCmp(struct Book *Onegin, int j)
{
    while(1)
    {
//    printf("CMP %d \n", k);
            if((Onegin->text[j][k] - Onegin->text[j+1][k]) > 0 || Onegin->text[j][k] == 0)
                return 1;
            else if(Onegin->text[j+1][k] == 0)
                break;
    }
    return 0;
}

void AddrSwapper(struct Book *Onegin, int j)
{
    char* c = Onegin->text[j];
    Onegin->text[j] = Onegin->text[j+1];
    Onegin->text[j+1] = c;
}

