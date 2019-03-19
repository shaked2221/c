/* Assignment: 3
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define	kavoe 10

void play();
int new_game(int[][kavoe], int size);/*���� ���*/
int insert_all(int arr[kavoe][kavoe]);
int insert(int arr[kavoe][kavoe], int line /* ����*/, int amode/* �����*/, int length/*���� �����*/, int horison/* ���'� �� ����*/);
int check_if_good_place(int arr[kavoe][kavoe], int line /* ����*/, int amode/* �����*/, int length/*���� �����*/, int horison/* ���'� �� ����*/);
int shoot(int[][kavoe], int size, int line, int amode);/*��� �����*/
int cheak_winnig(int arr[kavoe][kavoe], int size);
int print(int arr[kavoe][kavoe], int size);


int main() {
	play();

	return 0;
}

void play()
{
	int arr[kavoe][kavoe] = { 0 };/*0 arr*/
	int size = sizeof(arr) / sizeof(arr[0][0]);/*size of matrix*/
	int chosemenw, i, p, j;

	new_game(arr, size);/*restert matrix*/
	printf("a new game has begining\n");
	insert_all(arr);
	print(arr, size);

	do
	{
		printf("plese enter a coridnate thet you want send fire \n");
		scanf("%d %d", &i, &j);
		i--;/*����� ��� �� ������ ����*/
		j--;
		p = shoot(arr, size, i, j);
		print(arr, size);
		if (p == 3)
		{
			printf("new game if you want prees 1 want finise press 0\n");
			scanf("%d", &p);
			if (p == 1)
			{
				printf("a new game has begining\n");
				play();/*restert matrix*/
			}
			else
				exit(1);
		}

	} while (p!=3);
	return 0;
}


int new_game(int arr[][kavoe], int size)/*���� ���*/
{
	int i, j;
	for (i = 0; i < kavoe; i++)
		for (j = 0; j < kavoe; j++)
			arr[i][j] = 0;
	return arr;
}

