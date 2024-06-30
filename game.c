#include <stdio.h>
#include <stdlib.h>

char alphabetChar[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *startGame(int *charFound) {
    system("clear");
    char *word=malloc(sizeof(char)*100);
    printf("Inserisci la parola da far indovinare: ");
    scanf("%[^\n]",word);
    while(getchar()!='\n');
    for(int i=0;word[i];i++) {
        if(word[i]==' ') charFound[i]=1;
    }
    return word;
}


void printLevel(int tentativi) {
    switch(tentativi) {
        case 0:
            printf("____\n|/   |\n|\n|\n|\n|\n|_____");
            break;
        case 1:
            printf(" ____\n|/   |\n|   (_)\n|\n|\n|\n|\n|_____");
            break;
        case 2:
            printf(" ____\n|/   |\n|   (_)\n|    |\n|    |\n|\n|\n|_____");
            break;
        case 3:
            printf(" ____\n|/   |\n|   (_)\n|   \\|\n|    |\n|\n|\n|_____");
            break;
        case 4:
            printf(" ____\n|/   |\n|   (_)\n|   \\|/\n|    |\n|\n|\n|_____");
            break;
        case 5:
            printf(" ____\n|/   |\n|   (_)\n|   \\|/\n|    |\n|   /\n|\n|_____");
            break;
        case 6:
            printf(" ____\n|/   |\n|   (_)\n|   \\|/\n|    |\n|   / \\\n|\n|_____\n\nULTIMO TENTATIVO");
            break;
    }
    printf("\n\n\n\n");
}

void printWord(char *word, int *alphabet, int *charFound, int tentativi) {
    system("clear");
    printLevel(tentativi);
    for(int i=0;word[i];i++) {
        if(word[i]==' ') printf(" ");
        else if(charFound[i]) printf("%c ",word[i]);
        else printf("_ ");
    }
    printf("\n\n");
    for(int i=0;i<26;i++) {
        if((i%9)==0) printf("\n");
        if(alphabet[i]==0) printf("%c\t",alphabetChar[i]);
    }
}

int testChar(char *word, int *alphabet, int *charFound, int tentativi) {
    printf("\n\nInserisci la lettera da testare: ");
    char test='1';
    while((test<'a' || test>'z') && (test<'A' || test>'Z')) {
        test=getchar();
        while(getchar()!='\n');
    }
    if((test>='A' && test<='Z' && alphabet[test-'A']) || (test>='a' && test<='z' && alphabet[test-'a'])) {
        system("clear");
        printf("Lettera gia' testata\nPremi invio per continuare\n");
        while(getchar()!='\n');
        printWord(word,alphabet,charFound,tentativi);
        return testChar(word,alphabet,charFound,tentativi);
    }
    int i=0, control=0;
    if(test>='A' && test<='Z') {
        alphabet[test-'A']=1;
    }
    else {
        alphabet[test-'a']=1;
    }
    while(*word) {
        if(test==(*word) || ((test+'A'-'a')==(*word)) || ((test+'a'-'A')==(*word))) {
            control=1;
            charFound[i]=1;
        }
        word++;
        i++;
    }
    system("clear");
    if(control) {
        printf("Lettera trovata\nPremi invio per continuare: ");
        while(getchar()!='\n');
        return 0;
    }
    else {
        printf("Lettera non trovata\nPremi invio per continuare: ");
        while(getchar()!='\n');
        return 1;
    }
}

int controlWin(int *charFound, int maxControl) {
    int control=1;
    for(int i=0;i<maxControl;i++) {
        if(!charFound[i]) control=0;
    }
    return control;
}