#include "pch.h"
#include <iostream>

#include "using.h"
#include "bases.h"
#include "AlloyMelt.h"

void Heat() //need :chamberType,crucibleType,matterType,num,targetTempture,
{
	u16 i;       //'for' count
	bool jump = 0;
	u16 ChamberValue, CrucibleValue, ItemValue;  //xxxValuerid暂存
	f32 n, totaln = 0;     //n=count ,totaln=目前坩埚总unit
	f32 Q = 0, Q0 = 0, m = 0, T = 0;      //Q=actual heat unit(HU), Q0=useful heat unit(HU), m=total matter(kg), T=tamperture(K)  定义:1HU可使100kg物质温度上升1k T=Q0m/100
	f32 Power = 0, Power0 = 0, eta = 0, time = 0; // Power = Power(HU/t) Power0 = useful Power(HU/t) eta = efficiency(%) time(tick/s) eta=P0/P*100% 
	f32 CoalInNeed;
	f32* inBase = new f32;        //坩埚材质
	bool baseType;		//是否大型坩埚
	f32 isBaseSize;
	u16 inM[32];
	CrucibleValue = askReceive(ShowCrucible, 1, 6);	//decide the kind of crucible 录入坩埚数据
	*inBase = CrucibleList[CrucibleValue]->weight;
	m += *inBase;
	cout << "Is mega crucible?" << endl;
	cin >> baseType;
	if (baseType)isBaseSize = 432;
	else isBaseSize = 16;
	delete inBase;
	cout << "now the crucible weight " << m << "kg, " << totaln << "/"
		<< isBaseSize << " (" << isBaseSize + 48 << ") unit inside" << endl;
	ShowItemtList(1, 0);
	for (i = 1; i < 16 && jump == 0; i++)         //input item 录入投入物品数据 start 1 becauce of count
	{
		ItemValue = askReceive(ShowItemtList, 1, 27, i);
		if (ItemValue == 0)	//reload this turn when get list, break turn when get Empty
		{
			cout << "now the crucible have " << totaln << "/"
				<< isBaseSize << " (" << isBaseSize + 48 << ") unit inside" << endl;
			cout << "now the crucible weight " << m << "kg" << endl;
			break;
		}		//empty    full              max
		else	//  0-------16---------------64---->
		{
			inM[i] = ItemValue;
		}
		cout << "how many to input: ";
		cin >> n;        //how many item do it input
		if (n > 0)
		{
			if (totaln + n >= isBaseSize && totaln + n < isBaseSize + 48)     //the crucible overweight
			{
				cout << "Attention: the crucible is full in phyical (" << isBaseSize << " unit)" << endl;
				jump = 1;
			}
			else if (totaln + n >= isBaseSize + 48)      //the crucible cant get item any more
			{
				cout << endl << "Attention: the crucible is actually full (" << isBaseSize + 48 << " unit)" << endl;
				n = 64 - totaln;   //the crucible cant get more then 64 unit, clear overpart
				jump = 1;
			} //end if
			m += ItemList[inM[i]]->weight * n;  //normal case: m总+=m*n
		}
		else  //receve the Error when enter a wrong number
		{
			cout << endl << "Error: wrong number, please enter again" << endl;
			n = 0;  //didnt count when get wrong number
			i--;
		} //end if
		totaln += n;
		cout << "now the crucible have " << totaln << "/"
			<< isBaseSize << " (" << isBaseSize + 48 << ") unit inside" << endl;
		cout << "now the crucible weight " << m << "kg" << endl;
	} //end for
	ChamberValue = askReceive(ShowChamber, 1, 6);	//decide the kind of chamber 录入燃烧室数据
	eta = ChamberList[ChamberValue]->effectiveness;	//燃烧效率
	Power0 = ChamberList[ChamberValue]->HUoutput;		//燃烧功率
	bool dense;
	cout << "Is dense chamber?(0 or 1)" << endl;
	cin >> dense;
	if (dense == 1)Power0 *= 4;
	do
	{
		cout << "Enter target tamperture(base in 286k"
			<< ",max tamp in " << CrucibleList[CrucibleValue]->explore << "): ";
		cin >> T;
		if (T >= CrucibleList[CrucibleValue]->explore)
		{
			cout << endl << "Error:The crucible will be explore in "
				<< CrucibleList[CrucibleValue]->explore << "k!" << endl;
		}
	}while (T >= CrucibleList[CrucibleValue]->explore);
	T -= 286; //GT6草原标况 286k (现实:T(k 开尔文)=T(c 摄氏度)+273.15k)
	Q0 = T * m / 100;
	Q = Q0 / eta;
	CoalInNeed = Q / 40000;
	Power = Power0 / eta;
	time = Q0 / Power0;
	time /= 20;  //tick to second
	cout << "m = " << m << "kg" << endl;
	cout << "Q = " << Q << "HU" << endl;
	cout << "Q = " << Q0 << "HU (if η = 100%)" << endl;
	cout << "η = " << 100 * eta << "%" << endl;
	cout << "t = " << time << "s(" << time * 20 << "t)" << endl;
	cout << "Need Coal " << CoalInNeed << "unit" << endl;
}

u16 askReceive(void (*fnOut)(bool, bool), u16 idOp, u16 idEd)
{
	u16 buffer;
	fnOut(1, 0);
	do
	{
		fnOut(0, 1);
		cin >> buffer;
		if (buffer < idOp - 1 || buffer > idEd)
		{
			cout << "wrong number! prass again!" << endl;
		}
		else if (buffer == idOp - 1)
		{
			fnOut(1, 0);
		}
	} while (buffer < idOp || buffer > idEd);
	return buffer;
}

u16 askReceive(void (*fnOut)(bool, u16), u16 idOp, u16 idEd, u16& count)
{
	u16 buffer;
	do
	{
		fnOut(0, count);
		cin >> buffer;
		if (buffer < idOp - 1 || buffer > idEd)
		{
			return idOp - 1;
		}
		else if (buffer == idOp - 1)
		{
			fnOut(1, 0);
		}
	} while (buffer < idOp || buffer > idEd);
	return buffer;
}
