#pragma once
#ifndef DATA_H
#define DATA_H

#include "base.h"
#include "using.h"

struct Ing
{
	string name;
}IngList[];

struct Recipe
{
	u16 iid[4];          //input item id
	u16 oid[4];          //output item id
	f32 inumber[4];   //input item number
	f32 onumber[4];   //output item number
	f32 time;
}RecipeList[];

u16 getIngLen();
u16 getRecipeLen();

#endif //!DATA_H