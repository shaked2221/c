/* Assignment: 3
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define	kavoe 80
int polidrom( char[]);
int main() {
	char line[kavoe];
	printf("plese Enter the string to check if it is a palindrome when you down click space end enter \n");
	gets(line);/*scanf line*//*becreafal only 1 space betwwen word*/
	printf("the number of words polidrom is %d\n", polidrom(line));/*send to fun and diretly print*/

	return 0;
}
int polidrom(char str[]) {
	int i=0;
	int countpolinom =0;/*coun of words polindrom*/
	int endmila = 0;/*num of the last word*/
	int beginmila = 0;/*num of beginin word*/
	int flag = 1;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			endmila = i - 1;/*define mikom*/
			while (beginmila < endmila)/*whill they are differnt*/
			{			/*בדיקת פולנדרום*/
				if (str[beginmila] != str[endmila])
				{
					flag = 0;/*when it is wrong*/
				}
				if (flag == 0)/*if the letters difren break and close*/
					break;
				beginmila++;
				endmila--;
			}
			beginmila = i + 1;
			if (flag == 0) 
				flag = 1;/*do nothing and retun flag 1*/
			else
			{
			if (flag == 1) /*count polinom up*/
					countpolinom++;
			}				
		}
	i++;/*the next in the line*/
	}
	return countpolinom;
}