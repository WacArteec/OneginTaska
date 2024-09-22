#include <stdio.h>
#include <assert.h>

#include "Output.h"
#include <StructuresForOnegin.h>

void Outputer(struct Book *Onegin)
{
$$$ assert(Onegin);

    FILE* file_onegin_out_leftsort = fopen(Onegin->file_output_name, "w");
$$$ assert(file_onegin_out_leftsort);

        for(int i = 0; i < Onegin->count_lines; i++)
        {
            fprintf(file_onegin_out_leftsort, "1%s\n", Onegin->str[i].adr);
        }

    int fclose_check = !fclose(file_onegin_out_leftsort);
$$$ assert(fclose_check);
}
