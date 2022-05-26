#include <iostream>
#include <string>
#include "UserInterface.h"
#include "linearList.h"
#include "ListItem.h"

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "1. Add an element to the list." << std::endl;
	std::cout << "2. Remove an element from the list." << std::endl;
	std::cout << "3. Display list on screen." << std::endl;
	std::cout << "4. STOP." << std::endl;
	std::cout << std::endl;
}

int userInput(int numberOfMenu)
{
	int option = 0;
	bool check = true;
	std::string optionInput;
	while (check)
	{
		try
		{
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}
		catch (const std::exception&)
		{
			std::cout << "   Please enter a number!" << std::endl;
			std::cout << std::endl;
			check = true;
		}
		if (check == false && numberOfMenu == MainMenu)
		{
			if (option < 1 || option > NumbOfOptionsMain)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
		else if (check == false && numberOfMenu == SecondMenu)
		{
			if (option < 1 || option > NumbOfOptionsMain)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
		else if (check == false && numberOfMenu == WorkOrExit)
		{
			if (option < 1 || option > TwoCases)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
	}
	return option;
}

void workWithUser(LinearList& linearList, int& head)
{
	int& numbOfItems = linearList.numbOfItems;
	bool work = true; printMainMenu();
	while (work)
	{
		
		std::cout << "   Choice: ";

		switch (userInput(MainMenu))
		{
		case(AddItem):
		{
			caseAddItem(linearList, numbOfItems, head);
			break;
		}
		case(DeleteItem):
		{
			caseDeleteItem(linearList, linearList.numbOfItems, head);
			break;
		}
		case(PrintQueue):
		{
			if (!isEmpty(numbOfItems)) { printList(linearList, numbOfItems); }
			else std::cout << "   List is empty." << std::endl;
			break;
		}
		case 4:
			work = false; break;
		default:
			break;
		}
	}
}

void caseAddItem(LinearList& linearList, int& numbOfItems, int& head)
{
	if (isEmpty(numbOfItems))
	{
		std::cout << "   Enter the item to add." << std::endl;
		int data = userInput(EnterItem);
		addItemIsEmpty(linearList, data, numbOfItems, head);
		std::cout << std::endl;
		std::cout << "   Item added." << std::endl;
		std::cout << std::endl;
	}
	else if (!isFull(numbOfItems))
	{
		std::cout << "  Enter the item to add." << std::endl;
		int currentData = userInput(EnterItem);
		int parent = -5;
		int indexCurrent = FindBigger(linearList, parent, currentData);
		int beforeOrAfter;
		if (indexCurrent == 0)
		{
			beforeOrAfter = 2;
		}
		else
		{
			beforeOrAfter = 1;
		}
		switch (beforeOrAfter)
		{
		case(Before):
		{
			addItemBefore(linearList, parent, indexCurrent, currentData, linearList.numbOfItems, head);
			break;
		}
		case(After):
		{
			addItemAfter(linearList, parent, currentData, linearList.numbOfItems, head);
			break;
		}
		default:
			break;
		}
		std::cout << std::endl;
		std::cout << "   Item added." << std::endl;
		std::cout << std::endl;
	}
	else if (isFull(numbOfItems))
	{
		std::cout << std::endl;
		std::cout << "   The list is full." << std::endl;
		std::cout << std::endl;
	}
}

void caseDeleteItem(LinearList& linearList, int& numbOfItems, int& head)
{
	if (isEmpty(numbOfItems))
	{
		std::cout << "   Nothing to delete." << std::endl;
	}
	std::cout << "   Enter the item to delete." << std::endl;
	int currentData = userInput(EnterItem);
	bool check = true;
	int parent = NULL;
	int current= NULL;
	searchCurrent(linearList, currentData, parent, current, check);
	if (check)
	{
		deleteItem(linearList, parent, current, linearList.numbOfItems, head);
		std::cout << std::endl;
		std::cout << "   Item deleted." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "   There is no such element." << std::endl;
	}
}

bool workOrExit()
{
	std::cout << "   Continue (1) / exit (2)" << std::endl;
	int action = userInput(WorkOrExit);
	switch (action)
	{
	case(Continue):
	{
		return true;
		break;
	}
	case(Exit):
	{
		return false;
		break;
	}
	default:
		break;
	}
}