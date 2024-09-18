//#include<io.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#include "Inputer.h"
#include "StructuresForOnegin.h"


int FileInfo(FILE *file_onegin);
int ReplaceSymbol(char* text, int count_elements, char in, char out, struct Book *Onegin);

void StrInput(struct Book *Onegin)
{

    FILE *file_onegin = fopen("EnglishOnegin.txt", "rb");
$$$ assert(file_onegin);

    int file_size = FileInfo(file_onegin);

    Onegin->text = (char*)calloc(file_size + 1, sizeof(char)); //вместо sizeof(char) можно 1
$$$ assert(Onegin->text);

    size_t count_elements = fread(Onegin->text, sizeof(char), file_size, file_onegin);

    Onegin->adreses[0] = &(Onegin->text[0]);
    Onegin->count_lines = 1;

$$$ printf("Before array with adreses");

    Onegin->count_lines = ReplaceSymbol(Onegin->text, count_elements, '\n', '\0', Onegin);
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

    int errclose = !fclose(file_onegin);
$$$ assert(errclose); //!NDEBUG! !change to if!

}

int FileInfo(FILE *file_onegin)
{
    int fseek_proof = fseek(file_onegin, 0, SEEK_END);
$$$ assert(fseek_proof + 1);
    int file_size = ftell(file_onegin);
$$$ if(file_size == -1L) printf("!File Size is 0! : %s", strerror(errno));
    rewind(file_onegin);
    return file_size;
}

int ReplaceSymbol(char* text, int count_elements, char in, char out, struct Book *Onegin)
{
    int c_lines = 1;
    for(int i = 0; i < count_elements; i++)
    {
        if(text[i] == in)
        {
            text[i] = out;
            Onegin->adreses[c_lines] = &(Onegin->text[i+1]);
            c_lines += 1;
        } //!replace doooo.h!
    }
    return c_lines;
}
