#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char ch) {
    return ch == ' ' || ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == '\n' || ch == '\t';
}

void addWord(Word words[], int *numWords, char *word) {
    toLowerCase(word);
    for (int i = 0; i < *numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*numWords].word, word);
    words[*numWords].count = 1;
    (*numWords)++;
}

void countWords(char *paragraph, Word words[], int *numWords) {
    char word[MAX_WORD_LEN];
    int index = 0;

    for (int i = 0; paragraph[i] != '\0'; i++) {
        if (isDelimiter(paragraph[i])) {
            if (index > 0) {
                word[index] = '\0';
                addWord(words, numWords, word);
                index = 0;
            }
        } else {
            word[index++] = paragraph[i];
        }
    }

    if (index > 0) {
        word[index] = '\0';
        addWord(words, numWords, word);
    }
}

int main() {
    char paragraph[5000];
    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    countWords(paragraph, words, &numWords);

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
