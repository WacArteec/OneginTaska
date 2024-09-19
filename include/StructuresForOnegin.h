#ifndef STRUCTURESFORONEGIN_H_INCLUDED
#define STRUCTURESFORONEGIN_H_INCLUDED

#define $$$

struct Book
{
    char* text;
    int count_lines;
    int count_elements;
    char** adreses;
    FILE* file;
    size_t file_size;
    const char file_name[18];
};

#endif // STRUCTURESFORONEGIN_H_INCLUDED
