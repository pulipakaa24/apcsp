# first let's import random procedures since we will be shuffling
import os
import random

os.system('cls')
deck = []
player1 = []
player2 = []
royals = ["J", "Q", "K", "A"]


# next, let's start building list holders, so we can place our cards in there:
def create_DECK():
    global deck
    numberCards = []
    suits = ["♥️", "♦️", "♣️", "♠️"]
    global royals

    # now, let's start using loops to add our content:
    for i in range(2, 11):
        numberCards.append(str(i))
        # this adds numbers 2-10 and converts them to string data

    for j in range(4):
        numberCards.append(royals[j])
        # this will add the royal faces to the card base

    for k in range(4):
        for m in range(13):
            card = (numberCards[m] + " " + suits[k])
            # this makes each card, cycling through suits, but first through faces
            deck.append(card)
            # this adds the information to the "full deck" we want to make

    # now let's see the cards!
    counter = 0
    for row in range(4):
        for col in range(13):
            print(deck[counter], end=" ")
            counter += 1
        print()
    # now let's shuffle our deck!


create_DECK()


def playerCards():
    random.shuffle(deck)
    global player1, player2
    for i in range(52):
        if i % 2 == 0:
            player1.append(deck[i])
        else:
            player2.append(deck[i])
    print("player1 ", player1)
    print("player2 ", player2)
    print()
    # I also want to see what the deck looks like before shuffling. We should have
    # done that a while ago... oh well!


playerCards()


def worker2(qual1, qual2, ind):  # this function takes in the values of two cards and does the list operations based
    # on those two cards.
    global royals, player1, player2
    if qual1 > qual2:
        player1.extend(player2[:ind + 1])
        player1.extend(player1[:ind + 1])  # the index 'ind' lets us know what index of cards are being compared. This
        # plus one is the amount of cards we need to hand over.
        for i in range(ind + 1):
            player2.pop(0)
            player1.pop(0)
    elif qual1 == qual2:
        if len(player1) > ind + 2 and len(player2) > ind + 2:
            collect(ind + 2)
        else:
            print("Lack of cards results in loss")
            if len(player1) > len(player2):
                player1.extend(player2)
                player1.extend((player1[:len(player2)]))
                for i in range(len(player2)):
                    player2.pop(0)
                    player1.pop(0)

            else:
                player2.extend(player1)
                player2.extend((player2[:len(player1)]))
                for i in range(len(player1)):
                    player1.pop(0)
                    player2.pop(0)
    else:
        player2.extend(player1[:ind + 1])
        player2.extend(player2[:ind + 1])
        for i in range(ind + 1):
            player1.pop(0)
            player2.pop(0)


def collect(ind):  # relates the royal cards to the number cards and strips the suit. Uses worker2 to compare and do
    # list operations
    global royals, player1, player2
    if player1[ind][:-3] not in royals and player2[ind][:-3] not in royals:
        worker2(int(player1[ind][:-3]), int(player2[ind][:-3]), ind)
    elif player1[ind][:-3] in royals and player2[ind][:-3] in royals:
        worker2(royals.index(player1[ind][:-3]), royals.index(player2[ind][:-3]), ind)
    elif player1[ind][:-3] in royals:
        worker2(royals.index(player1[ind][:-3]) + 11, int(player2[ind][:-3]), ind)
    else:
        worker2(int(player1[ind][:-3]), royals.index(player2[ind][:-3]) + 11, ind)


count = 0
while len(player1) and len(player2):
    collect(0)
    print("player1 ", player1)  # run the simulation until end is reached
    print("player2 ", player2)
    print()
    count += 1

if len(player2):
    print("Player 2 won in " + str(count) + " turns!")  # print the winner and number of turns it took

else:
    print("Player 1 won in " + str(count) + " turns!")
