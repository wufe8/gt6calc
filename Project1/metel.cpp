#include "metel.h"
#include "pch.h"

metel::metel()
{
	IngAbout.pos = IngList;
	IngAbout.len = getIngLen();
	IngAbout.value[0] = 0;
	IngAbout.Need = 0;
	IngAbout.Get = 0;
	double k[] = {2,1,4,1,     //1: 2C + TiO2 + 4Cl = TiCl4 (25s)
	1,2,1,6,                //2: TiCl4 + 2Mg = Ti + 6MgCl2 (10s)
	6,2,3.5,1.75};         //3: 6MgCl2 + 2Na = 3.5Cl + 1.75Mg (15s)     TODO: isolation these in future
	Precent[0] = 0;
	for (int i = 0;i<12;i++)
	{
		Precent[i] = k[i];
	}
	cout << "class metel has been create!" << endl     //test and debug
		<< "get IngList len:" << IngAbout.len << endl;
}

void metel::outList()
{
	cout << "-----------------item list------------------" << endl;
	for (int i = 1; i < IngAbout.len; i++)     //cout the list, start at 1 to skip id 0: "NULL"
	{
		cout << i << ": " << IngAbout.pos[i].name << endl;
	}
	cout << "--------------------------------------------" << endl;
}