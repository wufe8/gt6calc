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
	u16 SID[18];         //surface id
	f32 SIDmagn[18];     //Ing magn (SID)
	u16 SIDline;    //isolution i/o SID
	u16 SIDlen;     //SID[] signed len
	u16 writedSID;     //had Ing (SID)
	f32 countSID[18];         //number the Ing (SID)
	f32 time;
	void SIDswitch();
public:
	void calc();
	metel();
	void GetRecipeID(u16 RecipeID);
	u8 GetHadIng(u16 IngSID, f32 IngNumber);
	void ShowRecIng();
	void ShowIng();
	void ShowRecipe();
	u16 oSIDlen();
	void oProcess();
};

#endif // !SRC_H
