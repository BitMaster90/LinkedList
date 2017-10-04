#include<stdio.h>
#include<stdlib.h>
#include"Node.h"

bool AddToList(Node **Root, unsigned int Value) {
	Node *CurrentNodePointer; 
	if ((*Root) == NULL) {
		*Root = (Node *)malloc(sizeof(Node));
		if ((*Root) == NULL) {
			return false;
		}
		(*Root)->Next = NULL;
		(*Root)->Value = Value;
	}
	else {
		CurrentNodePointer = *Root;
		while (CurrentNodePointer->Next != NULL) {
			CurrentNodePointer = CurrentNodePointer->Next;
		}
		CurrentNodePointer->Next = (Node *)malloc(sizeof(Node));
		if (CurrentNodePointer->Next == NULL) {
			return false;
		}
		CurrentNodePointer->Next->Next = NULL;
		CurrentNodePointer->Next->Value = Value;
	}
	return true;
}

void PrintList(Node **Root) {
	Node *CurrentNodePointer;
	CurrentNodePointer = *Root;
	while (CurrentNodePointer != NULL) {
		printf("%u->", CurrentNodePointer->Value);
		CurrentNodePointer = CurrentNodePointer->Next;
	}
	printf("NULL\n\n");
}

bool RemoveFromList(Node **Root, unsigned int Value) {
	Node *CurrentNodePointer;
	Node *PreviousNodePointer;
	PreviousNodePointer = *Root;
	if (*Root == NULL) {
		return false;
	}
	else if ((*Root)->Value == Value) {
		*Root = (*Root)->Next;
		free(PreviousNodePointer);
		return true;
	}
	CurrentNodePointer = (*Root)->Next;
	while (CurrentNodePointer != NULL) {
		if (CurrentNodePointer->Value == Value) {
			PreviousNodePointer->Next = CurrentNodePointer->Next;
			free(CurrentNodePointer);
			return true;
		}
		PreviousNodePointer = CurrentNodePointer;
		CurrentNodePointer = CurrentNodePointer->Next;
	}
	return false;
}

bool AddToFrontList(Node **Root, unsigned int Value) {
	Node *CurrentNodePointer;
	CurrentNodePointer = (Node *)malloc(sizeof(Node));
	if (CurrentNodePointer == NULL) {
		return false;
	}
	else {
		CurrentNodePointer->Next = *Root;
		CurrentNodePointer->Value = Value;
		*Root = CurrentNodePointer;
		return true;
	}
}

bool RemoveFromLastList(Node **Root, unsigned int *Location) {
	Node *CurrentNodePointer, *PreviousNodePointer;
	CurrentNodePointer = *Root;
	PreviousNodePointer = *Root;
	if (*Root == NULL) {
		return false;
	}
	if ((*Root)->Next == NULL) {
		*Location = (*Root)->Value;
		free(*Root);
		*Root = NULL;
		return true;
	}
	while (CurrentNodePointer->Next != NULL) {
		PreviousNodePointer = CurrentNodePointer;
		CurrentNodePointer = CurrentNodePointer->Next;
	}
	PreviousNodePointer->Next = NULL;
	*Location = CurrentNodePointer->Value;
	free(CurrentNodePointer);
	return true;
}


bool FindDuplicateFromList(Node **Root, unsigned int *Location) {
	Node *CurrentNodePointer;
	Node *NextNodePointer;
	CurrentNodePointer = *Root;
	while (CurrentNodePointer) {
		NextNodePointer = CurrentNodePointer->Next;
		while (NextNodePointer) {
			if (CurrentNodePointer->Value == NextNodePointer->Value) {
				*Location = CurrentNodePointer->Value;
				return true;
			}
			NextNodePointer = NextNodePointer->Next;
		}
		CurrentNodePointer = CurrentNodePointer->Next;
	}
	return false;
}

bool FindDuplicateFromListMaxNum(Node **Root, unsigned int *Location, unsigned int MaxNum) {
	Node *CurrentNodePointer;
	char *CountArray;
	char DupFlag = 0;
	CurrentNodePointer = *Root;
	CountArray = (char *)calloc(MaxNum,sizeof(char));
	if (CountArray == NULL) {
		printf("Exception! Out of Memory \n");
		return false;
	}
	while (CurrentNodePointer) {
		CountArray[CurrentNodePointer->Value]++;
		if (CountArray[CurrentNodePointer->Value] > 1) {
			*Location = CurrentNodePointer->Value;
			DupFlag = 1;
			break;
		}
		CurrentNodePointer = CurrentNodePointer->Next;
	}
	free(CountArray);
	if (DupFlag == 1) {
		return true;
	}
	else {
		return false;
	}
}

unsigned int* FindAllDuplicatesFromList(Node **Root, unsigned int *Count) {
	Node *CurrentNodePointer;
	Node *NextNodePointer;
	unsigned int *ResultArray;
	unsigned int ArrayIndex = 0;
	unsigned int ArraySize = 1;
	char DupFlag = 0;

	ResultArray = (unsigned int *)malloc(sizeof(unsigned int)*ArraySize);
	CurrentNodePointer = *Root;
	while (CurrentNodePointer) {
		NextNodePointer = CurrentNodePointer->Next;
		while (NextNodePointer) {
			if (CurrentNodePointer->Value == NextNodePointer->Value) {
				ResultArray = realloc(ResultArray, sizeof(unsigned int)*ArraySize);
				ResultArray[ArrayIndex] = CurrentNodePointer->Value;
				*Count += 1;
				ArrayIndex++;
				ArraySize++;
				DupFlag = 1;
			}
			NextNodePointer = NextNodePointer->Next;
		}
		CurrentNodePointer = CurrentNodePointer->Next;
	}
	if (DupFlag == 0) {
		return NULL;
	}
	else {
		return ResultArray;
	}
}