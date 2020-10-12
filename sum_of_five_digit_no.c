#include<stdio.h>
#include<math.h>
#include<conio.h>

int main()
{
   int num, a, b, c, d, e, sum;

   printf("Enter five digit number: \n");
   scanf("%d" , &num);

   a = num % 10;
   b = (num/10)%10;
   c = (num/100)%10;
   d = (num/1000)%10;
   e = (num/10000)%10;

   sum = a+b+c+d+e;

   printf("The sum of the digits of number is: %d" , sum);


}
