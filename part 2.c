/* Assignment: 5
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */


#define _CRT_SECURE_NO_WARNINGS 
#define kavoe 80
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct date {
	 int day, month, year;
};

struct student {
	char name[15];     
	struct date birth;     
	int courses;     
	int *grades;
};

int initialize(struct student **pdata);
void check_birthey(struct student *pdata, int size, struct date birthey);
void Free(struct student **pdata, int size);
int print(char* file_name, struct student *pdata, int size);
int main() {
	struct date birthey;/*הכרזת מבנים*/
	struct student* students;
	int size;
	char filename[80];
	int count;

	size = initialize(&students);/*אתחול מערך*/
	printf("plese enter the date: day, month that you want to check who have birthey\n");
	scanf("%d%d", &birthey.day, &birthey.month);
	check_birthey(students, size, birthey);
	printf("enter the name of file you want open\n");
	scanf("%s", filename);/*קבלת שם של קובץ לפתיחה*/
	count=print(filename, students, size);
	printf("the amount of people who get to the file is %d\n", count);
	Free(&students, size);/*שיחרור כל המערכים הדינמים*/

	return 0;
}

int initialize(struct student **pdata) {
	int size, i,k;
	printf("Please enter The size of the array of the students:\t");
	scanf("%d", &size);
	*pdata = (struct student*)malloc(sizeof(struct student)*(size));/*יציראת נערכים בגודל כמות הסטודנטים*/
	for (i = 0; i < (size); i++) 
	{/*הכנסת השמות ותאריכי לידי*/
		printf(" plese enter the name of the %d student\n",i+1);
		scanf("%s", (*pdata + i)->name);
		printf("plese enter the birthday of the student day month year \n");
		scanf("%d%d%d", &*((pdata + i).birth.day), &((*pdata + i)->birth.month), &((*pdata + i)->birth.year));
		printf("plese enter the number of course that he take\n");
		scanf("%d", &((*pdata + i)->courses));/*הכנסת כמות קורסים שהוא לוקח*/
		(*pdata + i)->grades = (int*)malloc(sizeof(int)*((*pdata + i)->courses));
		for (k = 0; k < (*pdata + i)->courses; k++)/*הכנסת הציונים*/
		{
			printf("plese enter the %d grade\n", k+1);
			scanf("%d", &((*pdata + i)->grades[k]));
		}
	}
	return size;
}
void check_birthey(struct student *pdata, int size, struct date birthey) {
	int i,flag =1;
	for(i=0;i<size;i++)
	{
		if ((pdata[i].birth.day == birthey.day) && (pdata[i].birth.month == birthey.month))/*אם התאריך תואם לתאריך שהוכנס*/
		{
			flag = 0;
			printf("%s his birthey today ", pdata[i].name);
			printf("he is %d old\n ", (2017-(pdata[i].birth.year)));/*השנה פחות השנה שנולד נותן את גילו*/
		}
	}
	if (flag = 1)
		printf("no one have birtheytoday\n ");
}
void Free(struct student **pdata, int size) {
	int i;
	for (i = 0; i < size; i++) {
		free((*pdata + i)->grades);
	}
	free(*pdata);
}
int print(char* file_name, struct student *pdata, int size) {
	FILE *textfile;
	int i, count = 0;
	textfile = fopen(file_name, "w");
	if (textfile == NULL)
		return -1;
	for (i = 0; i < size; i++) /*מדפיס את האנשים לקובץ טקסט לעשות את המצטינים*/
	{
		fprintf(textfile, "%s\n", pdata[i].name);
		count++;
	}
	fclose(textfile);
	return count;/*כמות האנשים שהודפסו למערך*/
}