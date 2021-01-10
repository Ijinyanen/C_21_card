# Aversion that makes greater use of global variables. More classical C in nature?


# the 21 cards we will use
CARDS = ["AD","2D","3D","4D","5D","6D","7D","8D", "9D","10D","JD","QD","KD","AH","2H","3H","4H","5H","6H","7H","8H"]
#list of global variables
selection = ""
main_deck = []
sub_deck_one = []
sub_deck_two = []
sub_deck_three = []
location = ""

def main():
    global sub_deck_one
    global sub_deck_two
    global sub_deck_three
    global main_deck

    
    selection = select_card()
    #allocates cards to the main deck.
    main_deck = CARDS

    #main loop of the trick
    counter = 0
    while(counter < 3):
        split_deck()
        location = show_decks(sub_deck_one,sub_deck_two,sub_deck_three)
        if location == "1":
            combine_decks(sub_deck_two,sub_deck_one,sub_deck_three)
        elif location == "2":
            combine_decks(sub_deck_one,sub_deck_two,sub_deck_three)
        else:
            combine_decks(sub_deck_one, sub_deck_three, sub_deck_two)
        counter = counter + 1

    
    
    print(f"Your card is {main_deck[10]}")


#gets user to select a card. This doesn't actually do anything.
def select_card(): 
    select = ""
    while(select not in CARDS):
        print(CARDS)
        select = input("Please choose a card. ")
        if(select not in CARDS):
            print("selection invalid. Please try again.")
    return select

#splits the main deck into three sub decks
def split_deck():
    global sub_deck_one
    global sub_deck_two
    global sub_deck_three
    global main_deck
    count = 0

    while (count<7):
        sub_deck_one.append(main_deck.pop())
        sub_deck_two.append(main_deck.pop())
        sub_deck_three.append(main_deck.pop())
        count = count + 1
    return 0


#combines the sub decks into one. Ensures sub deck with card goes to the middle.
def combine_decks(deck_one, deck_two, deck_three):
    global main_deck
    global sub_deck_one
    global sub_deck_two
    global sub_deck_three

    main_deck = deck_one + deck_two + deck_three
    sub_deck_one = []
    sub_deck_two = []
    sub_deck_three = []
    return 0

#displays the three sub decks
def show_decks(deck_one, deck_two,deck_three):
    valid_answers = ["1","2","3"]
    print(f"deck one:  {deck_one}")
    print(f"deck_two: {deck_two}")
    print(f"deck three: {deck_three}")

    answer = input("is your card in deck 1,2,3? ")
    while(answer not in valid_answers):
        print("Incorrect selection. Please try again.")
        answer = input("is your card in deck 1,2,3? ")
    return answer


main()