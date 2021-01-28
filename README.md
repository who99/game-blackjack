# Blackjack

## Basic Rules of Blackjack

1. Bet the amount of money ($X).

2. Dealer and player each get two cards.
- ‘A(ace)’ can be 1 or 11
- ‘10’, ‘J’, ‘Q’, ‘K’ are equal to 10.
- If player gets one ‘A’ and one ‘10’ (10 or J or Q or K), then ‘Blackjack!’, and gets twice the amount of money that was wagered($X +$2X).
- One of dealer’s cards is revealed to player.
3. Player can choose between ‘Hit’ or ‘Stand’. 
- ‘Hit’, then player will get one more card. 
  - If the total sum exceeds 21, then ‘Bust!’ = loose the game and loose ‘$X’.
  - If the total sum exceeds 21 and you have ‘Ace’, then the value of ‘Ace’ becomes 1, not 11.
- ‘Stand’, then compare the total sums of player’s and dealer’s cards.
- No more card for dealer. 
- Maximum number of ‘Hit’ is 10.
4. Repeat [step3] until the player choose ‘Stand’.
- If the total sum of player’s is bigger than the dealer’s, player gets $X+$X.
- If the dealer’s is bigger, then player loose ‘$X’.
- If same, then player get ‘$X’ back.

## Explanation of code

- Initial money = $1000
- Total number of games received at the beginning.
- At the end of game, the total amount of money is shown.
- Cards are drawn randomly by using rand() function, using random number generation.
