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
	if (length == 1)/*���� �����*/
		return (digit);
	return digit+(repeat(digit*10, length - 1));/*���� ����� ���� 10 �� ����� ���� ��� ���� ���*/
}
int postive(int arr[], int size) {
	if (arr[size] < 0)
		return 0;
	else
	{
	if (size == 0)
		return 1;/*����� ��� �� ��� ���� ����*/
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
		return 0;/*�� ���� ���� ���� ������ ������*/
	else
		return (postivep3(arr, (--size)));
	}
}
int p4(int num) {/*���� ���� ���� ���� ���345 ��� ���� 506 ����� ���� � 0*/
	int dight1, dight2;
	if (num < 10)/*���� �����*/
		return 1;
	else
	{
		dight1 = (num%10);/*���� ������*/
		dight2 = ((num/10) % 10);/*���� ���� �����*/
		if (dight1 > dight2)/*���� ����� ����� ������ ����� */
			return (p4(num / 10));/*����� ����� ������ ����*/
		else
			return 0;/*����� ���� �� ���� ���� ����� 0 */
	}

}
int p5(int arr[], int size) {
	int count = 0;
	if (size == -1)
		return 0;/*���� ����� ���� �� �� ��������*/
	if (arr[size] >= 56)
		count++;
	count += (p5(arr, --size));
		return count;
}
int p6(char str[], char charr) {/*����� ��� �� ������ ��� ���� ���� �� ��� �� ��� ���� ���� � 1*/
	if (str[0] == '\0')/*��� �������  ���� �����*/
		return 0;
	else
	{
		if (str[0] == charr)/*�� ������ ������� ���� ����*/
			return (1 + p6(++str, charr));/*����� 1 ���� ������� ����  ���� ��� �������*/
		else
			return (0 + p6(++str, charr));/*����� ���� 0 ����� �� ����� ����� ����� �������� ��� ����� ���� ��� �������*/
	}
}
void p7(char str[]) {
	if (str[0] != '\0') /*��� �������  ���� �����*/
	{
		printf("%c", str[0]);
		p7(++str);
	}/*������ ��� ������� ���� �� ���� ������ ���� ��� �� ����� ������*/
}
