#include <stdio.h>
#include <assert.h>

#include "Output.h"
#include <StructuresForOnegin.h>

void Outputer(struct Book *Onegin)
{
$$$ assert(Onegin);

    FILE* file_onegin_out_leftsort = fopen("OneginSorted.txt", "w");
$$$ assert(file_onegin_out_leftsort);

        for(int i = 0; i < Onegin->count_lines; i++)
        {
            fprintf(file_onegin_out_leftsort, "%s", Onegin->adreses[i]);

/*            int outproof = fputs(Onegin->adreses[i], file_onegin_out_leftsort);
$$$         assert(outproof >= 0);*/
        }

    int fclose_check = fclose(file_onegin_out_leftsort);
$$$ assert(fclose_check + 1);
}
