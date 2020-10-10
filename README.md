# card_battle
The classic card duel game with a twist. A person with the smallest card wins the hand.

### Card Battle Rules:
Battle Cards has the following rules:
1. There are N numbers of players (minimum 2) who will deal alternately.
2. This is played with a single deck of cards, that is, 52 cards with 4 suits  (Diamonds, Clubs, Hearts, Spades) 13 cards each.
3. The deck is shuffled by the dealer before the start of each game.
4. All the cards are dealt face down from the deck, starting with non-dealer and distributed until the end.
5. None of the players can look at their cards.
6. The game follows a series of battles.
7. Battles are played until we have a winner. if a player has less than 5 cards, they are out of the game.
8. In the battle, each player enter's the battle by putting the top card on the table face up.
9. The player with the lowest card wins the battle. (Ace is the lowest card and King being the highest card)
10. In case of a tie between the lowest cards, those players will continue to play by putting the next card face-up on the table until there is a winner.  
11. The players winning the battle collects all the cards on the table to its personal deck and shuffle before the next round of battle.
12. while in battle if players run out of cards, then the player is out/ looses.
13. the game is concluded when there is one player left. (*Winner !*).


###  Code Functions
In designing the game critical functions and classes were the cards, deck, shuffling of cards, and dealing of the game.

I also developed a custom comparator to compare the cards and decide the winner. For example, comparing J (Jack) and K (King) where J will be the winner since it's smaller than K.

### Final Output
Final gameplay is saved in a text file with all the dealing and rounds of the battle.
Below is the output file of the game. 
![CardBattle1](https://github.com/bhattidhruv/card_battle/blob/main/out_put1.JPG)
The above image is the screenshot of the output text file with the initial card dealing.

![CardBattleImage](https://github.com/bhattidhruv/card_battle/blob/main/output_2.JPG)
The above image is the screenshot of the output text file with the final winner of the card battle.
