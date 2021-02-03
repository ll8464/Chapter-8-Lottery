//Lee Lacey
//ITSE 1307
//Chapter 8 Lottery

#include <iostream>
#include <iomanip>
using namespace std;
//prototypes
int linearSearch(const int[], int, int);
void getChoice(char&);
int main()
{
	//Variables
	const int SIZE = 10;
	//Array picks are the described lottery picks
	int picks[SIZE] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
	int results;
	int user_number; //lottery number entered by the user
	char selection;// Menu Selection
	char Again;

		
	//---------------------------------------------------------------------
	do
	{
		cout << fixed << showpoint << setprecision(2); //  formatting
		//Function

		cout << "Please make a selection:\n\n";
		cout << "1: Enter lottery numbers\n2: Option Program Info\n3: Exit Application\n" << endl;
		cout << "Selection: " << endl;

		getChoice(selection);
		//Menu Selection
		switch (selection)
		{
			//Inpatient
		case '1': 
			cout << "Please enter a five digit lottery number: \n";
			cin >> user_number;
			results = linearSearch(picks, SIZE, user_number);

			if (results == -1)
				cout << "You did not Win.\n";
			else
				cout << "You Won!!\n";
			break;
			//Outpatient
		case '2':
			cout << "The program starts with the 10 lucky "
				 << "numbers you play each week in the lottery: \n" << endl;
			cout << "13579, 26791, 26792, 33445, 55555, 62483,"
				 <<" 77777, 79422, 85647, 93121\n"<< endl;
			cout << "It then allows you to enter this week's" 
				 <<"winning numbers using Selection 1.\n\n";
			break;



		}
		cout << "Enter y for yes or n for no to repeat again: ";
		cin >> Again;
		cout << "\033[2J\033[1;1H"; //clears the screen after each iteration

	}




	while (Again == 'Y' || Again == 'y');



	return 0;
}
int linearSearch(const int arr[], int size, int value)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < size && !found)
	{
		if (arr[index] == value) //if the winning pick is found
		{
			found = true;
			position = index;
		}
		index++; //Move on to next element
	}


	return position;
}
void getChoice(char& letter)
{
	//User selection
	cout << "Enter your Selection: ";
	cin >> letter;

	//Input Validation
	while (letter != '1' && letter != '2')
	{
		cout << "Please enter 1 or 2: ";
		cin >> letter;
	}

}