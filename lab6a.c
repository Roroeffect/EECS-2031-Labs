/***************************************

*	EECS2031 – Lab 6

*	Filename:	lab 6a.c

*	Author: Prabhakaran, Rohit

*	Email: rohitp@my.yorku.ca

*	EECS login ID: rohitp

****************************************/

#include <stdio.h>

int main()
{
  float inch, tocm; 
printf("Enter the measurements in inches>");
scanf("%f", &inch);
while(inch>0) 
{
tocm = inch * 2.54; 
printf("%.2f cm",tocm);
printf("\nEnter the measurements in inches>");
scanf("%f", &inch); 
}
return 0;
}
