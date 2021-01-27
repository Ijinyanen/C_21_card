import random

#challenge 1
print("This is a 21 card trick.")
print("You will pick a card.")
print("By asking you three questions i will be able to guess your card.")

#challenge 2
name = input("What is your name?\n->")
print("\nWelcome to the quiz", name, "\n")

#challeng 3
cards = ["AD","2D","3D","4D","5D","6D","7D","8D", "9D","10D","JD","QD","KD","AH","2H","3H","4H","5H","6H","7H","8H"]

random.shuffle(cards)
print("Here are all the cards:")
print(cards)
print("Please select a card from those above and remember it.")
input("press enter to continue.")

#challeng 4
pile_1 = cards[0],cards[3],cards[6],cards[9],cards[12],cards[15],cards[18]
pile_2 = cards[1],cards[4],cards[7],cards[10],cards[13],cards[16],cards[19]
pile_3 = cards[2],cards[5],cards[8],cards[11],cards[14],cards[17],cards[20]

print(pile_1)
print(pile_2)
print(pile_3)

#challenge 5
target_pile = int(input("Which pile is your card in?"))

#challenge 6
if target_pile == 1:
    cards2 = pile_2 + pile_1 + pile_3

elif target_pile == 2:
    cards2 = pile_1 + pile_2 + pile_3

else: 
    cards2 = pile_1 + pile_3 + pile_2

#challenge 7
pile_1 = cards2[0],cards2[3],cards2[6],cards2[9],cards2[12],cards2[15],cards2[18]
pile_2 = cards2[1],cards2[4],cards2[7],cards2[10],cards2[13],cards2[16],cards2[19]
pile_3 = cards2[2],cards2[5],cards2[8],cards2[11],cards2[14],cards2[17],cards2[20]

print(pile_1)
print(pile_2)
print(pile_3)

target_pile = int(input("Which pile is your card in?"))

if target_pile == 1:
    cards3 = pile_2 + pile_1 + pile_3

elif target_pile == 2:
    cards3 = pile_1 + pile_2 + pile_3

else: 
    cards3 = pile_1 + pile_3 + pile_2

pile_1 = cards3[0],cards3[3],cards3[6],cards3[9],cards3[12],cards3[15],cards3[18]
pile_2 = cards3[1],cards3[4],cards3[7],cards3[10],cards3[13],cards3[16],cards3[19]
pile_3 = cards3[2],cards3[5],cards3[8],cards3[11],cards3[14],cards3[17],cards3[20]  

print(pile_1)
print(pile_2)
print(pile_3)

target_pile = int(input("Which pile is your card in?"))

if target_pile == 1:
    cards4 = pile_2 + pile_1 + pile_3

elif target_pile == 2:
    cards4 = pile_1 + pile_2 + pile_3

else: 
    cards4 = pile_1 + pile_3 + pile_2

#challenge 8
input("ready to be amazed?")
print("Your card is ", cards4[10], ".")