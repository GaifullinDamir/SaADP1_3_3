#pragma once
#include "ListItem.h"
enum listItem
{
	ArraySize = 10
};
struct LinearList
{
	ListItem list[ArraySize];
	int numbOfItems = 1;
};

void init(LinearList& linearList, int& head);

bool isEmpty(int numbOfItems);
bool isFull(int numbOfItems);

int FindBigger(LinearList& linearList, int& parent, int data);

void searchCurrent(LinearList& linearList, int data, int& parent, int& current, bool& check);
void searchCurrentTail(LinearList& linearList, int data, int& indexBefore, int& indexCurrent);

void addItemIsEmpty(LinearList& linearList, int data, int& numbOfItems, int& head);
void addItemBefore(LinearList& linearList, int parent, int indexCurrent, int data, int& numbOfItems, int& head);
void addItemAfter(LinearList& linearList, int parent, int data, int& numbOfItems, int& head);

void deleteItem(LinearList& linearList, int parent, int current, int& numbOfItems, int& head);

void printList(LinearList& linearList, int numbOfItems);