#include "base.h"
#include "metel.h"

int main()
{
	metel metelAbout;
	u16 getrecipe, getid;
	f32 getnumber;
	bool skip = 0;
	metelAbout.ShowRecipe();
	while (!skip)
	{
		do
		{
			cout << "enter recipe: (enter 0 to exit and " << getRecipeLen() << " to get list): ";
			cin >> getrecipe;
			if (getrecipe > getRecipeLen())
			{
				cout << "wrong!" << endl;
			}
			if (getrecipe == getRecipeLen())
			{
				metelAbout.ShowRecipe();    //get help
			}
			if (getrecipe == 0)    //end
			{
				skip = 1;
			}
		} while (getrecipe >= getRecipeLen() && getrecipe != 0);
		if (skip == 1)
		{
			continue;    //end
		}
		metelAbout.GetRecipeID(getrecipe);
		metelAbout.ShowRecIng();
		u16 getlen = metelAbout.oSIDlen();
		do
		{
			cout << "enter id:";
			cin >> getid;
			if (getid >= getlen)
			{
				cout << "wrong!" << endl;
			}
		} while (getid >= getlen);
		do
		{
			cout << "enter number:";
			cin >> getnumber;
			if (getnumber <= 0)
			{
				cout << "wrong!" << endl;
			}
		} while (getnumber <= 0);
		metelAbout.GetHadIng(getid, getnumber);
		metelAbout.calc();
		metelAbout.oProcess();
	}
	system("pause");
	return 0;
}