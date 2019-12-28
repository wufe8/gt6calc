#include"pch.h"

#include "other.h"

void alloy()
{
	ShowAlloy();
}

void Csteel()
{
	u8 q1, q2, q3;
	cout << "Target Carbon(0) or Fe3O4(1) or Steel(2)? ";
	cin >> q1;											   //7Fe3O4+3C->3Fe(w) in 1811k , Fe(r)->Fe(w) in 2011k , Fe(w)+1/50C->Fe50C in 2046k 1纯净磁铁矿石=1.25Fe3O4 使用碳粉代替石墨消耗减半
	cout << "Using Pure Fe3O4 Ore(0) or BlackSand(1)? ";   //综上所述 得:X=7*A/3*1.25 Y=A+B B=A/50 Z=C A=C或A=C/2
	cin >> q2;
	cout << "Using Carbon bar(0) or Carbon dust(1)? ";
	cin >> q3;
	f32 X, Y, Z;           //X=消耗纯净磁铁矿石/消耗黑沙 Y=总消耗石墨棒 Z=生成钢 
	f32 A, B, C;           //A=生成铁消耗石墨棒 B=生成钢消耗石墨棒 C=生成铁/生成铸铁
	if (q1 == 1)                     //get steel to calc Fe and C
	{
		if (q2 == 1)            //calc with blackSand(Value:1)
		{
			cout << "Target BlackSand: ";
			cin >> X;
			C = X / 7 * 3;
		}
		else                       //calc with Pure Fe3O4 Ore(Value:1.25)
		{
			cout << "Target Pure Fe3O4 Ore: ";
			cin >> X;
			C = X / 7 * 3 * 1.25;
		}
		if (q3 == 1)
		{
			A = C / 2;
		}
		else
		{
			A = C;
		}
		B = C / 50;
		Y = A + B;
		Z = C;
		cout << endl << "Need Steel: ";       //output
		cout << Z << endl;
		if (q3 == 1)
		{
			cout << "Need Carbon dust: ";
		}
		else
		{
			cout << "Need Carbon bar: ";
		}
		cout << Y << endl;
		cout << "A=" << A << "    B=" << B << endl;
	}
	else if (q1 == 2)             //get Fe to calc steel and C
	{
		cout << "Get Steel: ";
		cin >> Z;
		C = Z;
		if (q3 == 1)
		{
			A = C / 2;
		}
		else
		{
			A = C;
		}
		B = C / 50;
		Y = A + B;
		if (q2 == 1)              //calc with blackSand(Value:1) and output
		{
			X = C / 3 * 7;
			cout << endl << "Need BlackSand: ";
		}
		else                       //calc with Pure Fe3O4 Ore(Value:1.25) and output
		{
			X = C / 3 * 7 / 1.25;
			cout << endl << "Need Pure Fe3O4 Ore: ";
		}
		cout << X << endl;
		if (q3 == 1)
		{
			cout << "Need Carbon dust: ";
		}
		else
		{
			cout << "Need Carbon bar: ";
		}
		cout << Y << endl;
		cout << "A=" << A << "    B=" << B << endl;
	}
	else
	{
		if (q3 == 1)
		{
			cout << "Target Carbon dust: ";
		}
		else
		{
			cout << "Target Carbon bar: ";
		}
		cin >> Y;
		if (q3 == 1)
		{
			A = 50 * Y / 52;   //∵Y=A+B B=2A/50 ∴A=50Y/52
			C = 2 * A;
		}
		else
		{
			A = 50 * Y / 51;   //∵Y=A+B B=A/50 ∴A=50Y/51
			C = A;
		}
		B = A / 50;
		Z = C;
		if (q2 == 1)              //calc with blackSand(Value:1) and output
		{
			X = C / 3 * 7;
			cout << endl << "Need BlackSand: ";
		}
		else                       //calc with Pure Fe3O4 Ore(Value:1.25) and output
		{
			X = C / 3 * 7 / 1.25;
			cout << endl << "Need Pure Fe3O4 Ore: ";
		}
		cout << X << endl;
		cout << "Get Steel: ";       //output
		cout << Z << endl;
		cout << "A=" << A << "    B=" << B << endl;
	}
}

void SimpleHeat()
{
	f32 Q, m, T;     //定义:1HU使100kg物质温度上升1k T=Qm/100
	cout << "Enter Q: ";
	cin >> Q;
	cout << "Enter m: ";
	cin >> m;
	T = Q / (m / 100);
	cout << "△T = " << T << "k" << endl;
}
