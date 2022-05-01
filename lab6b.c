/******************************************************************************

             EECS2031 – Lab 6

*	Filename:	lab 6b.c

*	Author: Prabhakaran, Rohit

*	Email: rohitp@my.yorku.ca

*	EECS login ID: rohitp

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
char str[101];
int i,count=0;
printf("Enter the line of characters>");
fgets(str,101,stdin);
for(i=0;str[i];i++)
{
 if(str[i]==' ')
count++;   
}
printf("%d",count);
}
