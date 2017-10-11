#include<stdio.h>
#include<stdlib.h>
#include"Node.h"
#define ListSize 10
int main(void) {
	Node *Root = NULL;
	unsigned int i;
	unsigned int TempLocation;
    unsigned int Count = 0;
	unsigned int *DuplicatesArray;

	for (i = 0; i < ListSize; i++) {
		if ((AddToFrontList(&Root, i)) == false) {
			printf("Memory alloction failed. Terminate ! \n");
			return 1;
		}
	}
	PrintList(&Root);
	for (i = 0; i < ListSize; i++) {
		RemoveFromLastList(&Root, &TempLocation);
		printf("Value obtained from last node is %u \n", TempLocation);
		PrintList(&Root);
	}

	AddToList(&Root, 1);
	AddToList(&Root, 4);
	AddToList(&Root, 3);
	AddToList(&Root, 2);
	AddToList(&Root, 4);
	AddToList(&Root, 5);
	printf("New List is : \n");
	PrintList(&Root);

	if (FindDuplicateFromList(&Root, &TempLocation) == true) {
		printf("Duplicate Found. Value is %u \n", TempLocation);
		RemoveFromList(&Root, TempLocation);
		PrintList(&Root);
	}
	else {
		printf("No duplicate found ! \n");
	}
	AddToList(&Root, 6);
	AddToList(&Root, 7);
	AddToList(&Root, 8);
	AddToList(&Root, 9);
	AddToList(&Root, 1);
	printf("New List is : \n");
	PrintList(&Root);
	if (FindDuplicateFromListMaxNum(&Root, &TempLocation, 9) == true) {
		printf("Duplicate Found. Value is %u \n", TempLocation);
		RemoveFromList(&Root, TempLocation);
		PrintList(&Root);
	}
	else {
		printf("No duplicate found ! \n");
	}
	AddToList(&Root, 3);
	AddToList(&Root, 5);
	AddToList(&Root, 12);
	AddToList(&Root, 1);
	printf("New List is : \n");
	PrintList(&Root);
	DuplicatesArray = FindAllDuplicatesFromList(&Root, &Count);
	if (DuplicatesArray == NULL) {
		printf("No Duplicates Found \n");
	}
	else {
		for (i = 0; i < Count; i++) {
			printf("Duplicate is %u \n", DuplicatesArray[i]);
			RemoveFromList(&Root, DuplicatesArray[i]);
		}
		PrintList(&Root);
	}
	for (i = 0; i < 10; i++) {
		RemoveFromLastList(&Root, &TempLocation);
	}
	AddToList(&Root, 5);
	AddToList(&Root, 4);
	AddToList(&Root, 2);
	AddToList(&Root, 1);
	AddToList(&Root, 3);
	printf("Before Sorting the List is \n");
	PrintList(&Root);
	SortList(&Root);
	printf("After sorting the list is \n");
	PrintList(&Root);
	for (i = 0; i < 5; i++) {
		RemoveFromLastList(&Root, &TempLocation);
	}
	AddToList(&Root, 5);
	AddToList(&Root, 4);
	AddToList(&Root, 3);
	AddToList(&Root, 1);
	AddToList(&Root, 2);
	AddToList(&Root, 7);
	printf("Before swapping, the list is : \n");
	PrintList(&Root);
	SwapNodesInListOpt(&Root, 2 , 7);
	printf("After swapping, the list is : \n");
	PrintList(&Root);
	return 0;
}