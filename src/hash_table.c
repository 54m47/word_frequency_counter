#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../third-party/xxhash/xxhash.h"
#include "../include/hash_table.h"

#define HASH_SIZE 1000003

typedef struct hash_node
{
    word_freq data;
    struct hash_node* next;
} hash_node;

hash_node* hash_table[HASH_SIZE];

// Calculates the hash value of a word
unsigned int hash(const char* word, int len)
{
    return XXH32(word, len, 0) % HASH_SIZE;
}

// Inserts a word into the hash table
void insert_word(const char* word, int len)
{
    unsigned int index = hash(word, len);
    hash_node* node = hash_table[index];
    while (node != NULL)
    {
        if (strncmp(node->data.word, word, len) == 0 && node->data.word[len] == '\0')
        {
            node->data.freq++;
            return;
        }
        node = node->next;
    }
    hash_node* new_node = (hash_node*)malloc(sizeof(hash_node));
    new_node->data.word = (char*)malloc((len + 1) * sizeof(char));
    strncpy(new_node->data.word, word, len);
    new_node->data.word[len] = '\0';
    new_node->data.freq = 1;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

// Compares two word frequencies for sorting
int compare_word_freq(const void* a, const void* b)
{
    const word_freq* wf1 = (const word_freq*)a;
    const word_freq* wf2 = (const word_freq*)b;
    if (wf1->freq != wf2->freq)
        return wf2->freq - wf1->freq;
    return strcmp(wf1->word, wf2->word);
}

// Retrieves the word frequency array from the hash table
int get_word_freq_array(word_freq** word_freq_array)
{
    int unique_words = 0;
    *word_freq_array = (word_freq*)malloc(HASH_SIZE * sizeof(word_freq));
    for (int i = 0; i < HASH_SIZE; i++)
    {
        hash_node* node = hash_table[i];
        while (node != NULL)
        {
            (*word_freq_array)[unique_words++] = node->data;
            hash_node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    qsort(*word_freq_array, unique_words, sizeof(word_freq), compare_word_freq);
    return unique_words;
}

// Frees the memory allocated for the word frequency array
void free_word_freq_array(word_freq* word_freq_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(word_freq_array[i].word);
    }
    free(word_freq_array);
}