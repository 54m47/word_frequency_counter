#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/word_utils.h"
#include "../include/file_utils.h"
#include "../include/hash_table.h"

// Counts the word frequencies from the input file
void count_word_frequencies(const char* input_file)
{
    FILE* file = open_input_file(input_file);

    char buffer[4096];
    int buffer_index = 0;
    int word_start_index = 0;

    int c;
    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
        {
            buffer[buffer_index++] = tolower(c);
        }
        else if (buffer_index > word_start_index)
        {
            process_word(buffer + word_start_index, buffer_index - word_start_index);
            word_start_index = buffer_index;
        }
        if (buffer_index == sizeof(buffer))
        {
            if (word_start_index > 0)
            {
                memmove(buffer, buffer + word_start_index, buffer_index - word_start_index);
                buffer_index -= word_start_index;
                word_start_index = 0;
            }
            else
            {
                process_word(buffer, buffer_index);
                buffer_index = 0;
            }
        }
    }

    if (buffer_index > word_start_index)
    {
        process_word(buffer + word_start_index, buffer_index - word_start_index);
    }

    fclose(file);
}

// Processes a word by inserting it into the hash table
void process_word(const char* word, int len)
{
    insert_word(word, len);
}