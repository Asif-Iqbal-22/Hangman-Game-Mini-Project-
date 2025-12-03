#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *words[] = {"computer", "programming", "hangman", "keyboard", "mouse"};
    char word[50], guessed[50];
    int length, wrong = 0, max_wrong = 6;
    char guess;

    srand(time(0));
    strcpy(word, words[rand() % 5]);
    length = strlen(word);
    for(int i=0;i<length;i++) guessed[i] = '_';
    guessed[length] = '\0';

    printf("=== Hangman Game ===\n");

    while(wrong < max_wrong) {
        printf("\nWord: %s\n", guessed);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        int correct = 0;
        for(int i=0;i<length;i++) {
            if(word[i]==guess && guessed[i]=='_') {
                guessed[i] = guess;
                correct = 1;
            }
        }

        if(!correct) {
            wrong++;
            printf("Wrong guess! Attempts left: %d\n", max_wrong - wrong);
        }

        if(strcmp(word, guessed)==0) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            break;
        }
    }

    if(wrong == max_wrong) {
        printf("\nGame Over! The word was: %s\n", word);
    }

    return 0;
}
