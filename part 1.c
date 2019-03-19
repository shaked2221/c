/* Assignment: 5
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */


#define _CRT_SECURE_NO_WARNINGS 
#define kavoe 80
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long repeat(int digit, int length);/*1*/
int postive(int arr[], int size);/*2*/
int postivep3(int arr[], int size);
int p4(int num);
int p5(int arr[], int size);
int p6(char[], char charr);
void p7(char[]);
int main() {
	/*1*/
	long digit, length;
	printf("plese enter a digit\n");
	scanf("%d", &digit);
	printf("plese enter the lengthyou want\n");
	scanf("%d", &length);
	printf("%ld",(repeat(digit,length)));
	printf("\n");

	/*2*/
	int size;
	int *arr,i;
	printf("plese enter the size you want: ");
	scanf("%d", &size);
	arr = (int*)malloc(size*(sizeof(int)));
	for (i = 0; i < size; i++)
	{
		printf("plese enter a num in place %d:  ", i+1);
		scanf("%d", &arr[i]);
	}
	printf("%d\n",postive(arr, --size));
	free(arr);


	/*3*/
	printf("plese enter the size you want: ");
	scanf("%d", &size);
	arr = (int*)malloc(size*(sizeof(int)));
	for (i = 0; i < size; i++)
	{
		printf("plese enter a num in place %d:  ", i+1);
		scanf("%d", &arr[i]);
	}
	printf("%d\n",postivep3(arr, --size));
	free(arr);

	/*4*/
	int num4;
	printf("plese enter num: ");
	scanf("%d", &num4);
	printf("%d\n",p4(num4));

	/*5*/
	int sizeArr;
	printf("plese enter the godal of student you want: ");
	scanf("%d", &sizeArr);
	arr= (int*)malloc(sizeArr*(sizeof(int)));
	for (i = 0; i < sizeArr; i++)
	{
		printf("plese enter the exam grade %d:  ", i+1);
		scanf("%d", &arr[i]);
	}
	printf(" the number of studn who pass is %d\n",p5(arr, --sizeArr));
	free(arr);

	/*6*/
	char str[kavoe], charr;
	printf("plese enter the string you want\n");
	getchar(';');
	gets(str);
	printf("plese enter the char you want count\n");
	scanf("%c", &charr);
	printf(" the number of the repet char is %d\n", p6(str, charr));
	
	/*7*/
	printf("plese enter the string you want to print\n");
	getchar(';');
	gets(str);
	p7(str);
	
	return 0;
}

long repeat(int digit, int length) {
	if (digit == 0)
	{
		printf("%d\n", digit);
		return 0;
	}
	if (length == 1)/*תנאי עצירה*/
		return (digit);
	return digit+(repeat(digit*10, length - 1));/*שולח תמספר כפול 10 עד שמגיע לסוף ואז מחבר הכל*/
}
int postive(int arr[], int size) {
	if (arr[size] < 0)
		return 0;
	else
	{
	if (size == 0)
		return 1;/*כלומר עבר על הכל והכל בסדר*/
	else
		return (postive(arr, (--size)));
	}
}
int postivep3(int arr[], int size) {
	if (arr[size] < 0)
		return 1;
	else
	{
	if (size == 0)
		return 0;/*אם הגיע לסוף ואין מספרים שלילים*/
	else
		return (postivep3(arr, (--size)));
	}
}
int p4(int num) {/*עובד כאשר מספר תקין כמו345 אבל כאשר 506 שגיאה במצב ה 0*/
	int dight1, dight2;
	if (num < 10)/*תנאי עצירה*/
		return 1;
	else
	{
		dight1 = (num%10);/*ספרה אחרונה*/
		dight2 = ((num/10) % 10);/*ספרה לפני אחרון*/
		if (dight1 > dight2)/*ספרה מהסוף גדולה מהספרה לפניה */
			return (p4(num / 10));/*תתקדם להמשך הבדיקה הלאה*/
		else
			return 0;/*שגיאה מספר לא בסדר עולה תחזיר 0 */
	}

}
int p5(int arr[], int size) {
	int count = 0;
	if (size == -1)
		return 0;/*תנאי עצירה שעבר על כל התלמידים*/
	if (arr[size] >= 56)
		count++;
	count += (p5(arr, --size));
		return count;
}
int p6(char str[], char charr) {/*המונה הוא מה שמוחזר ואם האות שווה אז הוא כל פעם מעלה אותו ב 1*/
	if (str[0] == '\0')/*סוף המחרוזת  תנאי עצירה*/
		return 0;
	else
	{
		if (str[0] == charr)/*אם המיקום במחרוזת שווה לאות*/
			return (1 + p6(++str, charr));/*תחזיר 1 פלוס ושתשלוח תשלח  מהתו הבא במחרוזת*/
		else
			return (0 + p6(++str, charr));/*תחזיר פלוס 0 כאילו לא לעלות תמונה מהסוף ותשתשלוח תשל כאילו מהתו הבא במחרוזת*/
	}
}
void p7(char str[]) {
	if (str[0] != '\0') /*סוף המחרוזת  תנאי עצירה*/
	{
		printf("%c", str[0]);
		p7(++str);
	}/*מכיוון שזה פוקניצת וויד לא צריך להחזיר כולן לכן זה מדפיס ומסיים*/
}
