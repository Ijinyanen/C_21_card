#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DECK_SIZE 21
#define SUB_DECK_SIZE 7
#define CHAR_LENGTH 4

char main_deck[DECK_SIZE][CHAR_LENGTH];
char sub_deck_one[SUB_DECK_SIZE][CHAR_LENGTH]; 
char sub_deck_two[SUB_DECK_SIZE][CHAR_LENGTH];
char sub_deck_three[SUB_DECK_SIZE][CHAR_LENGTH];

const char* select_card(char deck[DECK_SIZE][CHAR_LENGTH], int length);

void split_deck(char deck[DECK_SIZE][CHAR_LENGTH], char sub1[SUB_DECK_SIZE][CHAR_LENGTH],
char sub2[SUB_DECK_SIZE][CHAR_LENGTH], char sub3[SUB_DECK_SIZE][CHAR_LENGTH]);

void combine_decks(char deck, char sub1[], char sub2[],char sub3[]);
int show_decks(char sub1[SUB_DECK_SIZE][CHAR_LENGTH], char sub2[SUB_DECK_SIZE][CHAR_LENGTH], char sub3[SUB_DECK_SIZE][CHAR_LENGTH]);

int main(){


    char cards[21][4] = {"AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD","AH","2H","3H","4H","5H","6H","7H","8H"};
    for(int i = 0; i < DECK_SIZE;i++){
        printf("%s ", cards[i]);
    };

    printf("\n welcome to the 21 card trick. V2 \n");

    //Put cards into the main deck
    for(int i = 0; i < DECK_SIZE;i++){
        strcpy_s(main_deck[i],DECK_SIZE, cards[i]);
    }
    

    const char* selected_card = select_card(main_deck, DECK_SIZE);
    printf("You chose %s\n", selected_card);

    split_deck(main_deck,sub_deck_one,sub_deck_two,sub_deck_three);
    
    for(int i = 0; i < SUB_DECK_SIZE; i++){
        printf(sub_deck_one[i]);       
    }

    int containing_deck_num = 0;
    containing_deck_num = show_decks(sub_deck_one, sub_deck_two,sub_deck_three);

    return 0;
}

//below are the programme's functions.

//has the user select a card and returns it.
const char* select_card(char deck[DECK_SIZE][CHAR_LENGTH], int length){
    for(int i = 0; i < length; i++){
        printf("%s ", deck[i]);
    }
    printf("\n pick a card from the options above. \n");
    static char chosen_card [CHAR_LENGTH];
    scanf("%s", chosen_card);
    return chosen_card;

}

//splits the main deck into three sub decks.
void split_deck(char deck[DECK_SIZE][CHAR_LENGTH], char sub1[SUB_DECK_SIZE][CHAR_LENGTH], 
char sub2[SUB_DECK_SIZE][CHAR_LENGTH], char sub3[SUB_DECK_SIZE][CHAR_LENGTH]){
    int index = 0;
    for(int i = 0; i < SUB_DECK_SIZE; i++){
        strcpy_s(sub1[i],CHAR_LENGTH, deck[index++]);
        strcpy_s(sub2[i],CHAR_LENGTH, deck[index++]);
        strcpy_s(sub3[i],CHAR_LENGTH, deck[index++]);
    }
}

//shows the three decks
int show_decks(char sub1[SUB_DECK_SIZE][CHAR_LENGTH], char sub2[SUB_DECK_SIZE][CHAR_LENGTH], char sub3[SUB_DECK_SIZE][CHAR_LENGTH]){
    printf(" deck 1 contains: ");
    for(int i; i < SUB_DECK_SIZE; i++){
        printf(sub_deck_one[i]);
    }
    printf("\n");
        printf(" deck 2 contains: ");
    for(int i; i < SUB_DECK_SIZE; i++){
        printf(sub2[i]);
    }
    printf("\n");
        printf(" deck 3 contains: ");
    for(int i; i < SUB_DECK_SIZE; i++){
        printf(sub3[i]);
    }
    printf("\n");
    
    
    int answer = 0;
    while(answer <= 0 || answer >=4){
        printf("Is your chosen card in deck 1,2 or 3?\n");
        scanf("%d", answer);
        if(answer <= 0 || answer >=4){
           printf("That is an invaid answer. \n"); 
        }
    }
    return answer;
}
