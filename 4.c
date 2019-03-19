/* Assignment: 4
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */


#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define kavoe 80
/*1*/
char *buildstring();
void FreeString(char **str);
char *ReduceString(char *st1, char *st2);
/*2*/
char *ChangeString(char *str);
/*3*/
void Build1DArray(int** arr, int* count);
void Print1DArray(int* arr, int size);
void Reduce1DArray(int** arr, int *count);
/*4*/
void BuildMatrix(int*** matrix, int row, int col);
void PrintMatrix(int** matrix, int row, int col);
void FreeMatrix(int*** matrix, int row);
void Transpose(int*** matrix, int *row, int *column);
void RemoveColumn(int*** matrix, int row, int* col, int colNumberdelte);
int main() { 
	int chose=0, *pointer;
	char *dinamy;
	char *dinamy2;
	char *dinamy3;
	char string[kavoe], string2[kavoe], str[kavoe];
	char *x;
	int *arr, count,**matrix,row,col,coldelete;
	do{
		printf("plese selecet your chose \n1 - Reduce String\n2 - UpdateString\n3 - Dynamic1DArray\n4 - Dynamic2DArray \n5 - Exit\n");
		scanf("%d", &chose);
		switch (chose)
		{
		case 1:
			printf("plese enetr a string thet will be the smell one\n"); 
			dinamy= buildstring();/*the small string*/
			printf("plese enetr a string thetyou want to redeue frome her\n");/*���� ���� � ��� 2 ���� �����*/
			dinamy2 = buildstring();/*the big string*/
			printf("the new string is\n");
			dinamy3 = ReduceString(dinamy, dinamy2);
			if ((dinamy3) == NULL) 
			{
				printf("eror\n\n");
			}
			else
				puts(dinamy3);/*�����*/
			FreeString(&dinamy);
			FreeString(&dinamy2);
			FreeString(&dinamy3);/*����� 3 ��������*/
			break;
		case 2:
			printf("plese enter string\n");
			getchar(';');
			gets(str);/*���� ������*/
			x = ChangeString(str);
			puts(x);
			free(x);/*�����*/
			break;
		case 3:
			Build1DArray(&arr,&count);/*���� �����*/
			Print1DArray(arr, count);/*�����*/
			Reduce1DArray(&arr, &count);/*������*/
			Print1DArray(arr, count);/*�����*/
			free(arr=NULL);/*���� �����*/
			break;
		case 4:
			printf("plese enter the number of row \n");
			scanf("%d", &row);
			printf("plese enter the number of col\n");
			scanf("%d", &col);
			BuildMatrix(&matrix, row, col);
			PrintMatrix(matrix, row, col);
			Transpose(&matrix, &row, &col);
			printf("tansopse matrix\n");
			PrintMatrix(matrix, row, col);
			printf("enter the col you want to delete\n");
			scanf("%d", &coldelete);
			printf("after delet\n");
			RemoveColumn(&matrix, row, &col, coldelete);
			PrintMatrix(matrix, row, col);
			FreeMatrix(&matrix, row);

			break;
		case 5: printf("Have a nice day ! \n");
				exit(1);
			break;
		default:printf(" eror\t wrong choise\n");
			break;
		}
		} while (chose!=5);
	return 0;
} 
/*�����  1*/
char *buildstring()
{
	getchar('\n');
	char str[kavoe];
	char *dinamy;
	gets(str);
	dinamy = (char*)malloc(strlen(str) + 1);
	if (dinamy != NULL)
			strcpy(dinamy, str);/*����� ������� �������*/
	return dinamy;
}
void FreeString(char **str)
{
	free(*str);
}
char * ReduceString(char * st1, char * st2) {
	char *str3, *zamni;
	int i, j = 0, counter = 0, flag = 0;
	zamni = (char*)malloc((strlen(st2) + 1) * sizeof(char));
	if (strlen(st1) > strlen(st2))/*�� ������� ������� ���� ���� �������� ����� ����� �� ����*/
		return NULL;
	for (i = 0; i < strlen(st2); i++)
	{
		flag = 0;
		if (st2[i] == st1[0])/*�� ������� ������ ����� ����� �����*/
		{
			for (j = 1; j < strlen(st1); j++)
			{
				if (st2[i + j] != st1[j]) 
					flag = 1;
			}
			if (flag==0) /*�� ����*/
			{
				i = i + strlen(st1)-1;
				continue;
			}
		}
		zamni[counter++] = st2[i];/*����� ���*/
	}
	zamni[counter] = '\0';/*����� �������*/
	str3 = (char*)malloc((strlen(zamni) + 1) * sizeof(char));/*���� ������ ������*/
	strcpy(str3, zamni);/*����=�� ������� �������*/
	return str3;
}
/**2*/
char *ChangeString(char *str) 
{
	int i,r=0;
	char q = '0';
	char newstr[kavoe],*nrenewstr;
	for (i = 0; ((i <= kavoe)&&(str[i]!='\0')); i++)/*���� �� �� ������*/
	{
		if ((str[i]<='9')&&(str[i]>='1'))/*�� ����*/
		{
			q = str[i];
			while (q!='0')
			{
				newstr[r] = str[i];
				r++;
				q--;
			}
		}
	
		if ((str[i] <= 'z') && (str[i] >= 'a'))/*�� �� ��� ����� �� ����� �������*/
		{
			newstr[r] = '-';
			r++;
			while ((str[i] <= 'z') && (str[i] >= 'a'))
			{
					i++;
			}
			newstr[r] = '*';
			r++;
			i--;
		}
	}
	nrenewstr = (char*)malloc(r + 1);
	for (i = 0; i < r ; i++)/*����� ������� ��������*/
	{
		nrenewstr[i] = newstr[i];
	}
	nrenewstr[i] = '\0';
return nrenewstr;
}
/*3*/
void Build1DArray(int** arr, int* count) {
	int i;
	printf("plese enter the size of the arr you want \n");
	scanf("%d", count);
	*arr = (int*)malloc(sizeof(int)*(*count)+1);
	for (i = 0; i < *count; i++)
	{
		printf("Enter the num you want  in the place %d  : ",i+1);
		scanf("%d", (*arr + i));
	}

}
void Print1DArray(int** arr, int size) {
	int i;
	printf("{");
	if (arr != NULL)/*�� ����� ��� ����� �� �� */
	{
		for (i = 0; i < size; i++) {
			printf("%d ", arr[i]);
		}
	}
	printf("}\n");
}
void Reduce1DArray(int** arr, int *count) {
	int i,k=0, j,sizearrnew =0,*newarr, flag;
	for (i = 0; i < *count; i++)/*����� ���� ���� ��� �� �� ������ ������*/
	{
		flag = 1;
		for (j = i + 1; j < *count; j++) {
			if ((*arr)[i] == (*arr)[j]) /*�� �� ���� ���� ������ �� ���� ���  ����� �� ���� ����� ����*/
			{
				flag = 0;
			}
		}
		if (flag==1)
			sizearrnew++;
	}
	newarr = ((int*)malloc(sizeof(int)*(sizearrnew)));/*����� ���� ������ ��������*/
	for (i = 0; i <= *count; i++)
	{
		flag = 1;
		for (j = i + 1; j < *count; j++)
		{
			if ((*arr)[i] == (*arr)[j])
			{
				flag = 0;
			}
		}
		if (flag == 1) /*�� ��� ����� ����� ���� ����� ����*/
		{
			newarr[k]= (*arr)[i];
			k++;
		}
	j = 0;
	}
	free(*arr);/*����� ����*/
	*arr = newarr;/*���� ����� ����� ����� ���� ���*/
	*count = sizearrnew;/*����� ����� ���  �����*/
}
void Transpose(int*** matrix, int *row, int *column);
/*4*/
void BuildMatrix(int*** matrix, int row, int col) {
	int num = 0,i, j;
	(*matrix) = (int**)malloc(sizeof(int*)*row);
	for (i = 0; i < row; i++) {
		(*matrix)[i] = (int*)malloc(sizeof(int)*col);
		for (j = 0; j < col; j++) 
		{
			printf("plese enter what you want to enter in %d %d place: ", i+1, j+1);
			scanf("%d", &num);
			(*matrix)[i][j] = num;
		}
	}
}
void PrintMatrix(int** matrix, int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d\    ", matrix[i][j]);
		}
		printf("\n");
	}
}
void FreeMatrix(int*** matrix, int row) {
	int k;
	for (k = 0; k < row; k++)
		free((*matrix)[k]);
	free(*matrix);
	*matrix = NULL;
}
void Transpose(int*** matrix, int *row, int *col) {
	int **mistanezamni, i, l;
	mistanezamni = (int**)malloc(sizeof(int*)*(*col));/*������ ���� ����� ���� ����� ����� ������*/
	for (i = 0; i < *col; i++) {
		mistanezamni[i] = (int*)malloc(sizeof(int)*(*row));
		for (l = 0; l < *row; l++)
			mistanezamni[i][l] = (*matrix)[l][i];/*����� ������*/
	}
	free(*matrix, row);/*������ ���*/
	*matrix = mistanezamni;/*����� ���� ����� ��� ���� �����*/
	i = *row;/*����� ��� ������ ��������*/
	*row = *col;
	*col = i;
}
void RemoveColumn(int*** matrix, int row, int* col, int colddelte) 
{
	int i, k,**pp;
	if (colddelte > *col)/*�� ������ �� ����� ������� ������*/
	{
		printf("is not in the size of the matrix\n");
		exit(1);
	}

	for (i = 0; i <= *col; i++)
	{
		for (k = 0; k <= *col; k++)
		{
			if (k == colddelte)/*�� ����� ������ ����� ������ ���� ����*/
				(*matrix)[i][k] = (*matrix)[i][k+1];
			else
				(*matrix)[i][k] = (*matrix)[i][k];
		}
	}/*���� �� ������*/
}