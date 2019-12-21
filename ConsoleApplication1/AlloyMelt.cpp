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
	ChamberAbout.pos = ChamberList;
	CrucibleAbout.pos = CrucibleList;
	ItemAbout.pos = ItemList;
	ChamberAbout.len = Get_ChamberList_Len() - 1;
	CrucibleAbout.len = Get_CrucibleList_Len() - 1;
	ItemAbout.len = Get_ItemList_Len() - 1;
	ChamberAbout.value = 0, CrucibleAbout.value = 0, ItemAbout.value[0] = 0;
	CrucibleAbout.inBaseSize = 16;
	ItemAbout.kind = 0;
	ItemAbout.count[0] = 0, ItemAbout.total = 0;
	Q = 0, Q0 = 0;
	m = 0, T = 0;
	Power = 0, Power0 = 0, eta = 0, time = 0;
	cout << "data has been connect" << endl
		<< "Find Chamber: " << ChamberAbout.len << ", Crucible: " << CrucibleAbout.len << ", Item: " << ItemAbout.len << endl;
}

heatCalc::~heatCalc(void)
{
	cout << "process done! ending program..." << endl;
}

void heatCalc::ShowChamber()        //output the id list
{
	cout << "------------------Chamber_List-------------------" << endl;
	for (u16 i = 1; i <= ChamberAbout.len; i++)
	{
		cout << i << ": " << ChamberAbout.pos[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void heatCalc::ShowCrucible()        //output the id list
{
	cout << "-----------------Crucible_List--------------------" << endl;
	for (u16 i = 1; i <= CrucibleAbout.len; i++)
	{
		cout << i << ": " << CrucibleAbout.pos[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void heatCalc::ShowItem()        //output the id list
{
	cout << "------------------Item_List----------------------" << endl;
	for (u16 i = 1; i <= ItemAbout.len; i++)
	{
		cout << i << ": " << ItemAbout.pos[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void heatCalc::getChamber()      //get chamber id and level
{
	u16 id;
	do
	{
		cout << "Enter the chamber id: (if u dont know, press 0)" << endl;
		cin >> id;            //get chamber id
		if (id < 0 || id > ChamberAbout.len)
		{
			cout << "wrong number! prass again!" << endl;
		}
		else if (id == 0)
		{
			ShowChamber();
		}
	} while (id < 1 || id > ChamberAbout.len);
	ChamberAbout.value = id;
	cout << "Is dense chamber?(0 or 1)" << endl;
	u8 dense;
	cin >> dense;
	if (dense == 1)
	{
		Power0 *= 4;
	}
}

void heatCalc::getCrucible()        //get crucible id and size
{
	u16 id;
	do
	{
		cout << "Enter the crucible id: (if u dont know, press 0)" << endl;
		cin >> id;
		if (id < 0 || id > CrucibleAbout.len)
		{
			cout << "wrong number! prass again!" << endl;
		}
		else if (id == 0)
		{
			ShowCrucible();
		}
	} while (id < 1 || id > CrucibleAbout.len);
	CrucibleAbout.value = id;
	u8* baseType = new u8;
	cout << "Is mega crucible?" << endl;      //receive the crucible size
	cin >> *baseType;
	if (*baseType)
	{
		CrucibleAbout.inBaseSize = 432;
	}
}

u16 heatCalc::getItem(u16 id, u16 n, u16 pos, u16 mode)        //get each item id and number, mode 0:setup, 1:setup in which, 2:back to past point 3:end typing
{
	u16 receive = 0;    //0: pass,can be next,1: wrong,need reset or end ,2: error,need reset
	//---------------------------------------------------------------------------------------------
	if (id == 0 && n == 0 && pos == 0 && mode == 0)    //inside item input api
	{
		cout << "Enter the " << ItemAbout.kind + 1 << " id:" << endl
			<< "(get id list press 0, back to past position press " << ItemAbout.len + 1 << ",stop typing press order key)" << endl;
		cin >> id;
		if (id == ItemAbout.len + 1)                  //jump     // id <----------0---------------ItemAbout.len + 1----------->
		{                              				             //     end     idList     id          jump            end
			mode = 1;
			//mode = 2;
			cout << "Enter the position u want to:" << endl;
			cin >> pos;
			cout << "Enter the " << pos << " id:" << endl;
			cin >> id;
			pos--;     //array start at 0, so that -1
		}
		else if (id < 0 || id > ItemAbout.len + 1)   //end
		{
			u8* ask = new u8;   //manual
			cout << "Are you sure to end typing?" << endl;
			cin >> *ask;
			if (*ask)
			{
				mode = 3;
			}
			else      //not sure, break
			{
				cout << "Recalling..." << endl;
				receive = 2;
				return receive;
			}
		}   //end if
		if (id != 0 && mode != 3)
		{
			cout << "How many would u want? (Press 0 cancel)" << endl;
			cin >> n;
		}
	}
	//--------------------------------------------------------------------------------------------------
	if (pos > ItemAbout.kind || pos < 0)
	{
		cout << "invalue position!" << endl;
		receive = 2;
		return receive;     //didnt do anything if setup the unsigned point
	}
	if (id < 0 || id > ItemAbout.len && mode != 3)
	{
		cout << "wrong id, press again!" << endl;
		receive = 2;
		return receive;     //didnt do anything if setup the unsigned point
	}
	else if (id == 0)
	{
		ShowItem();
		receive = 2;
		return receive;
	}
	if (n > 0)       //detect n wheather invalue
	{
		if (ItemAbout.total + n >= CrucibleAbout.inBaseSize && ItemAbout.total + n < CrucibleAbout.inBaseSize + 48)     //the crucible overweight
		{
			cout << endl << "Attention: the crucible is full in phyical (" << CrucibleAbout.inBaseSize << " unit)" << endl;
			receive = 1;
		}
		else if (ItemAbout.total + n >= CrucibleAbout.inBaseSize + 48)      //the crucible cant get item any more
		{
			cout << endl << "Attention: the crucible is actually full (" << CrucibleAbout.inBaseSize + 48 << " unit)" << endl;
			n = CrucibleAbout.inBaseSize + 48 - ItemAbout.total;   //the crucible cant get more then 64 unit, clear overpart
			receive = 1;
		} //end if
	}
	else if (mode != 3)  //receve the Error when enter a wrong number above end type
	{
		cout << endl << "Error: wrong number, please enter again" << endl;
		receive = 2;
		return receive;
	} //end if
	if (ItemAbout.kind >= 16)
	{
		receive = 1;
		return receive;   //over 16
	}
	switch (mode)
	{
	case 0:          //setup and go next
		ItemAbout.value[ItemAbout.kind] = id;
		ItemAbout.count[ItemAbout.kind] = n;
		ItemAbout.total += ItemAbout.count[ItemAbout.kind];
		ItemAbout.kind++;
		break;
	case 1:          //setup specific position and go next
		ItemAbout.total -= ItemAbout.count[pos];
		ItemAbout.value[pos] = id;
		ItemAbout.count[pos] = n;
		ItemAbout.total += ItemAbout.count[pos];
		break;
	case 2:     //setup and jump to specific position
		reWriteItem(pos); 
		ItemAbout.total -= ItemAbout.count[ItemAbout.kind];
		ItemAbout.value[ItemAbout.kind] = id;
		ItemAbout.count[ItemAbout.kind] = n;
		ItemAbout.total += ItemAbout.count[ItemAbout.kind];
		ItemAbout.kind++;
		break;
	case 3:
		cout << "Ending typing..." << endl;
		receive = 1;
		return receive;     //end typing
	default:
		cout << "invalue mode!" << endl;
		receive = 2;
		return receive;    //didnt do anything 
	}    //end switch
	bufferOutput(1);
	return receive;
}
void heatCalc::setTempture()
{
	do
	{
		cout << "Enter target tamperture(base in 286k"
			<< ",max tamp in " << CrucibleAbout.pos[CrucibleAbout.value].explore << "): ";
		cin >> T;
		if (T >= CrucibleAbout.pos[CrucibleAbout.value].explore)    //if the target tempture higher the explore point, reject T
		{
			cout << "Error:The crucible will be explore in "
				<< CrucibleAbout.pos[CrucibleAbout.value].explore << "k!" << endl;
		}
	} while (T >= CrucibleAbout.pos[CrucibleAbout.value].explore);
	T -= 286; //GT6草原标况 286k (现实:T(k 开尔文)=T(c 摄氏度)+273.15k)
}
void heatCalc::bufferOutput(u16 level)    //level 0:about, 1:detail
{
	m = 0;
	if (CrucibleAbout.inBaseSize == 16)     //if mega crucible, the crucible weight is not include
	{
		m = CrucibleAbout.pos[CrucibleAbout.value].weight;
	}
	for (u8 i = 0; i < ItemAbout.kind; i++)     //clac m
	{
		m += ItemAbout.pos[*(ItemAbout.value + i)].weight * ItemAbout.count[i];
		//cout << endl << "#_DEBUG_MODE_# m = " << m << "kg ItemAbout.pos[*(ItemAbout.value + i)].weight = " << ItemAbout.pos[*(ItemAbout.value + i)].weight
		//	<< "kg ItemAbout.count[i] = " << ItemAbout.count[i] << endl;
	}
	switch (level)   //high->low and didnt use break for detail->about
	{
	case 1:
		cout << "Chamber: " << ChamberAbout.pos[ChamberAbout.value].ingredient
			<< ", Crucible: " << CrucibleAbout.pos[CrucibleAbout.value].ingredient << endl;
		if (ItemAbout.kind > 0)
		{
			cout << "Item inside: " << endl;
		}
		for (u16 i = 0; i < ItemAbout.kind; i++)
		{
			cout << "             " << i + 1 << ": " << ItemAbout.count[i] << " x " << ItemAbout.pos[*(ItemAbout.value + i)].ingredient << endl;
		}
	case 0:
		cout << "now the crucible have " << ItemAbout.total << "/"
			<< CrucibleAbout.inBaseSize << " (" << CrucibleAbout.inBaseSize + 48 << ") unit inside" << endl;
		cout << "now the crucible weight " << m << "kg" << endl;
		break;
	}  //end switch
}
void heatCalc::featureOutput()
{
	eta = ChamberAbout.pos[ChamberAbout.value].effectiveness;
	Power0 = ChamberAbout.pos[ChamberAbout.value].HUoutput;
	Q0 = T * m / 100;
	Q = Q0 / eta;
	f32 CoalInNeed = Q / 40000;
	Power = Power0 / eta;
	time = Q0 / Power0;
	time /= 20;  //tick to second
	cout << endl << "---------------------------------------------" << endl
		<< "m = " << m << "kg, △T = " << T << "k" << endl
		<< "Q = " << Q << "HU" << endl
		<< "Q = " << Q0 << "HU (if η = 100%)" << endl
		<< "η = " << 100 * eta << "%" << endl
		<< "time = " << time << "s(" << time * 20 << "t)" << endl
		<< "Need Coal " << CoalInNeed << "unit" << endl
		<< "----------------------------------------------" << endl;
}