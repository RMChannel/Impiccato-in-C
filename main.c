#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void intialize(int *a, int n, int value) {
    for(int i=0;i<n;i++) a[i]=value;
}

int myStrLen(char *word) {
    int n=0;
    for(;*word;word++,n++);
    return n;
}

void playGame() {
    int charFound[100];
    int alphabet[26];
    intialize(charFound,100,0);
    intialize(alphabet,26,0);
    char *word=startGame(charFound);
    int game=1, tentativi=0, maxControl=myStrLen(word);
    while(game) {
        printWord(word,alphabet,charFound,tentativi);
        if (testChar(word,alphabet,charFound,tentativi)) tentativi++;
        if(tentativi>6) {
            game=0;
            system("clear");
            printf(" ____\n|/   |\n|   (_)\n|   /|\\\n|    |\n|   | |\n|\n|_____\n\nMi dispiace, hai perso\nLa parola da trovare era: %s\n",word);
        }
        if(controlWin(charFound,maxControl)) {
            game=0;
            system("clear");
            printf(" ____\n|/   |\n|         GRAZIEEE!!!\n|  \\(_)/\n|    |\n|    |\n|___|_|\n\n\nCongratulazioni!!! Hai vinto!!!\n");
        }
    }
    printf("G A M E     O V E R\n");
    free(word);
}

int main() {
    char control='y';
    while(control=='y' || control=='Y') {
        playGame();
        printf("\nVuoi rigiocare?\n[Y/y] Si\n[Altro] No\n");
        control=getchar();
        while(getchar()!='\n');
    }
    return 0;
}