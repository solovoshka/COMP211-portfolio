/* Jacqueline Soloveychik: Homework 10 - Dictionaries
 *
 * wordcount 
 * program description: The program reads text from a file specified by the user, tokenizes the text into words, and 
 * then counts the number of times each word appears; it utilizes a dictionary to store the word counts - where each word is associated 
 * with its frequency in the input text.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

/* The maximum length of any filename.
 */
#define FNAME_MAX_LEN 128

/* Characters used to delimit words.
 */
#define DELIMS " \n\t,./;'[]\\-=<>?:\"{}|!@#$%^&*()_+0123456789"

int main(void) {
    /* The file from which to count words (prompted).
     */
    char fname[FNAME_MAX_LEN];

    /* File pointer to fname.
     */
    FILE* fp;

    /* Represents one line of the file.
     */
    char* lineptr = NULL;

    /* Represents the length of the line.
     */
    size_t len = 0;

    /* Open the file, read lines, count words.
     */
    printf("Enter filename: ");
    scanf(" %s", fname);
    fp = fopen(fname, "r");
    assert(fp != NULL);

    /* Create a dictionary to store word counts.
     */
    struct dict* word_counts = dict_create();

    /* Repeatedly set lineptr to a dynamically-allocated array containing the
     * next line to be read.  getline() returns -1 when there are no more
     * lines to read.
     */
    while (getline(&lineptr, &len, fp) != -1) {

        /* Initialize the tokenizer, which splits the line into words.
         */
        char* word = strtok(lineptr, DELIMS);
        /* Edge case:  there are no words in the line.
         */
        if (word == NULL) continue;

        /* Add or update the word count in the dictionary.
         */
        if (dict_contains(word_counts, word)) {
            dict_add(word_counts, word, dict_get(word_counts, word) + 1);
        } else {
            dict_add(word_counts, word, 1);
        }

        while ((word = strtok(NULL, DELIMS)) != NULL) {
            /* Add or update the word count in the dictionary.
             */
            if (dict_contains(word_counts, word)) {
                dict_add(word_counts, word, dict_get(word_counts, word) + 1);
            } else {
                dict_add(word_counts, word, 1);
            }
        }
    }

    /* Print out the word counts.
     */
    unsigned int num_words = dict_size(word_counts);
    char* keys[num_words];
    dict_keys_to_array(word_counts, keys);
    for (unsigned int i = 0; i < num_words; i++) {
        printf("%s: %d\n", keys[i], dict_get(word_counts, keys[i]));
        free(keys[i]);
    }

    /* Free all resources.
     */
    free(lineptr);
    dict_free(word_counts);
    fclose(fp);

    return 0;
}
