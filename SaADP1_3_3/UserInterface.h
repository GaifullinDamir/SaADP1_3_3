#pragma once
#include "linearList.h"
#include "ListItem.h"
enum userInterface
{
	MainMenu = 0,
	SecondMenu = 1,
	EnterItem = -1,
	NumbOfOptionsMain = 3,
	NumbOfOptionsSecond = 2,
	WorkOrExit = 1,
	AddItem = 1,
	DeleteItem,
	PrintQueue,
	BeforeOrAfterInput = 1,
	Before = 1,
	After = 2,
	TwoCases = 2,
	Continue = 1,
	Exit = 2
};

void printMainMenu();

int userInput(int numberOfMenu);

void workWithUser(LinearList& linearList);

void caseAddItem(ListItem* list, int& numbOfItems);

//void caseDeleteItem(int* list, int& numbOfItems);

bool workOrExit(); 


