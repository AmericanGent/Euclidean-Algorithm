#include<stdio.h>
/* 
Formula of the form b = aq + r 
	q is the QUOTIENT when b is divided by a
	r is the REMAINDER when b is divided by a
	
	goal is to find the gcd of a and b
	
	if r1 = 0, then gcd(a,b) = a 
	else if r1 > 0, apply the division algo w/ a and r1
		move all to left, find a new q2
	
	if r2 = 0, then r1 = gcd(r1, a), r1 = gcd(a,b)
	else if (r2 > 0), apply div algo again, shift to left, find new q3
	
	rx-1 = rk * qk+1 + rx
	repleat until rx = 0. Then rk = gcd(a,b) 
 */


int euclidian();

int main()
{
	int gcd;
	int a;
	int b;
	
	printf("Please input two values for a and b : ");
	scanf("%d %d",&a,&b);//Takes the user input
	
	if(b > a)//Ensures that the larger number is passed into the function as "a"
	{
		gcd = euclidian(b,a);
	}
	else
	{
		gcd = euclidian(a,b);
	}
	
	printf("The greatest common divisor of %d and %d is %d",a,b,gcd);

}

int euclidian(int a, int b)
{
	//a = b * q + r, a > b 
	int r = a % b;//Calculates r
	int q = (a-r)/b;//Calculates q
	
	/* printf("%d\n",r);
	printf("%d\n",q); */
	
	if(r == 0)//Base case 
	{
		return b;//returns number in the "b" position 
	}
	else if(r == 1)//a remainder of 1 means a and b are rel. prime and cannot be divided further 
	{
		return 1;
	}
	else//The only remaining case is that r must be > 1. Thus, it can be broken down further 
	{
		return euclidian(b,r);
	}
	
	return -1;//returns -1 if an error occurs. 
	
}