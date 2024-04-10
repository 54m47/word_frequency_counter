#include <stdio.h>
#include <stdlib.h>
#include "../include/file_utils.h"
#include "../include/word_utils.h"

// Opens the input file and returns the file pointer
FILE* open_input_file(const char* input_file)
{
    FILE* file = fopen(input_file, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        exit(1);
    }
    return file;
}

// Writes the word frequency array to the output file
void write_output_file(const char* output_file, const word_freq* word_freq_array, int size)
{
    FILE* file = fopen(output_file, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        exit(1);
    }

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d %s\n", word_freq_array[i].freq, word_freq_array[i].word);
    }

    fclose(file);
}