#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define hor 5
#define vert 8

struct Book
{
    int lines;
    char **text;
};

void Sorter(struct Book *Onegin);
void StrInput(struct Book *Onegin, FILE *file_onegin);
int StrCmp(struct Book *Onegin, int i, int j);
void AddrSwapper(char *a, char *b);
void TextPrint(struct Book Onegin);


int main()
{
    FILE *file_onegin;
    file_onegin = fopen("EnglishOnegin.txt", "r+");

    struct Book Onegin = {};

    Onegin.text = (char**)calloc(hor, sizeof(char*));
    if (!Onegin.text) return 1;

    StrInput(&Onegin, file_onegin);

    TextPrint(Onegin);

    Sorter(&Onegin);

    TextPrint(Onegin);

    fclose(file_onegin);

    free(Onegin.text);
    for(int i = 0; i < hor; i++)
    {
        free(Onegin.text[i]);
    }

    return 0;
}

void Sorter(struct Book *Onegin)
{
    for(int i = 0; i < hor-1; i++)
    {
        for(int j = 0; j < hor - 1 - i; j++)
        {
            if(StrCmp(Onegin, i, j)) AddrSwapper(Onegin->text[j], Onegin->text[j+1]);
        }
    }
}

int StrCmp(struct Book *Onegin, int i, int j)
{
    for(int k = 0; k < vert-1; k++)
    {
    printf("CMP %d \n", k);
            if((Onegin->text[i][k] - Onegin->text[j][k]) > 0 || Onegin->text[i][k] == 0) return 1;
            else if(Onegin->text[j][k] == 0) break;
    }
    return 0;
}

void AddrSwapper(char *a, char *b)
{
    size_t c = *a;
    *a = *b;
    *b = c;
}

void StrInput(struct Book *Onegin, FILE* file_onegin)
{
    for(int i = 0; i < hor; i++)
    {
        Onegin->text[i] = (char*)calloc(vert, sizeof(char));
        assert(Onegin->text[i]);
        fscanf(file_onegin, "%s", Onegin->text[i]);
    }
}

void TextPrint(struct Book Onegin)
{
    for(int i = 0; i < hor; i++)
    {
        printf("%s\n", Onegin.text[i]);

        //fprintf(fp, "%s", str);
    }
}
