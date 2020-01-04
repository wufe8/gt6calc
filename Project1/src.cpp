#include "base.h"
#include "metel.h"

int main()
{
	metel metelAbout;
	u16 getrecipe, getid, getnumber;
	metelAbout.ShowIng();
	metelAbout.ShowRecipe();
	do
	{
		cout << "enter recipe:";
		cin >> getrecipe;
		if (getrecipe >= getRecipeLen())
		{
			cout << "wrong!" << endl;
		}
	} while (getrecipe >= getRecipeLen());
	metelAbout.GetRecipeID(getrecipe);
	metelAbout.ShowRecIng();

	do
	{
		cout << "enter id:";
		cin >> getid;
		if (getid >= 4)
		{
			cout << "wrong!" << endl;
		}
	} while (getid >= 4);
	do
	{
		cout << "enter number:";
		cin >> getnumber;
		if (getnumber <= 0)
		{
			cout << "wrong!" << endl;
		}
	} while (getnumber <= 0);
	cout << "return:" << metelAbout.GetHadIng(getid, getnumber);
	system("pause");
	return 0;
}