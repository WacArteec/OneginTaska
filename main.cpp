#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <Inputer.h>
#include <StructuresForOnegin.h>
#include <Sorter.h>
#include <Output.h>


int main()
{

    struct Book Onegin = {0, 0, 0, 0, 0, 0, "EnglishOnegin.txt"};

    Input(&Onegin);

    Sorter(&Onegin);

    printf("%d", Onegin.count_lines);

    Outputer(&Onegin);

    free(Onegin.text);
    for(int i = 0; i < Onegin.count_lines; i++) free(Onegin.adreses[i]);
    free (Onegin.adreses);

    return 0;
}
