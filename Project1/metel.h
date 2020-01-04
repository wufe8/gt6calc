#pragma once
#ifndef SRC_H
#define SRC_H

#include "base.h"
#include "using.h"

#include "data.h"

class metel
{
protected:
	struct IngData
	{
		Ing* pos;        //the pointer to Any Ing struct
		u16 len;         //the len of pos->"struct"
		u16 id;          //pos->"struct"[id]
	}IngAbout;
	struct RecipeData
	{
		Recipe* pos;    //the point to Any Recipe struct
		u16 len;        //the len of rpos->"struct"
		u16 id;         //pos->"struct"[rid]
	}RecipeAbout;
	u16 writed;     //had item id
	u16 writedType;  //had in/out item
	f32 icount[4];         //number the inneed item
	f32 ocount[4];          //number the geting item

public:
	void calc(u16 HadIng);
	metel();
	void GetRecipeID(u16 RecipeID);
	u8 GetHadIng(u16 IngSID, u16 IngNumber);
	void ShowRecIng();
	void ShowIng();
	void ShowRecipe();
};

#endif // !SRC_H