int insert_all(int arr[kavoe][kavoe]) {/*����� ������ ����� ������� ������ ��������*/
	int line, amode, long_submarine, horizontal, i; /*����� ������*/
	int x;
	/*submarine 5 long*/
	do
	{/*����� ����� 5*/
	 /*������������ �� ��� ����� ���� ���� ���� ������ �� ����� */
		printf("plese enter the place qordinat of 5 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 5;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*������� ����� �� ����� ����*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);
	do
	{/*����� ����� 4*/
	 /*������������ �� ��� ����� ���� ���� ���� ������ �� ����� */
		printf("plese enter the place qordinat of 4 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 4;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*������� ����� �� ����� ����*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);
	do
	{/*����� ����� 3*/
	 /*������������ �� ��� ����� ���� ���� ���� ������ �� ����� */
		printf("plese enter the place qordinat of 3 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 3;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*������� ����� �� ����� ����*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);

	do
	{/*����� ����� 3*/
	 /*������������ �� ��� ����� ���� ���� ���� ������ �� ����� */
		printf("plese enter the place qordinat of 3 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 3;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*������� ����� �� ����� ����*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);
	do
	{/*����� ����� 2*/
	 /*������������ �� ��� ����� ���� ���� ���� ������ �� ����� */
		printf("plese enter the place qordinat of 2 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 2;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*������� ����� �� ����� ����*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);


	return 0;
}
int insert(int arr[][kavoe], int line /* ����*/, int amode/* �����*/, int length/*���� �����*/, int horison/* ���'� �� ����*/) {
	int i, x;
	if ((line > 10) || (line<0))
	{/*���� �� ������ ������ ����� �� �������*/
		printf("eror not the size of the board enter a line agein\n");
		return 0;
	}
	if ((amode > 10) || (amode < 0))
	{
		printf("eror not the size of the board enter a amode agein\n");
		return 0;
	}
	if (((line - 1) + (length) >= 10) || ((amode - 1) + (length) >= 10))/*����� ��� ���� ����� �� ������ ������ ������*/
	{
		printf("eror not good place for this submarine the submarine is get out of the board\n");
		return 0;
	}
	else
	{
		if ((horison < 0) || (horison > 1))
		{
			while (((horison < 0) || (horison > 1)))
			{
				printf("eror\n\n plese enter 1 for ofki  and 0 for anci\n");
				scanf("%d", &horison);
			}
		}/*�� �� ��� ���� ������� ������� ������*/
		x = check_if_good_place(arr, line, amode, length, horison);/*����� ����� �� ���� ��� ����� �� ��� ������ ����*/
		if (x == 0)
		{
			printf("the submatine crash or not in good place like the law of the game\n");
			return 0;
		}
		/*����� ������ ������ ����*/
		if (horison == 1)
		{/*����� ����*/
			for (i = 0; i < length; i++)
			{
				arr[line - 1][amode - 1] = 2;
				amode++;
			}
		}
		else/*  ����� �����*/
		{
			for (i = 0; i < length; i++)
			{
				arr[line - 1][amode - 1] = 2;
				line++;
			}
		}
	}
	return 1;
}
/*����� �� ���� ����� ������*/
int check_if_good_place(int arr[kavoe][kavoe], int line /* ����*/, int amode/* �����*/, int length/*���� �����*/, int horison/* ���'� �� ����*/) {
	int i, j = 0;
	int newline;/*���� ��� ������� ����� ��� �����*/
	int newamode;
	line--;/*�� ����� ��� ������ ���� � 0 -9*/
	amode--;/*���*/
	if (horison == 1)/* ����� ����� ����� ����� ����� ����*/
	{
		newline = (line + length + 1);/*���� ��� �������*/
		newamode = (amode + 1);/*���� �� ����� ���� 1*/
		if (newamode == 10)/*����� ���� �� ���� ����� � ��� ���� ����� ������ �����*/
			newamode--;
		if (newline == 10)/*��� �� ������ �����=� ��� ���� ����� ������ �����*/
			newline--;
		if (line - 1 == -1)/*����� ������ ������ 10 �� 10*/
			line++;
		if (amode - 1 == -1)/*����� ������ ������ 10 �� 10*/
			amode++;
		for (i = (line - 1); i <= (newline); i++)
		{
			for (j = (amode - 1); j <= newamode; j++)
			{
				if (arr[i][j] == 2)
				{
					printf("not good place for sunbmarine  \n");
					return 0;
				}
			}
		}

	}
	else
	{
		if (horison == 0) /*����� ������*/
		{
			newline = (line + 1);/*���� ��� �������*/
			newamode = (amode + length + 1);/*���� ����� �����*/
			if (newamode == 10)/*����� ���� �� ���� ����� � ��� ���� ����� ������ �����*/
				newamode--;
			if (newline == 10)/*��� �� ������ �����=� ��� ���� ����� ������ �����*/
				newline--;
			if (amode - 1 == -1)
				amode++;
			if (line - 1 == -1)
				line++;
			for (i = (line - 1); i <= (newline); i++)
			{
				for (j = amode; j <= newamode; j++);
				{
					if (arr[i][j] == 2)
					{
						printf("not good place for sunbmarine  \n");
						return 0;
					}
				}
			}
		}
	}

	return 1;
}

int shoot(int arr[][kavoe], int size, int line, int amode, int length) {
	int x;
	if (line < 0 || line>9 || amode < 0 || amode>9)/*����� ��� ����� �������*/
	{
		printf(" \n\neror qordint out of the board\n");
		return -1; /*�������� �� ����*/
	}
	if (arr[line][amode] != 2)
	{
		printf("miss\n");
		arr[line][amode] = 1;
		return 0;
	}
	if (arr[line][amode] == 2)
	{
		printf("hit!!!!\n");
		arr[line][amode] = 3;
		/*�����  �� �����*/
		/*������*/
		x = cheak_winnig(arr, size);
		if (x == 1)
		{
			printf("winning you good!!!!\n");
			return 3;
		}
		return 1;
	}


	return 0;
}
/*������� ����� ������*/
int cheak_winnig(int arr[kavoe][kavoe], int size)
{
	int i, j;
	for (i = 0; i < kavoe; i++)/*���� �� �� ����� ����� ����� � �� ��� ������*/
	{/*����� ������*/
		for (j = 0; j < kavoe; j++)
		{
			if (arr[i][j] == 2)
				return 0;
		}
	}
	return 1;
}

int print(int arr[kavoe][kavoe])
{
	int i, p;
	for (i = 0; i < kavoe; i++)
	{/*����� �����*/
		for (p = 0; p < kavoe; p++) {
			printf("%d ", arr[i][p]);
			if (p == 9)
				printf("\n");
		}
	}
	return 0;
}