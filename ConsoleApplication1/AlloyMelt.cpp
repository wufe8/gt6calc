#include "pch.h"
#include <iostream>
#include "using.h"
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

heatCalc::heatCalc()
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
	Q = 0, Q0 = 0, CoalInNeed = 0;
	m = 0, T = 0;
	Power = 0, Power0 = 0, eta = 0, time = 0;
	receive = 0;
	//cout << "data has been connect" << endl
	//	<< "Find Chamber: " << ChamberAbout.len << ", Crucible: " << CrucibleAbout.len << ", Item: " << ItemAbout.len << endl;
}

heatCalc::~heatCalc(void)
{
	//cout << "process done! ending program..." << endl;
}


u16 heatCalc::getItem(u16 id, u16 n, u16 pos, u16 mode)        //get each item id and number, mode 0:setup, 1:setup in which, 2:back to past point 3:end typing
{
	receive = 0;    //0** pass, 1** reject, 2** out put, 3** error
	//0: pass,can be next,100: end,101: full,102: whole full,103: overtype, 202: show item id list, 300: invalue position, 301: wrong id,302: wrong number, 303: wrong mode
	if (pos > ItemAbout.kind || pos < 0)
	{
		//cout << "invalue position!" << endl;
		receive = 301;
		return receive;     //didnt do anything if setup the unsigned point
	}
	if (id < 0 || id > ItemAbout.len && mode != 3)
	{
		//cout << "wrong id, press again!" << endl;
		receive = 302;
		return receive;     //didnt do anything if setup the unsigned point
	}
	else if (id == 0)
	{
		receive = 203;    //get id list
		return receive;
	}
	if (n > 0)       //detect n wheather invalue
	{
		if (ItemAbout.total + n >= CrucibleAbout.inBaseSize && ItemAbout.total + n < CrucibleAbout.inBaseSize + 48)     //the crucible overweight
		{
			//cout << endl << "Attention: the crucible is full in phyical (" << CrucibleAbout.inBaseSize << " unit)" << endl;
			receive = 102;
		}
		else if (ItemAbout.total + n >= CrucibleAbout.inBaseSize + 48)      //the crucible cant get item any more
		{
			//cout << endl << "Attention: the crucible is actually full (" << CrucibleAbout.inBaseSize + 48 << " unit)" << endl;
			n = CrucibleAbout.inBaseSize + 48 - ItemAbout.total;   //the crucible cant get more then 64 unit, clear overpart
			receive = 103;
		} //end if
	}
	else if (mode != 3)  //receve the Error when enter a wrong number above end typed
	{
		//cout << endl << "Error: wrong number, please enter again" << endl;
		receive = 303;
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
		//cout << "Ending typing..." << endl;
		receive = 101;
		return receive;     //end typing
	default:
		//cout << "invalue mode!" << endl;
		receive = 304;
		return receive;    //didnt do anything 
	}    //end switch
	return receive;
}
void heatCalc::setTempture(f32 tempture)
{
	T = tempture - 283;
}
void heatCalc::CalcDetail()    //level 0:about, 1:detail
{
	m = 0;
	if (CrucibleAbout.inBaseSize == 16)     //if mega crucible, the crucible weight is not include
	{
		m = CrucibleAbout.pos[CrucibleAbout.value].weight;
	}
	for (u8 i = 0; i < ItemAbout.kind; i++)     //clac m
	{
		m += ItemAbout.pos[*(ItemAbout.value + i)].weight * ItemAbout.count[i];
	}
}
void heatCalc::CalcFeature()
{
	eta = ChamberAbout.pos[ChamberAbout.value].effectiveness;
	Power0 = ChamberAbout.pos[ChamberAbout.value].HUoutput;
	Q0 = T * m / 100;
	Q = Q0 / eta;
	CoalInNeed = Q / 40000;
	Power = Power0 / eta;
	time = Q0 / Power0;
	time /= 20;  //tick to second
	//if got any 0 or inf, plz check wheather writed all inmformation
}