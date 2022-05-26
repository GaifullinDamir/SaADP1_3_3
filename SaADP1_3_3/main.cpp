#include <iostream>
#include "ListItem.h"
#include "LinearList.h"
#include "UserInterface.h"

int main()
{
	LinearList linearList;
	int head;
	init(linearList, head);
	workWithUser(linearList, head);
}
