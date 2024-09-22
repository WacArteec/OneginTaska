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
long MyFstat(struct Book* Onegin);

void Input(struct Book* Onegin)
{
$$$ assert(Onegin);

    FileInput(Onegin);

    Onegin->count_lines = StrCounter(Onegin);

    Onegin->str = (Lines*) calloc(Onegin->count_lines, sizeof(Lines));
$$$ assert(Onegin->str);

    ReplaceSymbol(Onegin);

}

void FileInput(struct Book* Onegin)
{
$$$ assert(Onegin);

    Onegin->file = fopen(Onegin->file_input_name, "rb");
$$$ assert(Onegin->file);

// fstat

    Onegin->count_elements = MyFstat(Onegin);

    Onegin->text = (char*) calloc(Onegin->count_elements + 1, sizeof(char));
$$$ assert(Onegin->text);

    size_t fread_check = fread(Onegin->text, sizeof(char), Onegin->count_elements, Onegin->file);
$$$ assert(Onegin->count_elements == fread_check);

    int errclose = !fclose(Onegin->file);
$$$ assert(errclose); //!NDEBUG! !change to if!
}

int StrCounter(struct Book* Onegin)
{
$$$ assert(Onegin);

    int count_of_lines = 1;

    for(size_t i = 0; i < Onegin->count_elements; i++)
    {
        if(Onegin->text[i] == '\n')
        {
            count_of_lines += 1;
        }
    }
    return count_of_lines-1;
}

void ReplaceSymbol(struct Book* Onegin)
{
$$$ assert(Onegin);

    // Onegin->str[0].adr = Onegin->text;

    int j = 0;
    size_t lenght = 0;
    char* start = Onegin->text;
    for(size_t i = 0; i < Onegin->count_elements; i++)
    {
        if(Onegin->text[i] == '\r')
        {
            Onegin->text[i] = '\0';
            Onegin->text[i+1] = '\0';

            Onegin->str[j].adr = start;
            Onegin->str[j].len = lenght;

            //printf("WRITED_STR %s len=%d \n", Onegin->str[j].adr, Onegin->str[j].len);
            fprintf(stderr, "WRITED_STR %s len=%d \n", Onegin->str[j].adr, Onegin->str[j].len);
            start = Onegin->text + i + 2;
            lenght = 0;
            i++;
            j++;
        } //!replace doooo.h!
        else lenght++;
    }
    printf("%c\n", Onegin->str[0].adr[0]);

    Onegin->text[Onegin->count_elements] = '\0';
//    Onegin->text[Onegin->count_elements + 1] = '\0';
}

long MyFstat(struct Book* Onegin)
{
$$$ assert(Onegin);

    int fseek_proof = fseek(Onegin->file, 0, SEEK_END);
$$$ assert(fseek_proof + 1);
    long count_symb_in_file = ftell(Onegin->file);

$$$ if(Onegin->count_elements == (size_t)(-1L))
        printf("!File Size is 0! : %s", strerror(errno));
    rewind(Onegin->file);
    return count_symb_in_file;
}
