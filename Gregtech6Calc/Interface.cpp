#include "pch.h"
#include "Interface.h"

void Interface::ShowChamber()        //output the id list
{
	cout << "------------------Chamber_List-------------------" << endl;
	for (u16 i = 1; i <= ChamberAbout.len; i++)
	{
		cout << i << ": " << ChamberAbout.pos[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void Interface::ShowCrucible()        //output the id list
{
	cout << "-----------------Crucible_List--------------------" << endl;
	for (u16 i = 1; i <= CrucibleAbout.len; i++)
	{
		cout << i << ": " << CrucibleAbout.pos[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

void Interface::ShowItem()        //output the id list
{
	cout << "------------------Item_List----------------------" << endl;
	for (u16 i = 1; i <= ItemAbout.len; i++)
	{
		cout << i << ": " << ItemAbout.pos[i].ingredient << endl;
	}
	cout << "-------------------------------------------------" << endl;
}


void Interface::IChamber()      //get chamber id and level
{
	receive = 0;
	u16 id;
	do
	{
		cout << "Enter the chamber id: (if u dont know, press 0)" << endl;
		cin >> id;            //get chamber id
		if (id < 0 || id > ChamberAbout.len)
		{
			//cout << "wrong number! prass again!" << endl;
			receive = 300;
			tr();
		}
		else if (id == 0)
		{
			receive = 201;        //200: show chamber id list
			tr();
		}
	} while (id < 1 || id > ChamberAbout.len);
	ChamberAbout.id = id;
	cout << "Is dense chamber?(0 or 1)" << endl;
	cin >> ChamberAbout.dense;
}

void Interface::ICrucible()        //get crucible id and size
{
	u16 id;
	do
	{
		receive = 0;
		cout << "Enter the crucible id: (if u dont know, press 0)" << endl;
		cin >> id;
		if (id < 0 || id > CrucibleAbout.len)
		{
			//cout << "wrong number! prass again!" << endl;
			receive = 301;
			tr();
		}
		else if (id == 0)
		{
			receive = 202;     //201: show crucible id list
			tr();
		}
	} while (id < 1 || id > CrucibleAbout.len);
	CrucibleAbout.id = id;
	u8* baseType = new u8;
	cout << "Is mega crucible?" << endl;      //receive the crucible size
	cin >> *baseType;
	if (*baseType)
	{
		CrucibleAbout.inBaseSize = 432;
	}
	delete baseType;
}

u16 Interface::IItem()
{
	receive = 0;
	u16 id = 0, n = 0, pos = 0, mode = 0;
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
		u8 ask;
		cout << "Are you sure to end typing?" << endl;
		cin >> ask;
		if (ask)
		{
			mode = 3;
		}
		else      //not sure, break
		{
			cout << "Recalling..." << endl;
			receive = 100;
		}
	}   //end if
	if (id != 0 && mode != 3 && receive == 0)
	{
		cout << "How many would u want? (Press 0 cancel)" << endl;
		cin >> n;
	}
	this->getItem(id, n, pos, mode);
	tr();
	return receive;
}

void Interface::ITempture()
{
	do
	{
		cout << "Enter target tamperture(base in 286k"
			<< ",max tamp in " << CrucibleAbout.pos[CrucibleAbout.id].explore << "): ";
		cin >> T;
		if (T >= CrucibleAbout.pos[CrucibleAbout.id].explore)    //if the target tempture higher the explore point, reject T
		{
			cout << "Error:The crucible will be explore in "
				<< CrucibleAbout.pos[CrucibleAbout.id].explore << "k!" << endl;
		}
	} while (T >= CrucibleAbout.pos[CrucibleAbout.id].explore);
	T -= 286; //GT6草原标况 286k (现实:T(k 开尔文)=T(c 摄氏度)+273.15k)
}

void Interface::tr()
{
	switch (receive)
	{
	case 0:
		break;
	case 100:
		break;
	case 101:
		cout << endl << "Ending typing..." << endl;
		break;
	case 102:
		cout << endl << "Attention: the crucible is full in phyical (" << CrucibleAbout.inBaseSize << " unit)" << endl;
		break;
	case 103:
		cout << endl << "Attention: the crucible is actually full (" << CrucibleAbout.inBaseSize + 48 << " unit)" << endl;
		break;
	case 104:
		cout << endl << "Attention: the crucible has 16 type of item now" << endl;
		break;
	case 200:
		break;
	case 201:
		ShowChamber();
		break;
	case 202:
		ShowCrucible();
		break;
	case 203:
		ShowItem();
		break;
	case 300:
		break;
	case 301:
		cout << "invalue position!" << endl;
		break;
	case 302:
		cout << "wrong id, press again!" << endl;
		break;
	case 303:
		cout << endl << "Error: wrong number, please enter again" << endl;
		break;
	case 304:
		break;
	default:
		cout << "wrong receive! plz check the code!";
	}
}
void Interface::ODetail(u8 level)    //level 0:about, 1:detail
{
	m = 0;
	if (CrucibleAbout.inBaseSize == 16)     //if mega crucible, the crucible weight is not include
	{
		m += CrucibleAbout.pos[CrucibleAbout.id].weight;
	}
	for (u8 i = 0; i < ItemAbout.kind; i++)     //clac m
	{
		m += ItemAbout.pos[*(ItemAbout.id + i)].weight * ItemAbout.count[i];
		//cout << endl << "#_DEBUG_MODE_# m = " << m << "kg ItemAbout.pos[*(ItemAbout.value + i)].weight = " << ItemAbout.pos[*(ItemAbout.value + i)].weight
		//	<< "kg ItemAbout.count[i] = " << ItemAbout.count[i] << endl;
	}
	switch (level)   //high->low and didnt use break for detail->about
	{
	case 1:
		cout << "Chamber: " << ChamberAbout.pos[ChamberAbout.id].ingredient
			<< ", Crucible: " << CrucibleAbout.pos[CrucibleAbout.id].ingredient << endl;
		if (ItemAbout.kind > 0)
		{
			cout << "Item inside: " << endl;
			for (u16 i = 0; i < ItemAbout.kind; i++)
			{
				cout << "             " << i + 1 << ": " << ItemAbout.count[i] << " x " << ItemAbout.pos[*(ItemAbout.id + i)].ingredient << endl;
			}
		}
	case 0:
		cout << "now the crucible have " << ItemAbout.total << "/"
			<< CrucibleAbout.inBaseSize << " (" << CrucibleAbout.inBaseSize + 48 << ") unit inside" << endl;
		cout << "now the crucible weight " << m << "kg" << endl;
		break;
	}  //end switch
}

void Interface::OFeature()
{
	heatCalc::CalcFeature();
	cout << endl
		<< "---------------------------------------------" << endl
		<< "m = " << m << "kg, △T = " << T << "k" << endl
		<< "Q = " << Q << "HU" << endl
		<< "Q = " << Q0 << "HU (if η = 100%)" << endl
		<< "η = " << 100 * eta << "%" << endl
		<< "time = " << time << "s(" << time * 20 << "t)" << endl
		<< "Need Coal " << CoalInNeed << "unit" << endl
		<< "----------------------------------------------" << endl;
}