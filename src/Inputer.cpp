//#include<io.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#include "Inputer.h"
#include "StructuresForOnegin.h"

#define $$$

int FileInfo(FILE *file_onegin);

void StrInput(struct Book *Onegin)
{

    FILE *file_onegin = fopen("EnglishOnegin.txt", "rb");
$$$ assert(file_onegin);

 int file_size = FileInfo(file_onegin);

    Onegin->text = (char*)calloc(file_size + 1, sizeof(char)); //вместо sizeof(char) можно 1
$$$ assert(Onegin->text);

    size_t count_elements = fread(Onegin->text, sizeof(char), file_size, file_onegin);

    //char*  = (char*)realloc(Onegin->text, count_elements + 1);
    //Onegin->text = ;


    //long long int count_lines = 1;
    Onegin->adreses[0] = &(Onegin->text[0]);
    Onegin->count_lines = 1;

$$$ printf("Before array with adreses");

    for(size_t i = 0; i < count_elements; i++)
    {
        if(Onegin->text[i] == '\n')
        {
            Onegin->text[i] = '\0';
            Onegin->adreses[Onegin->count_lines] = &(Onegin->text[i+1]);
            Onegin->count_lines += 1;
        } //!replace doooo.h!
    }
$$$ printf("After array with adreses");
    //Onegin->count_lines = count_lines;
//printf("%ld %zd", count_elements, file_size);

/*for(int i = 0; i < Onegin->count_lines; i++)
{
printf("%s \n \n", Onegin->adreses[i]);
}*/

    int errclose = !fclose(file_onegin);
$$$ assert(errclose); //!NDEBUG! !change to if!

}

int FileInfo(FILE *file_onegin)
{
    fseek(file_onegin, 0, SEEK_END);
    int file_size = ftell(file_onegin);
$$$ if(file_size == -1L) printf("!File Size is 0! : %s", strerror(errno));
    rewind(file_onegin);
    return file_size;
}
