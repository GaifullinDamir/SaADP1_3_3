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
int searchAfter(ListItem* list, int data, bool& check);
void searchBefore(ListItem* list, int data, int indexBefore, int indexCurrent);
void addItemIsEmpty(ListItem* list, int data, int& numbOfItems);
void addItemBefore(ListItem* list, int indexBefore, int indexCurrent, int data, int& numbOfItems);
void addItemAfter(ListItem* list, int indexCurrent, int data, int& numbOfItems);
void deleteItem(ListItem* list, int index, int& numbOfItems);
void printList(ListItem* list, int numbOfItems);