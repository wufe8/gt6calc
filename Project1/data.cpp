#include "data.h"
#include "metel.h"
#include "pch.h"

Ing IngList[]
{
	"NULL",
	"C",
	"TiO2",
	"Cl",
	"TiCl4",
	"Mg",
	"Ti",
	"MgCl2",
	"Na"
};

Recipe RecipeList[]
{
	{
	},{
	},{
	},{
	}
}

double k[] = { 2,1,4,1,     //1: 2C + TiO2 + 4Cl = TiCl4 (25s)
1,2,1,6,                //2: TiCl4 + 2Mg = Ti + 6MgCl2 (10s)
6,2,3.5,1.75 };         //3: 6MgCl2 + 2Na = 3.5Cl + 1.75Mg (15s)     TODO: isolation these in future

int getIngLen()
{
	return sizeof(IngList) / sizeof(IngList[0]);  //should be create here, or IngList will send as pointer
}