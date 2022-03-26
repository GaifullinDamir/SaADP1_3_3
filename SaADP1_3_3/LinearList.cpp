#include <iostream>
#include "LinearList.h"
#include "ListItem.h"

void init(LinearList& linearList)
{
	linearList.list[0].next = NULL;
	for (int i = 1; i < ArraySize; i++)
	{
		linearList.list[i].next = -1;
	}
	linearList.numbOfItems = 0;
}
bool isEmpty(int numbOfItems) { return numbOfItems == 0; }
bool isFull(int numbOfItems) { return numbOfItems == ArraySize; }
void searchAfter(ListItem* list, int data, int index, bool& check)
{
	int current = list[0].next;
	while (current != -1)
	{
		if (list[current].data == data) 
		{ 
			check = true;
			index = current;
			break; 
		}
		else check = false;
		current = list[current].next;
	}
}

void searchBefore(ListItem* list, int data, int indexBefore, int indexCurrent)
{
	int current = list[0].next;
	int currentBefore = current;
	while (current != -1)
	{
		if (list[current].data == data) 
		{ 
			indexBefore = currentBefore; 
			indexCurrent = current;
			break; 
		}
		currentBefore = current;
		current = list[current].next;
	}
}

void addItemIsEmpty(ListItem* list, int data, int& numbOfItems)
{
	list[1].data = data;
	list[0].next = 1;
	numbOfItems++;
}

void addItemBefore(ListItem* list, int indexBefore, int indexCurrent, int data, int& numbOfItems)
{
	int indexEmpty = -2;
	bool check = true;
	searchAfter(list, -1, indexEmpty, check);
	list[indexEmpty].next = indexCurrent;
	list[indexBefore].next = indexEmpty;
	list[indexEmpty].data = data;
}

void addItemAfter(ListItem* list, int indexCurrent, int data, int& numbOfItems)
{
	int indexEmpty = -2;
	bool check = true;
	searchAfter(list, -1, indexEmpty, check);
	list[indexEmpty].next = list[indexCurrent].next;
	list[indexCurrent].next = indexEmpty;
	list[indexEmpty].data = data;
	numbOfItems++;

}