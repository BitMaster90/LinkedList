#pragma once
#include<stdbool.h>
#ifndef NODE_H
#define NODE_H
typedef struct Node Node;

struct Node {
	unsigned int Value;
	Node *Next;
};

bool AddToList(Node **, unsigned int);
void PrintList(Node **);
bool RemoveFromList(Node **, unsigned int);
bool AddToFrontList(Node **, unsigned int);
bool RemoveFromLastList(Node **, unsigned int *);

#endif