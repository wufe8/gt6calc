#include "pch.h"

#include "using.h"
#include "bases.h"
#include "AlloyMelt.h"
#include "Interface.h"

//main function here

void alloy();
void Csteel();
void SimpleHeat();

int main()
{
	u16 getValue;
	ShowMemu();
	do
	{
		cout << "Enter: ";
		cin >> getValue;
		switch (getValue)
		{
		case 0:
			ShowMemu();
			break;
		case 1:
			alloy();
			break;
		case 2:
			Csteel();
			break;
		case 3:
		{
			SimpleHeat();
			break;
		}
		case 4:
		{
			Interface heatAbout;
			heatAbout.ICrucible();
			heatAbout.ODetail(1);
			u16 getID = 0, getN = 0, getPos = 0, getMod = 0;
			u8 getSign = 0;
			do
			{
				getSign = heatAbout.IItem();
				heatAbout.ODetail(1);
				//cout << "#_DEBUG_MODE_# Receive = " << getSign << endl;
			} while (getSign / 100 != 1);
			heatAbout.IChamber();
			heatAbout.ITempture();
			heatAbout.ODetail(1);
			heatAbout.OFeature();
			break;
		}
		case 9:
		{
			break;  //end program
		}
		default:
		{
			cout << "indefine number! enter again!" << endl;
		}
		}
		cout << "|-----------PROCESS_COMPLATE---------------|" << endl << endl;
	} while (getValue != 9); //getValue != 9);  //do...while
	return 0;
}


//this program make by Wufe8 这东西是萌新八公主码的 >v<