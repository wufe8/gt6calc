#include "pch.h"
#include <iostream>

#include "using.h"
#include "bases.h"
#include "AlloyMelt.h"

//text function about

void ShowMemu()
{
	cout << "|---------List---------|" << endl
		<< "|0.showmemu------------|" << endl
		<< "|1.alloy---------------|" << endl
		<< "|2.Steel---------------|" << endl
		<< "|3.SimpleHeat----------|" << endl
		<< "|4.heat----------------|" << endl
		<< "|9.Exit----------------|" << endl;
}
void ShowAlloy(bool out, bool ask)
{
	if (out)
		cout << "---------------------------------------------------------------------------------" << endl
		<< "7Fe3O4+1.5C -> Fe(r)  in 1811k" << endl
		<< "Fe(r) -> Fe(w)  in 2011k" << endl
		<< "Fe(w)+1/50C -> Fe50C  in 2046k" << endl
		<< "3Cu+Sn -> 4Cu3Sn  in 1367k" << endl
		<< "3Cu+Zn -> 4Cu3Zn  in 1160k" << endl
		<< "2Fe(r)+Ni -> 3Fe2Ni  in 1916k" << endl
		<< "4Fe(w)+3Fe2Ni+Cr+Mn -> 9Fe4(Fe2Ni)CrMn  in 2011k" << endl
		<< "Fe50C+W -> (Fe50C)W  in 2870k" << endl
		<< "Os+Ir -> 2OsIr  in 3012k" << endl
		<< "5Fe50CW+Cr+2Mo+V -> 9((Fe50C)W)5,2CrMo2V  in 2870k" << endl
		<< "6((Fe50C)W)5,2CrMo2V+Co+Mn+Si -> 9(((Fe50C)W)5,2CrMo2V)6,9CoMnSi  in 2314k" << endl
		<< "6((Fe50C)W)5,2CrMo2V+2OsIr+Ir -> 9(((Fe50C)W)5,2CrMo2V)6,9(OsIr)Ir  in 2786k" << endl
		<< "---------------------------------------------------------------------------------" << endl;
	//if (ask); //TODO:anything want to cout
}
void ShowCrucible(bool out, bool ask)
{
	if (out)
		cout << "------------" << endl
		<< "1.Clay" << endl
		<< "2.Steel" << endl
		<< "3.Cr" << endl
		<< "4.Ir" << endl
		<< "5.Carbon" << endl
		<< "------------" << endl;
	if (ask)cout << endl << "Choise kind of crucible :(enter 0 to Show list)" << endl;
}
void ShowChamber(bool out, bool ask)
{
	if (out)
		cout << "---------" << endl
		<< "1.Pb" << endl
		<< "2.Cu3Sn" << endl
		<< "3.Fe50C" << endl
		<< "4.Cr" << endl
		<< "5.Ti" << endl
		<< "6.W" << endl
		<< "---------" << endl;
	if (ask)cout << endl << "what kind of chamber are you using ? (enter 0 to Show list)" << endl;
}
void ShowItemtList(bool out, u16 count)
{
	if (out)
		cout << "-----------------------" << endl
		<< "1.Pure Fe3O4 ore" << endl
		<< "2.carbon bar" << endl
		<< "3.Raw Fe" << endl
		<< "4.Fe" << endl
		<< "5.Steel(Fe50C)" << endl
		<< "6.Pb" << endl
		<< "7.Cu" << endl
		<< "8.Sn" << endl
		<< "9.Cu3Sn" << endl
		<< "10.Zn" << endl
		<< "11.Cu3Zn" << endl
		<< "12.Fe2Ni" << endl
		<< "13.Cr" << endl
		<< "14.Mn" << endl
		<< "15.Stainless Steel" << endl
		<< "16.W" << endl
		<< "17.(Fe50C)W" << endl
		<< "18.Mo" << endl
		<< "19.V" << endl
		<< "20.Co" << endl
		<< "21.Si" << endl
		<< "22.Os" << endl
		<< "23.Ir" << endl
		<< "24.OsIr" << endl
		<< "25.High Speed Steel-G" << endl
		<< "26.High Speed Steel-E" << endl
		<< "27.High Speed Steel-S" << endl
		<< "Other.Nothing Any More" << endl
		<< "-----------------------" << endl;
	if (count)cout << endl << "input the " << count
		<< " item:(enter 0 to Show item list)" << endl;
}