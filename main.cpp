#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <Inputer.h>
#include <StructuresForOnegin.h>
#include <Sorter.h>
#include <Output.h>

void TextPrint(struct Book *Onegin);


int main()
{

    struct Book Onegin = {};

    StrInput(&Onegin);

    Sorter(&Onegin);

    printf("%d", Onegin.count_lines);

    Outputer(&Onegin);

    free(Onegin.text);

    return 0;
}


void TextPrint(struct Book *Onegin)
{
    for(int i = 0; i < Onegin->count_lines; i++)
    {
        printf("%s \n", Onegin->adreses[i]);
    }
}
