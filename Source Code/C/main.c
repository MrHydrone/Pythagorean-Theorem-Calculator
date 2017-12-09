/*
 * Originally made by Lane
 * Pythagorean Theorem calculator used to help people and students for finding the solution
 * to different 'pythagorean problems'
 *
 * This program is openly editable to anyone who desires to do so.
 *
 * Compatible with Windows, OS X, and Linux.
 * 
 */

#include <stdio.h>
#include <math.h>

int least_acceptable = 1; // The lowest value a user can input for it to be accepted.

void Menu_Options() // Menu
{
	puts("Enter 1 for finding the hypotenuse\n");
	puts("Enter 2 for finding if a set makes a pythagorean tri\n");
	puts("Enter 3 to find the value/length of a leg\n");
	puts("Enter 4 to find if a triangle is accute, obtuse, or a right triangle\n");
	puts("Enter 5 to exit\n\n");
}


int main(int argc, char *argv[]) // Main function
{
	float entered_a, entered_b, entered_c; // Values that will hold input by the user.
	float a, b, c; // Values that will hold the new value of the entered number.
  
  //entered_c and c will be the hypotenuse values.

  int choice; //User will enter a number from the menu.
  
menu_return:
  
  Menu_Options();
  printf("Choice: ");
 	scanf("%d", &choice);
  
	if(choice > 5)
  		{
    			puts("You must enter a number from one to five\n\n");
    			fflush(stdin); // Bad habbit, don't be mad. Clears the input buffer.
   			goto menu_return;
  		}
  
	switch (choice)
  {
    
	case 1:		// Will be used for option 1
      
    	printf("Please enter the first leg value: ");
  	scanf("%f", &entered_a);
  
  	printf("\nPlease enter the second leg value: ");
  	scanf("%f", &entered_b);
  
	if(entered_a < least_acceptable || entered_b < least_acceptable)
	{
		puts("Anything less than 1 is not acceptable. Please try again.\n\n");
		goto menu_return;
	}

  a = pow(entered_a, 2);
  b = pow(entered_b, 2);
  
  //Algorithm: a^2 + b^2 = c^2
  
  c = a + b;
  	printf("\nAnswer: %f", sqrt(c));
    	printf("\nSOLUTION\n\t %f squared + %f squared = %f\n\tThe square root of %f is %f", entered_a, entered_b, c, c, sqrt(c));

    break;
       	
    	case 2:		// Will be used for option 2
      
    /* For finding a pythagorean tri
      The user must enter 3 numbers(a, b, c)
      If a^2 + b^2 equals c^2 then it makes a pythagorean tri.
      If not, then it doesn't
      */
      
    printf("Please enter the first leg value: ");
    scanf("%f", &entered_a);
    
    printf("\nPlease enter the second leg value: ");
    scanf("%f", &entered_b);
    
    printf("\nPlease enter the hypotenuse value: ");
    scanf("%f", &entered_c);
   
	if(entered_a < least_acceptable || entered_b < least_acceptable || entered_c < least_acceptable)
	{
		puts("You have entered an invalid value. Values can be no less than 1.\n\n");
		goto menu_return;
	}

    	a = pow(entered_a, 2);
    	b = pow(entered_b, 2);
    	c = pow(entered_c, 2);
				
    if(a + b == c)
    {
      puts("\nThe set is a correct pythagorean tri\n");
      printf("SOLUTION\n\t %f squared + %f squared = %f\n\t%f squared = %f\nThey equal therefore they make a correct pythagorean tri.\n\n", entered_a, entered_b, a+b, entered_c, c);
    	goto menu_return;
    }
    
    else if(a + b > c || a + b < c)
    {
      puts("\nThe set does not make a pythagorean tri\n");
      printf("SOLUTION\n\t %f squared + %f squared = %f\n\t%f squared = %f\nThey do not equal therefore they do not make a correct pythagorean tri.\n\n\n\n", entered_a, entered_b, a+b, entered_c, c);
	goto menu_return;
    }
    
    break;
    
    
    	case 3:		// Will be used for option 3
    
    //Essentially, to find the leg's value, you get square the values of a and c and then square that to get b
    
    printf("Please enter the leg value: ");
    scanf("%f", &entered_a);
    
    printf("\nPlease enter the hypotenuse value: ");
    scanf("%f", &entered_c);
    
     if(entered_c < least_acceptable || entered_a < least_acceptable || entered_c < entered_a) // Because we all know the leg can't be longer than the hypotenuse
    {
      puts("\nYou have entered an invalid number for the hypotenuse.\n\n");
      goto menu_return;
    }
    

    a = pow(entered_a, 2);
    c = pow(entered_c, 2);
    
    b = c - a;
    printf("\nValue of missing leg: %f\n\n", sqrt(b));
    printf("SOLUTION\n\t%f squared = %f; %f squared = %f\n%f-%f = %f\nThen square root that to get %f\n\n\n\n", entered_a, a, entered_c, c, c, a, c-a, sqrt(b));
    
    break;

	case 4:	// Lastly option 4
    
    // For finding if a triangle is accute, obtuse, or right
 
   printf("Please enter the first leg value: ");
   scanf("%f", &entered_a);

   printf("\nPlease enter the second leg value: ");
   scanf("%f", &entered_b);

   printf("\nPlease enter the hypotenuse value: ");
   scanf("%f", &entered_c);

	 if(entered_a < least_acceptable || entered_b < least_acceptable || entered_c < least_acceptable)
	{
		puts("You have entered an invalid value. Values can be no less than 1\n\n");
			goto menu_return;
	}

	if(entered_a > entered_c || entered_b > entered_c)
	{
		puts("A legs value can not be higher than the hypotenuse. Please try again\n\n");
		goto menu_return;
	}

	a = pow(entered_a, 2);
	b = pow(entered_b, 2);
	c = pow(entered_c, 2);
	
	if(a + b > c)
	{
		puts("The triangle is accute.\n");
		printf("SOLUTION\n\t %f squared + %f squared = %f\n\t%f squared = %f\nThe two legs value is higher than the hypotenuse therefore the triangle is accute\n\n\n\n", entered_a, entered_b, a+b, entered_c, c);
		goto menu_return;
	}
		else if(a + b < c)
		{
			puts("The triangle is obtuse.\n");
			printf("SOLUTION\n\t %f squared + %f squared = %f\n\t%f squared = %f\nThe two legs value is lower than the hypotenuse therefore the triangle is obtuse\n\n\n\n", entered_a, entered_b, a+b, entered_c, c);
			goto menu_return;
		}
			else if(a + b == c)
			{
				puts("The triangle is a right triangle.\n");
				printf("SOLUTION\n\t %f squared + %f squared = %f\n\t%f squared = %f\nThe two legs value is the same as the hypotenuse therefore the triangle is a right triangle\n\n\n\n", entered_a, entered_b, a+b, entered_c, c);
				goto menu_return;
			}
		break;
	}

	/*
	 * Option 5 is not in the switch statement because it's just used as an exit option.
	 * The switch statement will see 5 is not an answer and just let it fly over and return 0 will be used to exit
	 */

  return 0; // Exit the program with no errors reported.
}

