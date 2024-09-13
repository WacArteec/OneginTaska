#include "Sorter.h"
#include <StructuresForOnegin.h>

int StrCmp(struct Book *Onegin, int j);
void AddrSwapper(struct Book *Onegin, int j);

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
    int i = 0;

    while(1)
    {
//    printf("CMP %d \n", k);
                 if((Onegin->adreses[j][i] - Onegin->adreses[j+1][i]) > 0 || Onegin->adreses[j][i] == 0)
                return 1;
            else if(Onegin->adreses[j+1][i] == 0)
                break;
    i++;
    }
    return 0;
}

void AddrSwapper(struct Book *Onegin, int j)
{
    char* c = (Onegin->adreses[j]);
    (Onegin->adreses[j]) = (Onegin->adreses[j+1]);
    (Onegin->adreses[j+1]) = c;
}

