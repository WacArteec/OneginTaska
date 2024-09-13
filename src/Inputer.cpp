#include<stdio.h>
#include <assert.h>

#include "Inputer.h"

#include "StructuresForOnegin.h"

void StrInput(struct Book *Onegin)
{

    FILE *file_onegin = fopen("EnglishOnegin.txt", "r");
assert(file_onegin);

    fseek(file_onegin, 0, SEEK_END);
    long int file_size = ftell(file_onegin);
if(file_size == -1L) printf("!File Size is 0!");
    rewind(file_onegin);

    Onegin->text = (char*)calloc(file_size + 1, sizeof(char)); //вместо sizeof(char) можно 1
assert(Onegin->text);

    size_t count_elements = fread(Onegin->text, sizeof(char), file_size, file_onegin);

    Onegin->text = (char*)realloc(Onegin->text, count_elements + 1);

    long long int count_lines = 1;
    Onegin->adreses[0] = &(Onegin->text[0]);

    printf("Before array with adreses");

    for(size_t i = 0; i < count_elements; i++)
    {
        if(Onegin->text[i] == '\n')
        {
            Onegin->text[i] = '\0';
            Onegin->adreses[count_lines] = &(Onegin->text[i+1]);
            count_lines += 1;
        }
    }
    printf("After array with adreses");
    Onegin->count_lines = count_lines;
//printf("%ld %zd", count_elements, file_size);

/*for(int i = 0; i < Onegin->count_lines; i++)
{
printf("%s \n \n", Onegin->adreses[i]);
}*/

    assert(!fclose(file_onegin));

}
