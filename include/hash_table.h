#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "word_utils.h"

void insert_word(const char* word, int len);
int get_word_freq_array(word_freq** word_freq_array);
void free_word_freq_array(word_freq* word_freq_array, int size);

#endif