#pragma once
#include "ListItem.h"
enum listItem
{
	ArraySize = 9
};
struct LinearList
{
	ListItem list[ArraySize];
	int numbOfItems;
};

void init(LinearList& linearList);
bool isEmpty(int numbOfItems);
bool isFull(int numbOfItems);
int search(ListItem* list, int data, bool& check);
void addItemIsEmpty(ListItem* list, int data, int& numbOfItems);
void addItem(ListItem* list, int data, int& numbOfItems);
void deleteItem(ListItem* list, int index, int& numbOfItems);
void printList(ListItem* list, int numbOfItems);