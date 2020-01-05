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
		{0},{0},{0},{0},0   //0: example NULL
	},{
		{1,2},{3,4},{2,1},{4,1},25   //1: 2C + TiO2 + 4Cl = TiCl4 (25s)
	},{
		{4,5},{6,7},{1,2},{1,6},10   //2: TiCl4 + 2Mg = Ti + 6MgCl2 (10s)
	},{
		{7,8},{3,5},{6,2},{3.5,1.75},15    //3: 6MgCl2 + 2Na = 3.5Cl + 1.75Mg (15s)
	},{
		{1,2,3,4},{7,3,1,2},{3,1,4,1,5},{6,45,1,2},30
	}
};

u16 getIngLen()
{
	return sizeof(IngList) / sizeof(IngList[0]);  //should be create here, or IngList will send as pointer
}

u16 getRecipeLen()
{
	return sizeof(RecipeList) / sizeof(RecipeList[0]);  //should be create here, or IngList will send as pointer
}