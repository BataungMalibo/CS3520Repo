#include <stdio.h>
#include<math.h>

// Names: MALIBO ERNEST BATAUNG
// Student_Number: 202000188

/*The following program determines and prints the first 10 reversable prime squares.

- Each number MUST possess the following attributes:
												1. it's not a palindrome, 
												2. must be a square of a prime number,
												3. its reverse is a square of a prime number
												
*/

//function prototypes
int revNum(int num);//reverses a number.
int palCheck(int num);//palindrome checker
int primeCheck(int num);//prime number checker.
int sqrNum(int num);//squares a number.  
int is_sqrOfPrime(int num);//checks if the number is a square of a prime.
int revIsSqr_OfPrime(int num);//checks if the reverse of a number is a sqaure of a prime.

int main()
{
	int lim_;//range upper bound.
	printf("Enter the range upperbound: ");
	scanf("%d", &lim_);
	
	//calling nested functions inside a for loop to check the conditions and return, and print reversable prime squares. 
	for(int j = 0; j < lim_; j++)
	{
		if(!palCheck(j))
		{
			if(is_sqrOfPrime(j) && (revIsSqr_OfPrime(j)))
			{
				{
					printf("Reversal prime squares in the given range are:\n");
					printf("%d \t\t", j);
				}
			}
			else
			{
				printf("No reversable prime squares in the given range");
			}
		}
		else
		{
			continue;
		}

	}
	
	return 0;
}

//function implementations.

int revNum(int num)//reverses a number.
{
	int rev = 0, rem = 0;
	
	while(num != 0)
	{ 
		rem = num%10;
		rev = rev*10 + rem;

		num/=10;
	}
	return rev;
}

int palCheck(int num)//palindrome checker.
{
	if(num == revNum(num))
	{
		return 1;
	}
	else
	{
		return 0;
	}
		
}

int primeCheck(int num)//prime number checker.
{ 
	int flag =0;
	if (num == 0 || num == 1)
	{
		flag = 1;
	}
   	
  for (int i = 2; i <= num / 2; ++i)
   {

    if (num % i == 0)
	{
      flag = 1;
      break;
    }
  }

  if (flag == 0)
  {
  	return 1;
  }
    
  else
  {
  	return 0;
  }
    
}

int sqrNum(int num)//squares a number.
{
	return num*num;
}


int is_sqrOfPrime(int num)//checks if the number is a square of a prime.
{
	int flag = 0;
	for(int i = 0; i < num; i++)
	{
		if((primeCheck(i) == 1) && (sqrNum(i) == num)){
			flag = 1;
			return 1;
		}
	}
	if(flag != 1){
		return 0;
	}
}

int revIsSqr_OfPrime(int num)//checks if the reverse of a number is a sqaure of a prime.
{
	int reverc = 0;
	
	reverc = revNum(num);
	if(is_sqrOfPrime(reverc))
		return 1;
	else
		return 0;	
}

