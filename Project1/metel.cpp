#include "metel.h"
#include "pch.h"

metel::metel()
{
	IngAbout.pos = IngList;
	IngAbout.len = getIngLen();
	RecipeAbout.pos = RecipeList;
	RecipeAbout.len = getRecipeLen();
	icount[0] = 0;
	ocount[0] = 0;
	writed = 0;
	writedType = 0;
	cout << "class metel has been create!" << endl     //test and debug
		<< "get IngList len:" << IngAbout.len << endl
		<< "get RecipeList len:" << RecipeAbout.len << endl;
}

void metel::GetRecipeID(u16 RecipeID)
{
	RecipeAbout.id = RecipeID;
}

u8 metel::GetHadIng(u16 IngSID, u16 IngNumber)         //return 0:sucessed 1:failed
{
	if (IngSID)      //TODO:
	{
		icount[IngSID] = IngNumber;
		writed = IngSID;
		writedType = 0;   //mark input
		return 0;
	}
	for (u8 i = 0; (RecipeAbout.pos + RecipeAbout.id)->oid[i] != 0 && i <= 4; i++)
	{
		if ((RecipeAbout.pos + RecipeAbout.id)->oid[i] == IngSID)
		{
			ocount[i] = IngNumber;
			writed = i;
			writedType = 1;    //mark output
			return 0;
		}
	}
	return 1;
}

void metel::calc(u16 HadIngID)
{
	f32 base;
	if (writedType == 0)    //type 0:input Ing 1:output Ing
	{
		base = icount[writed] / (RecipeAbout.pos + RecipeAbout.id)->inumber[HadIngID];
	}
	else
	{
		base = ocount[writed] / (RecipeAbout.pos + RecipeAbout.id)->onumber[HadIngID];
	}
	cout << "base = " << base << endl;

}

void metel::ShowRecIng()
{
	cout << "-----Recipe internal(" << RecipeAbout.id << ")-----" << endl;
	u8 count = 1;
	for (u8 i = 0; (RecipeAbout.pos + RecipeAbout.id)->iid[i] != 0 && i <= 4; i++, count++)
	{
		cout << count << ":" << (IngAbout.pos + (RecipeAbout.pos + RecipeAbout.id)->iid[i])->name << endl;
	}
	for (u8 i = 0; (RecipeAbout.pos + RecipeAbout.id)->oid[i] != 0 && i <= 4; i++, count++)
	{
		cout << count << ":" << (IngAbout.pos + (RecipeAbout.pos + RecipeAbout.id)->oid[i])->name << endl;
	}
	cout << "----------------------------" << endl;
}

void metel::ShowIng()
{
	cout << "--------item list--------" << endl;
	for (u8 i = 1; i < IngAbout.len; i++)     //cout the list, start at 1 to skip id 0: "NULL"
	{
		cout << i << ": " << (IngAbout.pos + i)->name << endl;
	}
	cout << "-------------------------" << endl;
}
void metel::ShowRecipe()
{
	cout << "----------------------------Recipe List--------------------------" << endl;
	for (u8 i = 1; i < RecipeAbout.len; i++)
	{
		if ((RecipeAbout.pos + i - 1)->oid != 0)
		{
			cout << i << ": ";
			for (u8 a = 0; (RecipeAbout.pos + i)->iid[a] != 0 && a <= 4;a++)
			{
				if ((RecipeAbout.pos + i)->inumber[a] != 1)     //won't cout amount 1
				{
					cout << (RecipeAbout.pos + i)->inumber[a];    //cout number
				}
				cout << (IngAbout.pos + (RecipeAbout.pos + i)->iid[a])->name;
				if ((RecipeAbout.pos + i)->iid[a + 1] != 0)     //detest end
				{
					cout << " + ";    //connect
				}
			}
			cout << " = ";
			for (u8 a = 0; (RecipeAbout.pos + i)->oid[a] != 0 && a <= 4; a++)
			{
				if ((RecipeAbout.pos + i)->onumber[a] != 1)     //won't cout amount 1
				{
					cout << (RecipeAbout.pos + i)->onumber[a];    //cout number
				}
				cout << (IngAbout.pos + (RecipeAbout.pos + i)->oid[a])->name;      //cout id
				if ((RecipeAbout.pos + i)->oid[a + 1] != 0)    //detest end
				{
					cout << " + ";     //connect
				}
			}
			cout << endl;
		}
	}
	cout << "-----------------------------------------------------------------" << endl;
}