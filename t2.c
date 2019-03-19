/* Assignment: 3
Campus: Beer Sheva
Author: shaked astemker, ID: 311499917 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define	kavoe 5
#define	kavoe2 10

int devide(int a[], int size, int num);
int main() {
	int i;
	int devider;
	int arr1[kavoe];
	int arr2[kavoe2];
	int x;
	printf("arr 1 grop 1\n");
	printf("plese enter 5 numbers\n");
	for (i = 0; i < kavoe; i++) {/*ful arr grop*/
		scanf("%d", &arr1[i]);
	}
	printf("plese enter a number who will be the dvise of arr 1\n");
	scanf("%d", &devider);/*enter the dviser of them you want*/
	x = devide(arr1, kavoe, devider);/*send to the functia*/
	if (x == -1)/*if the num is 0*/
		printf("eror you enter devider 0 \n");
	else
		printf("the number of num who devide farpcty the dvise is %d\n", x);

	/*arr 2*/
	printf("\n\n arr 2 grop 2\n");
	printf("plese enter 10 numbers\n");
	for (i = 0; i < kavoe2; i++) {/*ful arr grop*/
		scanf("%d", &arr2[i]);
	}
	printf("plese enter a number who will be the dvise of arr 1\n");
	scanf("%d", &devider);/*enter the dviser of them you want*/
	x = devide(arr2, kavoe2, devider);/*send to the functia*/
	if (x == -1)/*if the num is 0*/
		printf("eror you enter devider 0 \n");
	else
		printf("the number of num who devide farpcty the dvise is %d\n", x);
}
devide(int arr[], int size, int devidep){
	int counter = 0;
	int i;
	if (devidep == 0)/*chack if devider is 0*/
		return -1;
	for (i = 0; i < size; i++) {
		if (arr[i] % devidep == 0) {/*check one one number if devide */
			printf("the num %d devide with the devider\n", arr[i]);
			counter++;/*to check how much num devide*/
		}
	}
	return counter;
}