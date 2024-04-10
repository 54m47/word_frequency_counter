#ifndef WORD_UTILS_H
#define WORD_UTILS_H

typedef struct word_freq
{
    char* word;
    int freq;
} word_freq;

void count_word_frequencies(const char* input_file);
void process_word(const char* word, int len);

#endif