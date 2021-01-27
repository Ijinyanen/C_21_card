import random

# a list of animals

animals = ["dog", "cat", "brid","ant", "pig", "cow"]

#print animal at position 0
print(animals[0])

#print animal at position 2
print(animals[2])

#print animal at position 5
print(animals[5])

#assign an animal from the list to a variable

mypet = animals[1]


#print my pet

print("My pet is a ", mypet)

#shuffle the animals
random.shuffle(animals)

#print animals in position 0
print(animals[0])


