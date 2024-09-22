#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <Inputer.h>
#include <StructuresForOnegin.h>
#include <Sorter.h>
#include <Output.h>

int main()
{

    struct Book Onegin = {};

    Input(&Onegin);

    Sorter(&Onegin);

    printf("%d", Onegin.count_lines);

    Outputer(&Onegin);

    free(Onegin.text);
    free (Onegin.str);

    return 0;
}
