//#include<io.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#include "Inputer.h"
#include "StructuresForOnegin.h"


void FileInput(struct Book* Onegin);
void ReplaceSymbol(struct Book* Onegin);
int StrCounter(struct Book* Onegin);

void Input(struct Book* Onegin)
{
$$$ assert(Onegin);

//$$$ printf("Before array with adreses");
    FileInput(Onegin);

    Onegin->count_lines = StrCounter(Onegin);

    Onegin->adreses = (char**) calloc(Onegin->count_lines, sizeof(char*));

    ReplaceSymbol(Onegin);

//$$$ printf("After array with adreses");
}

void FileInput(struct Book* Onegin)
{
    Onegin->file = fopen(Onegin->file_name, "rb");
$$$ assert(Onegin->file);

    int fseek_proof = fseek(Onegin->file, 0, SEEK_END);
$$$ assert(fseek_proof + 1);

    Onegin->file_size = ftell(Onegin->file);
$$$ if(Onegin->file_size == -1L) printf("!File Size is 0! : %s", strerror(errno));
    rewind(Onegin->file);

    Onegin->text = (char*) calloc(Onegin->file_size + 1, sizeof(char));
$$$ assert(Onegin->text);

    Onegin->count_elements = fread(Onegin->text, sizeof(char), Onegin->file_size, Onegin->file);
$$$ assert(Onegin->count_elements == Onegin->file_size);

    int errclose = !fclose(Onegin->file);
$$$ assert(errclose); //!NDEBUG! !change to if!
}

int StrCounter(struct Book* Onegin)
{
    int count_of_lines = 1;
    for(int i = 0; i < Onegin->count_elements; i++)
    {
        if(Onegin->text[i] == '\n')
        {
            count_of_lines += 1;
        }
    }
    return count_of_lines;
}

void ReplaceSymbol(struct Book* Onegin)
{
    Onegin->adreses[0] = &(Onegin->text[0]);

    int j = 1;
    for(int i = 0; i < Onegin->count_elements; i++)
    {
        if(Onegin->text[i] == '\r')
        {
            Onegin->text[i] = '\n';
            Onegin->text[i+1] = '\0';
            Onegin->adreses[j] = &(Onegin->text[i+2]);
            j += 1;
        } //!replace doooo.h!
    }

    Onegin->text[Onegin->count_elements] = '\n';
    Onegin->text[Onegin->count_elements+1] = '\0';
}
