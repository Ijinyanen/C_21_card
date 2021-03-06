//A version that just uses share/global variables. Becomes much less complex. Less Pythony?
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

const char* select_card();

void split_deck();

void combine_decks(char deck[DECK_SIZE][CHAR_LENGTH], char sub1[SUB_DECK_SIZE][CHAR_LENGTH], char sub2[SUB_DECK_SIZE][CHAR_LENGTH],char sub3[SUB_DECK_SIZE][CHAR_LENGTH]);
int show_decks();
int card_check(char chosen_num[CHAR_LENGTH]);




int main(){


    char cards[21][4] = {"AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD","AH","2H","3H","4H","5H","6H","7H","8H"};

    printf("\n Welcome to the 21 card trick. V2 \n\n");

    //Put cards into the main deck
    for(int i = 0; i < DECK_SIZE;i++){
        strcpy_s(main_deck[i],DECK_SIZE, cards[i]);
    }
    

    const char* selected_card = select_card();
    printf("You chose %s\n", selected_card);

    int cycle = 0;
    while (cycle < 3){
        split_deck();

        int containing_deck_num = 0;
        containing_deck_num = show_decks();
        if(containing_deck_num == 1){
            combine_decks(main_deck,sub_deck_two,sub_deck_one,sub_deck_three);
        }
        else if(containing_deck_num == 2){
        combine_decks(main_deck,sub_deck_one,sub_deck_two,sub_deck_three);
        }
        else if(containing_deck_num == 3){
            combine_decks(main_deck,sub_deck_one,sub_deck_three,sub_deck_two);
        }
        else{
            printf("\nSomething went wrong.\n");
        }
        cycle++;
    }
    printf("\nYour card is %s\n", main_deck[10]);
    system("pause");
    return 0;
}

//below are the programme's functions.

//has the user select a card and returns it.
const char* select_card(){
    int card_ok = 0;
    static char chosen_card [CHAR_LENGTH];
    
    while(card_ok < 1){

        for(int i = 0; i < DECK_SIZE; i++){
            printf("%s ", main_deck[i]);
        }
        printf("\n Pick a card from the options above. \n");
        scanf("%s", chosen_card);
        card_ok = card_check(chosen_card);

    }
    return chosen_card;
}

//splits the main deck into three sub decks.
void split_deck(){
    int index = 0;
    for(int i = 0; i < SUB_DECK_SIZE; i++){
        strcpy_s(sub_deck_one[i],CHAR_LENGTH, main_deck[index++]);
        strcpy_s(sub_deck_two[i],CHAR_LENGTH, main_deck[index++]);
        strcpy_s(sub_deck_three[i],CHAR_LENGTH, main_deck[index++]);
    }
}

//shows the three decks
int show_decks(){
        
    printf(" deck 1 contains: ");
    for(int j = 0; j < SUB_DECK_SIZE; j++){
        printf("%s ", sub_deck_one[j]);
    }

    printf("\n");
    printf(" deck 2 contains: ");
    for(int k = 0; k < SUB_DECK_SIZE; k++){
        printf("%s ",sub_deck_two[k]);
    }

    printf("\n");
        printf(" deck 3 contains: ");
    for(int l = 0; l < SUB_DECK_SIZE; l++){
        printf("%s ", sub_deck_three[l]); 
    }
    printf("\n\n");
    
    
    int answer = 0;
    while(answer <= 0 || answer >=4){
        printf("Is your chosen card in deck 1,2 or 3?\n");
        scanf("%d", &answer);
        if(answer <= 0 || answer >=4){
           printf("That is an invaid answer. \n"); 
        }
    }
    return answer;
}
// function to combine the three sub decks into one.
void combine_decks(char deck[DECK_SIZE][CHAR_LENGTH], char sub1[SUB_DECK_SIZE][CHAR_LENGTH],
 char sub2[SUB_DECK_SIZE][CHAR_LENGTH],char sub3[SUB_DECK_SIZE][CHAR_LENGTH]){
     for(int i= 0; i < SUB_DECK_SIZE; i++){
         strcpy_s(deck[i],SUB_DECK_SIZE, sub1[i]); 
     }
     for(int j = 0; j < SUB_DECK_SIZE; j++){
         strcpy_s(deck[j+7], SUB_DECK_SIZE, sub2[j]);
     }
     for(int k = 0; k < SUB_DECK_SIZE; k++){
         strcpy_s(deck[k+14], SUB_DECK_SIZE, sub3[k]);
     }
     printf("\n");
 }

// checks if card selection is valid
 int card_check(char chosen_num[CHAR_LENGTH]){
    for(int i = 0; i < DECK_SIZE; i++){
        if(main_deck[i][0] == chosen_num[0] && main_deck[i][1] == chosen_num[1]){
            return 1;
        }

    }
    return 0;

 }