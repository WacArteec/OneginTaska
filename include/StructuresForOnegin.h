#ifndef STRUCTURESFORONEGIN_H_INCLUDED
#define STRUCTURESFORONEGIN_H_INCLUDED

#define $$$

struct Lines
{
    char* adr = NULL;
    int len = 0;
};

struct Book
{
    struct Lines* str = NULL;
    char* text = NULL;
    size_t count_lines = NULL;
    size_t count_elements = NULL;

    FILE* file = NULL;

    const char* file_input_name  = "EnglishOnegin.txt";
    const char* file_output_name = "OneginSorted.txt";
};

#endif // STRUCTURESFORONEGIN_H_INCLUDED
