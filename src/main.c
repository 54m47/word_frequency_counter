#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/word_utils.h"
#include "../include/hash_table.h"
#include "../include/file_utils.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./freq [input_file] [output_file]\n");
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];

    // Start the timer
    clock_t start = clock();

    count_word_frequencies(input_file);

    word_freq* word_freq_array = NULL;
    int size = get_word_freq_array(&word_freq_array);

    write_output_file(output_file, word_freq_array, size);

    free_word_freq_array(word_freq_array, size);

    // Stop the timer and calculate the elapsed time
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}