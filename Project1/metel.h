#pragma once
#ifndef SRC_H
#define SRC_H

#include "base.h"
#include "data.h"

class metel
{
private:
	struct IngData
	{
		Ing* pos;        //the pointer to Any Ing struct
		int len;
		int value[16];    //the number of pos[value]
		int Need;         //buffer of mark the inneed item
		int Get;          //buffer of mark the geting item
	}IngAbout;
	double Precent[12];
public:
	metel();
	void getIng(int a);
	void outList();
};

#endif // !SRC_H
