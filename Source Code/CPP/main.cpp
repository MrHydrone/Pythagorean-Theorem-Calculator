/*
 * Pythagorean Theorem calculator made in C++ by Lane
 * Decided to make this in C++ aswell since I thought some people may be interested in what it would look like in C++ instead of C
 * Made both the C and C++ version on Gentoo Linux
*/

#include <iostream> // Standard preprocessor directives
#include <math.h>
#include <string>

using std::cout; // So we don't have to continuously use std::cout or std::cin whenever taking user output or input
using std::cin;

int LEAST_ACCEPTABLE_NUMBER = 1; // A leg's value can't be less than one

void menu()
{
	cout << "Menu options\n\n";
	cout << "Enter 1 and press Enter to calculate regular pythagorean theorem problem(a squared + b squared = c squared)\n";
	cout << "Enter 2 and press Enter to find if a set makes a pythagorean tri\n";
	cout << "Enter 3 and press Enter to find the length of a leg\n";
	cout << "Enter 4 and press Enter to find if a triangle is accute, obtuse, or is a right triangle\n";
	cout << "Enter 5 and press Enter to exit\n\n";
}

int main(int argc, char *argv[])
{
	float entered_a, entered_b, entered_c; // For holding values that are user input
	float changed_a, changed_b, changed_c; // For holding new values.
	int choice; // For when the user enters input for the menu.

menu_return:

	menu(); // Call the menu function
	cout << "Choice: ";
	cin >> choice;

		if(choice > 5)
		{
			cout << "That is not an option, please try again.\n";
			cin.clear();
			cin.ignore(10000,'\n');
			goto menu_return;

		} else if(cin.fail()) // If the user tries to enter a letter
			{
				cout << "\nNice try buster!\n";
				cin.clear();
				return 1;
			}
	switch(choice)
	{
		case 1:
			cout << "Please enter the first leg value: ";
			cin >> entered_a;
			
			cout << "\nPlease enter the second leg value: ";
			cin >> entered_b;
			
			if(entered_a < LEAST_ACCEPTABLE_NUMBER || entered_b < LEAST_ACCEPTABLE_NUMBER)
			{
				cout << "\nA legs length can not be less than 1\n\n";
				goto menu_return;
			}
			
			changed_a = pow(entered_a, 2);
			changed_b = pow(entered_b, 2);
			changed_c = changed_a + changed_b;
			
			cout << "\nANSWER: " << sqrt(changed_c) << "\n";
			cout << "SOLUTION: " << entered_a << " squared + " << entered_b << " squared = " << changed_c << " Then square root that and you get " << sqrt(changed_c) << " \n\n";
				goto menu_return;

			break;

		case 2:
			cout << "Please enter the first leg value: ";
			cin >> entered_a;

			cout << "\nPlease enter the second leg value: ";
			cin >> entered_b;

			cout << "\nPlease enter the hypotenuse value: ";
			cin >> entered_c;
			
			if(entered_a < LEAST_ACCEPTABLE_NUMBER || entered_b < LEAST_ACCEPTABLE_NUMBER || entered_c < LEAST_ACCEPTABLE_NUMBER)
			{
				cout << "\nNeither the leg nor the hypotenuse can be below 1\n\n";
				goto menu_return;
			}

			changed_a = pow(entered_a, 2);
			changed_b = pow(entered_b, 2);
			changed_c = pow(entered_c, 2);

			if(changed_a + changed_b == changed_c)
			{
				cout << "\nThe set makes a correct pythagorean tri.\n";
				cout << "SOLUTION: " << entered_a << " squared + " << entered_b << " is equal to " << entered_c << " squared\n\n";

					goto menu_return;

			}
			else if (changed_a + changed_b > changed_c || changed_a + changed_b < changed_c)
			{
				cout << "\nThe set does not make a correct pythagorean tri.\n";
				cout << "REASON: " << entered_a << " squared + " << entered_b << " squared does not equal " << entered_c << " squared\n\n";

					goto menu_return;
			}
			

			break;

		case 3:
			cout << "Please enter the first leg value: ";
			cin >> entered_a;

			cout << "Please enter the hypotenuse value: ";
			cin >> entered_c;
				
				if(entered_a > entered_c || entered_a < LEAST_ACCEPTABLE_NUMBER || entered_c < LEAST_ACCEPTABLE_NUMBER) // Condition where if the leg value is more than the hypotenuse value
				{
					cout << "\nThe leg can not be longer than the hypotenuse.\n\n";
					goto menu_return;
				}
			
			changed_a = pow(entered_a, 2);
			changed_c = pow(entered_c, 2);
			changed_b = changed_c - changed_a;

			cout << "Length of missing leg: " << sqrt(changed_b);
			cout << "REASON: " << entered_c << " squared - " << entered_a << " squared equals " << changed_b << " and then square root it to get " << sqrt(changed_b) << "\n\n";


			break;

		case 4:
			cout << "Please enter the first leg value: ";
			cin >> entered_a;

			cout << "Please enter the second leg value: ";
			cin >> entered_b;
			
			cout << "Please enter the hypotenuse value: ";
			cin >> entered_c;

			if(entered_a < LEAST_ACCEPTABLE_NUMBER || entered_b < LEAST_ACCEPTABLE_NUMBER || entered_c < LEAST_ACCEPTABLE_NUMBER)
			{
				cout << "\nThe leg or hypotenuse value can not be less than 1.\n\n";
				goto menu_return;
			}
			if(entered_a > entered_c || entered_b > entered_c)
			{
				cout << "\nThe leg values can not be larger than the hypotenuse value.\n\n";
				goto menu_return;
			}

			changed_a = pow(entered_a, 2);
			changed_b = pow(entered_b, 2);
			changed_c = pow(entered_c, 2);

			if(changed_a + changed_b > changed_c)
			{
				cout << "\nThe triangle is accute.\n";
				cout << "REASON: " << entered_a << " squared + " << entered_b << " squared is larger than " << entered_c << " squared, therefor the triangle is accute.\n\n";
				goto menu_return;

			}	
			else if(changed_a + changed_b < changed_c)
				{
					cout << "\nThe triangle is obtuse.\n";
					cout << "REASON: " << entered_a << " squared + " << entered_b << " squared is less than " << entered_c << " squared, therefor the triangle is obtuse.\n\n";
					goto menu_return;

				}
			else if(changed_a + changed_b == changed_c)
			{
				cout << "\nThe triangle is a right triangle.\n";
				cout << "REASON: " << entered_a << " squared + " << entered_b << " squared is equal to " << entered_c << " squared, therefor the triangle is a right triangle.\n\n";
				goto menu_return;
			}

			break;
	}

	return 0;
}
