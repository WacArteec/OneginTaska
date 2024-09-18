#include <stdio.h>
#include <assert.h>

#include "Output.h"
#include <StructuresForOnegin.h>

void Outputer(struct Book *Onegin)
{
    FILE* file_onegin_out_leftsort = fopen("OneginSortLeft.txt", "w");

$$$ assert(file_onegin_out_leftsort);

    if(file_onegin_out_leftsort)
        for(int i = 0; i < Onegin->count_lines; i++)
        {
            int outproof = fputs(Onegin->adreses[i], file_onegin_out_leftsort);
$$$         assert(outproof > 0);
        }

$$$ assert(!fclose(file_onegin_out_leftsort));
}
