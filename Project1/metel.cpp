#include "metel.h"
#include "pch.h"

metel::metel()
{
	IngAbout.pos = IngList;
	IngAbout.len = getIngLen();
	RecipeAbout.pos = RecipeList;
	RecipeAbout.len = getRecipeLen();
	countSID[0] = 0;
	SID[0] = 0;
	SIDmagn[0] = 0;
	SIDline = 0;
	SIDlen = 0;
	writedSID = 0;
	cout << "class metel has been create!" << endl     //test and debug
		<< "get IngList len:" << IngAbout.len << endl
		<< "get RecipeList len:" << RecipeAbout.len << endl;
}

void metel::SIDswitch()    //need set up RecipeAbout.idfirst
{
	u8 count = 0;
	for (u8 i = 0; (RecipeAbout.pos + RecipeAbout.id)->iid[i] != 0; i++, count++)
	{
		SID[count] = (RecipeAbout.pos + RecipeAbout.id)->iid[i];
		SIDmagn[count] = (RecipeAbout.pos + RecipeAbout.id)->imagn[i];
	}
	SIDline = count;    //isolution i/o Ing
	for (u8 i = 0; (RecipeAbout.pos + RecipeAbout.id)->oid[i] != 0; i++, count++)
	{
		SID[count] = (RecipeAbout.pos + RecipeAbout.id)->oid[i];
		SIDmagn[count] = (RecipeAbout.pos + RecipeAbout.id)->omagn[i];
	}
	SIDlen = count;    //get signed SIDlen len
	/*
	for (u8 i = 0; i < count; i++)    //DEBUG
	{
		cout << "SID[" << i << "] = " << SID[i] << ", " << SIDmagn[i] << (IngAbout.pos + SID[i])->name << endl;
	}
	*/
}

void metel::GetRecipeID(u16 RecipeID)
{
	RecipeAbout.id = RecipeID;
}

u8 metel::GetHadIng(u16 IngSID, f32 IngNumber)         //return 0:sucessed 1:failed   need run SIDswitch() first
{
	IngSID--;    //backspace
	if (IngSID < SIDlen)    //avoid invalued SID
	{
		countSID[IngSID] = IngNumber;
		writedSID = IngSID;
		return 0;
	}
	else
	{
		return 1;
	}
}

void metel::calc()
{
	f32 base = 0;
	base = countSID[writedSID] / SIDmagn[writedSID];
	for (u8 i = 0; i < SIDlen; i++)
	{
		countSID[i] = base * SIDmagn[i];
	}
}

u16 metel::oSIDlen()
{
	return SIDlen;
}

void metel::oProcess()
{
	//cout << endl << countSID << endl;    //DEBUG
	for (u8 i = 0; i < SIDlen; i++)
	{
		if (countSID[i] != 1)
		{
			cout << countSID[i];    //cout number
		}
		cout << (IngAbout.pos + SID[i])->name;    //cout name
		if (i + 1 != SIDline && i + 1 != SIDlen)
		{
			cout << " + ";   //cout + except end and "="
		}
		else if (i + 1 == SIDline)     //connects
		{
			cout << " = ";
		}
	}
	cout << endl;
}

void metel::ShowRecIng()           //need set up RecipeAbout.id first
{
	SIDswitch();
	cout << "-----Recipe internal(" << RecipeAbout.id << ")-----" << endl
		<< "input:" << endl;
	for (u8 i = 0; i < SIDlen; i++)
	{
		if (i == SIDline)    //isolution i/o Ing
		{
			cout << "output:" << endl;
		}
		cout << "\t" << i + 1 << ":" << (IngAbout.pos + SID[i])->name << endl;    //cout ing name
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
			for (u8 a = 0; (RecipeAbout.pos + i)->iid[a] != 0 && a <= 9;a++)
			{
				if ((RecipeAbout.pos + i)->imagn[a] != 1)     //won't cout amount 1
				{
					cout << (RecipeAbout.pos + i)->imagn[a];    //cout number
				}
				cout << (IngAbout.pos + (RecipeAbout.pos + i)->iid[a])->name;
				if ((RecipeAbout.pos + i)->iid[a + 1] != 0)     //detest end
				{
					cout << " + ";    //connect
				}
			}
			cout << " = ";
			for (u8 a = 0; (RecipeAbout.pos + i)->oid[a] != 0 && a <= 9 ; a++)
			{
				if ((RecipeAbout.pos + i)->omagn[a] != 1)     //won't cout amount 1
				{
					cout << (RecipeAbout.pos + i)->omagn[a];    //cout number
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