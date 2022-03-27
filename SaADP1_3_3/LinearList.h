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

int searchEmpty(ListItem* list);
void searchCurrent(ListItem* list, int data, int& index, bool& check);
void searchCurrentTail(ListItem* list, int data, int& indexBefore, int& indexCurrent);

void addItemIsEmpty(ListItem* list, int data, int& numbOfItems);
void addItemBefore(ListItem* list, int indexBefore, int indexCurrent, int data, int& numbOfItems);
void addItemAfter(ListItem* list, int indexCurrent, int data, int& numbOfItems);

void deleteItem(ListItem* list, int indexBefore, int indexCurrent, int& numbOfItems);

void printList(ListItem* list, int numbOfItems);