#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include "word_utils.h"

FILE* open_input_file(const char* input_file);
void write_output_file(const char* output_file, const word_freq* word_freq_array, int size);

#endif