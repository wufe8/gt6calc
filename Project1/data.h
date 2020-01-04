#pragma once
#ifndef DATA_H
#define DATA_H

#include "base.h"

struct Ing
{
	string name;
}IngList[];

struct Recipe
{
	int id[];
	double number[];
}RecipeList[];

int getIngLen();

#endif //!DATA_H