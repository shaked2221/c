/* Assignment: 3
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define	kavoe 10

void play();
int new_game(int[][kavoe], int size);/*משחק חדש*/
int insert_all(int arr[kavoe][kavoe]);
int insert(int arr[kavoe][kavoe], int line /* שןרה*/, int amode/* עמודה*/, int length/*אורף צוללת*/, int horison/* אופ'י או אנכי*/);
int check_if_good_place(int arr[kavoe][kavoe], int line /* שןרה*/, int amode/* עמודה*/, int length/*אורף צוללת*/, int horison/* אופ'י או אנכי*/);
int shoot(int[][kavoe], int size, int line, int amode);/*ירי למשחק*/
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
		i--;/*מיקום לפי מה שהמחשב רואה*/
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


int new_game(int arr[][kavoe], int size)/*משחק חדש*/
{
	int i, j;
	for (i = 0; i < kavoe; i++)
		for (j = 0; j < kavoe; j++)
			arr[i][j] = 0;
	return arr;
}

int insert_all(int arr[kavoe][kavoe]) {/*תפריט צוללות גודלן ושליחתן להכנסה בפונקציה*/
	int line, amode, long_submarine, horizontal, i; /*מיקום צוללות*/
	int x;
	/*submarine 5 long*/
	do
	{/*צוללת באורך 5*/
	 /*מיקוםהצוללות על ידי הכנסת אורך רוחב תורה אופקית או אנכית */
		printf("plese enter the place qordinat of 5 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 5;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*פונקציה תקינה עד שהוכח אחרת*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);
	do
	{/*צוללת באורך 4*/
	 /*מיקוםהצוללות על ידי הכנסת אורך רוחב תורה אופקית או אנכית */
		printf("plese enter the place qordinat of 4 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 4;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*פונקציה תקינה עד שהוכח אחרת*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);
	do
	{/*צוללת באורך 3*/
	 /*מיקוםהצוללות על ידי הכנסת אורך רוחב תורה אופקית או אנכית */
		printf("plese enter the place qordinat of 3 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 3;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*פונקציה תקינה עד שהוכח אחרת*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);

	do
	{/*צוללת באורך 3*/
	 /*מיקוםהצוללות על ידי הכנסת אורך רוחב תורה אופקית או אנכית */
		printf("plese enter the place qordinat of 3 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 3;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*פונקציה תקינה עד שהוכח אחרת*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);
	do
	{/*צוללת באורך 2*/
	 /*מיקוםהצוללות על ידי הכנסת אורך רוחב תורה אופקית או אנכית */
		printf("plese enter the place qordinat of 2 long  sub marine by line and then amode\n");
		scanf("%d", &line);
		scanf("%d", &amode);
		long_submarine = 2;
		printf("plese enter 0 for ofki and 1 for anci \n");
		scanf("%d", &horizontal);
		x = 1;/*פונקציה תקינה עד שהוכח אחרת*/
		x = insert(arr, line, amode, long_submarine, horizontal);
	} while (x == 0);


	return 0;
}
int insert(int arr[][kavoe], int line /* שןרה*/, int amode/* עמודה*/, int length/*אורף צוללת*/, int horison/* אופ'י או אנכי*/) {
	int i, x;
	if ((line > 10) || (line<0))
	{/*בודק אם השורות שהוכנו בגודל של המטריצה*/
		printf("eror not the size of the board enter a line agein\n");
		return 0;
	}
	if ((amode > 10) || (amode < 0))
	{
		printf("eror not the size of the board enter a amode agein\n");
		return 0;
	}
	if (((line - 1) + (length) >= 10) || ((amode - 1) + (length) >= 10))/*בדיקה האם אפשר להניח את הצוללת במיקום שהתקבל*/
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
		}/*אם עד לפה בסדר המספרים שנוכנסו תקינים*/
		x = check_if_good_place(arr, line, amode, length, horison);/*לבדוק מיקום אם בסדר ואז לשנות אם אפס להכניס מחדש*/
		if (x == 0)
		{
			printf("the submatine crash or not in good place like the law of the game\n");
			return 0;
		}
		/*שינוי למיקום הצוללת עצמה*/
		if (horison == 1)
		{/*מיקום אנכי*/
			for (i = 0; i < length; i++)
			{
				arr[line - 1][amode - 1] = 2;
				amode++;
			}
		}
		else/*  מיקום אופקי*/
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
/*בדיקה אם אפשר להניח תצוללת*/
int check_if_good_place(int arr[kavoe][kavoe], int line /* שןרה*/, int amode/* עמודה*/, int length/*אורף צוללת*/, int horison/* אופ'י או אנכי*/) {
	int i, j = 0;
	int newline;/*שורה מעך השצוללת מסגרת שלה בדיקה*/
	int newamode;
	line--;/*זה השורה כפי שהמחשב רואה מ 0 -9*/
	amode--;/*כנל*/
	if (horison == 1)/* צוולת אנכית בדיקת מיקום אפשרי אנכי*/
	{
		newline = (line + length + 1);/*שורה מעך השצוללת*/
		newamode = (amode + 1);/*אורך של צוללת פלוס 1*/
		if (newamode == 10)/*כלומר עברה את גבול המערך ך אין צורק לבדוק תמסביב למערך*/
			newamode--;
		if (newline == 10)/*עבר את גבולות המערת=ך אין צורק לבדוק תמסביב למערך*/
			newline--;
		if (line - 1 == -1)/*יציאה מהמערך שהוגדר 10 על 10*/
			line++;
		if (amode - 1 == -1)/*יציאה מהמערך שהוגדר 10 על 10*/
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
		if (horison == 0) /*צוולת אופקית*/
		{
			newline = (line + 1);/*שורה מעך השצוללת*/
			newamode = (amode + length + 1);/*סביב צוללת אנכיצ*/
			if (newamode == 10)/*כלומר עברה את גבול המערך ך אין צורק לבדוק תמסביב למערך*/
				newamode--;
			if (newline == 10)/*עבר את גבולות המערת=ך אין צורק לבדוק תמסביב למערך*/
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
	if (line < 0 || line>9 || amode < 0 || amode>9)/*בדיקת ירה בטווח המטריצה*/
	{
		printf(" \n\neror qordint out of the board\n");
		return -1; /*קורדינטה לא טובה*/
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
		/*לעשות  פה הטבעה*/
		/*ניצחון*/
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
/*פונקציה בדיקת ניצחון*/
int cheak_winnig(int arr[kavoe][kavoe], int size)
{
	int i, j;
	for (i = 0; i < kavoe; i++)/*עובר על כל המערך בשביל לבדוק ם יש עוד צוללות*/
	{/*בדיקת ניצחון*/
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
	{/*בדיקת הדפסה*/
		for (p = 0; p < kavoe; p++) {
			printf("%d ", arr[i][p]);
			if (p == 9)
				printf("\n");
		}
	}
	return 0;
}