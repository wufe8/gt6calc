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

int getIngLen()
{
	return sizeof(IngList) / sizeof(IngList[0]);  //should be create here, or IngList will send as pointer
}