#include "pch.h"
#include <iostream>

#include "using.h"
#include "bases.h"
#include "AlloyMelt.h"

//class function here

/*
template<typename T,typename P>		//doesnt work ,of cause
void listOutput(const T* const getList[].target,u16 idOp,u16 idEd)
{
	cout << "-----------------------------" << endl;
	for (u16 i = idOp; i < idEd; i++)
	{
		cout << i << ":" << getList[i]-> target  << endl;
	}
	cout << "-----------------------------" << endl;
}
*/

heatCalc::heatCalc(void)
{
	cout << "data has been connect" << endl;
	pChamber = ChamberList;
	pCrucible = CrucibleList;
	pItem = ItemList;
	ChamberLen = Get_ChamberList_Len();
	CrucibleLen = Get_CrucibleList_Len();
	ItemLen = Get_ItemList_Len();
	ChamberValue = 0, CrucibleValue = 0, ItemValue[0] = 0;
	ItemCount = 1;
	countIn = 0, totalCount = 0;
	Q = 0, Q0 = 0;
	m = 0, T = 0;
	Power = 0, Power0 = 0, eta = 0, time = 0;
}

heatCalc::~heatCalc(void)
{
	cout << "process done! ending program..." << endl;
}

void heatCalc::ShowChamber()
{
	u16 idOp = 1;
	u16 idEd = sizeof(pChamber);
	cout << "------------------Chamber_List-------------------" << endl;
	for (u16 i = idOp; i < idEd; i++)
	{
		cout << i << ":" << pChamber[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void heatCalc::ShowCrucible()
{
	u16 idOp = 1;
	u16 idEd = sizeof(pCrucible);
	cout << "-----------------Crucibl_List--------------------" << endl;
	for (u16 i = idOp; i < idEd; i++)
	{
		cout << i << ":" << pCrucible[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void heatCalc::ShowItem()
{
	u16 idOp = 1;
	u16 idEd = sizeof(pItem);
	cout << "------------------Item_List----------------------" << endl;
	for (u16 i = idOp; i < idEd; i++)
	{
		cout << i << ":" << pItem[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void heatCalc::getChamber()
{
	u16 buffer;
	u16 idOp = 1;
	u16 idEd = sizeof(pChamber);
	do
	{
		cin >> buffer;
		if (buffer < idOp - 1 || buffer > idEd)
		{
			cout << "wrong number! prass again!" << endl;
		}
		else if (buffer == idOp - 1)
		{
			ShowChamber();
		}
	} while (buffer < 1 || buffer > idEd);
	ChamberValue = buffer;
}

void heatCalc::getCrucible()
{
	u16 buffer;
	u16 idEd = sizeof(pCrucible);
	do
	{
		cin >> buffer;
		if (buffer < 0 || buffer > idEd)
		{
			cout << "wrong number! prass again!" << endl;
		}
		else if (buffer == 0)
		{
			ShowCrucible();
		}
	} while (buffer < 1 || buffer > idEd);
	CrucibleValue = buffer;
}

u16 heatCalc::getItem()
{
	u16 buffer;
	u16 idEd = sizeof(pItem);
	do
	{
		cout << "Enter the" << ItemCount 
			<< "item id:(if u dont know press 0 and switch bit by press -1)" << endl;
		cin >> buffer;
		if (buffer < 1 || buffer > idEd)
		{
			ItemValue[ItemCount] = 0;
			cout << "Then enter the id:__";
		}
		else if (buffer == 0)
		{
			ShowItem();
		}
		else if (buffer == -1)
		{
			cout << "switch to:__";
			u16 *change = new u16;    //manual
			cin >> *change;
			reWriteItem(*change);
			delete change;
		}
	} while (buffer < 1 || buffer > idEd);
	ItemValue[ItemCount] = buffer;
	ItemCount++;
	return ItemCount;
}

void heatCalc::bufferOutput(u16 level)    //level 0:about,1:detail
{
	switch (level)   //high to low and didnt break for detail to about
	{
	case 1:
		cout << "Chamber:" << pChamber[ChamberValue].ingredient;
	}
}