#include <iostream>
#include <time.h>
using namespace std;

class Card //class named Card
{
private:
	int card[12]; //private variables
	int value[12];
	int num;
public:
	Card() //constructor
	{
		card[0] = rand() % 13 + 1; //get first random card from 1~13
		if (card[0] == 11 || card[0] == 12 || card[0] == 13) 
			value[0] = 10; //if card[0] is 11, 12, 13, value[0] will become 10
		else if (card[0] == 1) 
			value[0] = 11; //if card[0] is 1, value[0] will become 11
		else
			value[0] = card[0]; //other numbers for card[0] is the value

		card[1] = rand() % 13 + 1; //repeat the steps above for card[1] (second random card)
		if (card[1] == 11 || card[1] == 12 || card[1] == 13)
			value[1] = 10;
		else if (card[1] == 1)
			value[1] = 11;
		else
			value[1] = card[1];
		num = 2;
	}
	void card_again() //card_again() function to repeat the steps above when starting a new game, reset private members' value
	{
		card[0] = rand() % 13 + 1;
		if (card[0] == 11 || card[0] == 12 || card[0] == 13)
			value[0] = 10;
		else if (card[0] == 1)
			value[0] = 11;
		else
			value[0] = card[0];

		card[1] = rand() % 13 + 1;
		if (card[1] == 11 || card[1] == 12 || card[1] == 13)
			value[1] = 10;
		else if (card[1] == 1)
			value[1] = 11;
		else
			value[1] = card[1];
		num = 2;
	}
	int dealer_card() //dealer_card() integer type function
	{
		return card[0]; //returns card[0] when function is called
	}
	void deal() //void deal() function to get new random cards when called
	{
		card[num] = rand() % 13 + 1;
		if (card[num] == 11 || card[num] == 12 || card[num] == 13)
			value[num] = 10;
		else if (card[num] == 1)
			value[num] = 11;
		else
			value[num] = card[num];
		num++; //increase num by 1
	}
	void deal_hit() //void deal_hit() function to get new random cards when 'hit'
	{
		card[num] = rand() % 13 + 1;
		if (card[num] == 11 || card[num] == 12 || card[num] == 13)
			value[num] = 10;
		else
			value[num] = card[num];
		num++;
	}
	void print() //void print() function to print out cards on the console window when called
	{
		int i = 0; //declare integer i with the value of 0
		printf("%d ", card[i]); //print out the number of card[0] from card array
		for (i; i < num - 1; i++)
		{
			printf("and %d ", card[i + 1]); //print out the number of cards from 1 to num
		}
		cout << endl; // end line
	}
	int sum() //integer type function sum()
	{
		int summ = 0; //declare integer type variable summ with the value of 0
		for (int i = 0; i < num; i++) 
			summ += value[i]; // for loop, adding each value[i]'s value to get the value of summ

		return summ; //return the value of summ when function is called
	}
	/*bool operator<(Card &b)
	{
	if (sum() < b.sum())
	return true;
	else
	return false;
	}*/
};

int main()
{
	srand(time(NULL)); //get random number
	Card dealer, player; //declare class object dealer and player

	cout << "Welcome to Blackjack Game!" << endl << endl; //print  out "Welcome to Blackjack Game!"
	cout << "You have $1000. How many games do you want?"; //print out "You have $1000. How many games do you want?"
	int gamenum = 0; //declare integer type variable gamenum with the value of 0
	cin >> gamenum; //get the value of gamenum
	int money_sum = 1000; //declare integer type variable money_sum with the value of 1000 (total value of money at the beginning)
	cout << endl;

	for (int n = 0; n < gamenum; n++)
	{
		printf("<<Game #%d>>\n", n + 1); //print out <<Game #%d>> depending on the value of i
		cout << "Please place your money: $"; //print out "Please place your money: $"
		int m = 0; //declare integer type variable m with value of 0
		cin >> m; //get the value of m

		player.card_again();//access class members
		dealer.card_again();

		cout << endl << "The dealer has " << dealer.dealer_card() << " and X card" << endl; //print out "The dealer has dealer.dealer_card() and X card"
		cout << "You have "; //print out "You have "
		player.print(); //access class members

		if (player.sum() == 21)
		{
			cout << "Blackjack! You Win $" << m * 2 << "!!" << endl; //print out "Blackjack! You Win $" 
			money_sum += m * 2; //value of money_sum 2 times bigger than the betting price
			cout << "Now you have $" << money_sum << endl << endl; //print out "Now you have $ value (of money_sum)
		}
		else
		{
		WANT://function named WANT
			cout << "What do you want? (1:Hit, 2:Stand)"; //print out "What do you want? (1:Hit, 2:Stand)"
			int n; //declare integer type variable n
			cin >> n; //get the value of integer n
			if (n == 1)
			{
				player.deal_hit(); //acess function deal_hit()
				cout << endl << "You have "; 
				player.print(); //aaccess function print 
				goto WANT; //goto WANT
			}

			else if (n == 2) //if n22
			{
				if (player.sum() > dealer.sum())
				{
					cout << endl << "The dealer has "; //print out "The dealer if :
					dealer.print(); //access function print()

					if (player.sum() <= 21) //if player.sum) is <= 21
					{
						if (player.sum() == 21) //print out below when player's card is <= than 21
						{
							cout << "Blackjack! You Win $" << m * 2 << "!!" << endl;
							money_sum += m * 2;
							cout << "Now you have $" << money_sum << endl;
						}
						else
						{
							money_sum += m; //gets the value of money_sum by m
							cout << "You Win $" << m << endl; 
							cout << "Now you have $" << money_sum << endl;
						}
					}
					else //print out below when printing bust (card if bigger than 21)
					{
						cout << "Bust" << endl; 
						cout << "You lose $" << m << endl;
						money_sum -= m; //value of money_sum relative to m, changes by -1 
						cout << "Now you have $" << money_sum << endl;
					}
				}

				else if (player.sum() < dealer.sum()) //if player.sum is smaller than dealer.sum, print out below
				{
					cout << endl << "The dealer has ";
					dealer.print();

					cout << "You lose $" << m << endl;
					money_sum -= m;
					cout << "Now you have $" << money_sum << endl;
				}

				else if (player.sum() == dealer.sum()) //if player.sum() is the same as dealer.sum(), print out below 
				{
					if (player.sum() == 21) //if player.sum() is 21, print out below
					{
						cout << "Blackjack! You Win $" << m * 2 << "!!" << endl;
						money_sum += m * 2; //money_sum's value is increased by double the betting
						cout << "Now you have $" << money_sum << endl; //print out "Now you have $"
					}
					else
					{
						cout << endl << "The dealer has ";
						dealer.print(); //access class members

						cout << "Draw" << endl;
						cout << "Now you have $" << money_sum << endl;
					}
				}
			}
			cout << endl;
		}
	}	cout << "Finally, you have $" << money_sum << endl;

	system("pause"); // stop the console window from disappearing when the program is terminated
	return 0; // finish program
}




