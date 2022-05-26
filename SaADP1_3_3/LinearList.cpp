#include <iostream>
#include "LinearList.h"
#include "ListItem.h"

void init(LinearList& linearList, int& head)
{
	linearList.list[0].data = -1;
	linearList.list[0].next = 0;
	head = 1;
	for (int i = 1; i < ArraySize; i++)
	{
		if (i == ArraySize - 1)
		{
			linearList.list[i].next = 0;
		}
		else
		{
			linearList.list[i].next = i + 1;
		}
	}
	linearList.numbOfItems = 1;
}

bool isEmpty(int numbOfItems) { return numbOfItems - 1 == 0; }

bool isFull(int numbOfItems) { return numbOfItems == ArraySize; }

int FindBigger(LinearList& linearList, int& parent, int data)
{
	parent = 0;
	int current = linearList.list[0].next;
	while (current != 0)
	{
		if (linearList.list[current].data >= data)
		{
			return current;
		}
		parent = current;
		current = linearList.list[current].next;
	}
	return current;
}

void searchCurrent(LinearList& linearList, int data, int& parent, int& current, bool& check)
{
	parent = 0;
	current = linearList.list[0].next;
	
	while (current != 0)
	{
		if (linearList.list[current].data == data)
		{ 
			check = true;
			break; 
		}
		else check = false;
		parent = current;
		current = linearList.list[current].next;
	}
}

void searchCurrentTail(LinearList& linearList, int data, int& indexBefore, int& indexCurrent)
{
	int current = linearList.list[0].next;
	int currentBefore = 0;
	while (current != 0)
	{
		if (linearList.list[current].data == data)
		{ 
			indexBefore = currentBefore; 
			indexCurrent = current;
			break; 
		}
		currentBefore = current;
		current = linearList.list[current].next;
	}
}

void addItemIsEmpty(LinearList& linearList, int data, int& numbOfItems, int& head)
{
	int tempI = head;
	head = linearList.list[tempI].next;
	linearList.list[0].next = tempI;
	linearList.list[tempI].data = data;
	linearList.list[tempI].next = 0;
	numbOfItems++;
}

void addItemBefore(LinearList& linearList, int parent, int indexCurrent, int data, int& numbOfItems, int& head)
{
	int indexEmpty = head;
	head = linearList.list[indexEmpty].next;

	linearList.list[parent].next = indexEmpty;
	linearList.list[indexEmpty].next = indexCurrent;
	linearList.list[indexEmpty].data = data;
	numbOfItems++;
}

void addItemAfter(LinearList& linearList, int parent, int data, int& numbOfItems, int& head)
{
	int indexEmpty = head;
	head = linearList.list[indexEmpty].next;
	linearList.list[parent].next = indexEmpty;
	linearList.list[indexEmpty].data = data;
	linearList.list[indexEmpty].next = 0;
	numbOfItems++;
}



void printList(LinearList& linearList, int numbOfItems)
{
	int current = linearList.list[0].next;
	while (current != 0)
	{
		std::cout << "   " << linearList.list[current].data << std::endl;
		current = linearList.list[current].next;
	}
}

void deleteItem(LinearList& linearList, int parent, int current, int& numbOfItems, int& head)
{
	linearList.list[parent].next = linearList.list[current].next;
	linearList.list[current].next = head;
	head = current;
	numbOfItems--;
}