#include "metel.h"
#include "pch.h"

metel::metel()
{
	IngAbout.pos = IngList;
	IngAbout.len = getIngLen();
	IngAbout.value[0] = 0;
	IngAbout.Need = 0;
	IngAbout.Get = 0;

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