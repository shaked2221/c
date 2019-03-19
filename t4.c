/* Assignment: 3
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

enum model { Toyota, Ford, Fiat, Nissan };
enum color { white, black, yellow, blue, red, green };

#define MODEL 4
#define COLOR 6
#define YEAR 3

void add(int arr[MODEL][YEAR][COLOR]);/*הוספת רכב למרגר*/
int return1(int arr[MODEL][YEAR][COLOR]);/*בדיקת מלאי לפי דגם שנה וצבע*/
int find_model(int arr[MODEL][YEAR][COLOR]);/*בדיקה מלאי לפי דגם רכב*/
int find_year(int arr[MODEL][YEAR][COLOR]);/*בדיקת מלאי לפי שנה*/
int frequen_color(int arr[MODEL][YEAR][COLOR]);/*רכב  שיש מימנו הכי הרבה לפי צבע*/
int main() {
	
	int arr[MODEL][YEAR][COLOR] = { 0 };
	int chose;
	

	do
	{
	printf("plese selcet want you want to do \n 1 add car to the mager\n 2 for see  amount car with specic moderl yaer and color \n 3-for see amount of specipic model\n 4- to see amount by specific year\n 5- to see the color you got the biggest in the car\n 6-for exit\n");
	scanf("%d", &chose);
	switch (chose)
	{
	case 1:add(arr);
			break;
	case 2:return1(arr);
		break;
	case 3: printf("the number of cars you have in specisc models is %d\n",find_model(arr));
		break;
	case 4:printf("the number of cars you have in specisc year is %d\n", find_year(arr));
		break;
	case 5:printf("the number of is color you have is  %d \n", frequen_color(arr));
		break;
	case 6: exit(1);
			break;
	default:printf("wrong chose try agein\n");
			break;
	}

	} while (chose!=5);

	return 0;
}

void add(int arr[MODEL][YEAR][COLOR])
{
	int maker, year1,color1;
	printf("plese selct your maker\n 0- Toyota\n 1 -Ford\n 2- Fiat\n 3- Nissan \n");
	scanf("%d", &maker);
	printf("plese selct your year\n 0-2014\n 1 -2015\n 2- 2016\n");
	scanf("%d", &year1);
	printf("plese selct your color\n 0- white\n 1-black\n 2-yellow\n 3- blue\n 4-red\n 5-green\n ");
	scanf("%d", &color1);
	arr[maker][year1][color1]++;
	return 0;
}
int return1(int arr[MODEL][YEAR][COLOR])
{
	int maker, year1, color1;
	printf("serch the amount of car by specic model year and color \n");
	printf("plese selct your maker 0- Toyota\n 1 -Ford\n 2- Fiat\n 3- Nissan \n");
	scanf("%d", &maker);
	printf("plese selct your year\n 0-2014\n 1 -2015\n 2- 2016\n");
	scanf("%d", &year1);
	printf("plese selct your color\n 0- white\n 1-black\n 2-yellow\n 3- blue\n 4-red\n 5-green\n ");
	scanf("%d", &color1);
	printf("the amount of the model tou chose is %d\n", arr[maker][year1][color1]);
	return 0;
}
int find_model(int arr[MODEL][YEAR][COLOR])
{
	int maker,i, j, count=0;
	printf("serch the amount of car by specic model  \n");
	printf("plese salect your model\n  0- Toyota\n 1 -Ford\n 2- Fiat\n 3- Nissan  \n");
	scanf("%d", &maker);
	for (i = 0; i < YEAR; i++) 
	{
		for (j = 0; j < COLOR; j++)
			count += arr[maker][i][j];
	}

	return count;
}
int find_year(int arr[MODEL][YEAR][COLOR]) 
{
	int year1, i, j, count = 0;
	printf("serch the amount of car by specic year  \n");
	printf("plese selct your year\n 0-2014\n 1 -2015\n 2- 2016\n  \n");
	scanf("%d", &year1);
	for (j = 0; j < MODEL; j++)/*ריצה על הדגם*/
	{
		for (i=0;i<COLOR; i++)
		count += (arr[j][year1][i]);
	}

	return count;
}
int frequen_color(int arr[MODEL][YEAR][COLOR])
{
	int count=0, coubt_bigger=0, i, j, k,f=0;
	for (k = 0; k < COLOR; k++)/*קודם רצים על  הצבע לאחר מיכן על השנה ואז על הדגם ואם הצבע שאחרי הראשון גדול יותר הוא שומר אותו כהכי גדול*/
	{
		for (j = 0; j < YEAR; j++)
		{
			for (i = 0; i < MODEL; i++) 
			{
				count += arr[i][j][k];
			}
		}
		if (count > coubt_bigger)
		{
			coubt_bigger = count;
			count = 0;
			f = k;
		}
	}
	printf("the color you have alot from him is %d", f);
	return coubt_bigger;
}