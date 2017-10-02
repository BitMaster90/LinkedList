#include<stdio.h>
#include<stdlib.h>
#include"Node.h"
#define ListSize 10
int main(void) {
	Node *Root = NULL;
	unsigned int i;
	unsigned int TempLocation;
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
	return 0;
}