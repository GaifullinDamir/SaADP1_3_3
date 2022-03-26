#include <iostream>
#include "LinearList.h"

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
int search(ListItem* list, int data, bool& check)
{
	int current = list[0].next;
	while (current != -1)
	{
		if (list[current].data == data) { check = true; break; }
		else check = false;
		current = list[current].next;
	}
	return current;
}

void addItemIsEmpty(ListItem* list, int data, int& numbOfItems)
{
	list[1].data = data;
	list[0].next = 1;
	numbOfItems++;
}

void addItem(ListItem* list, int index, int data, int& numbOfItems)
{

}