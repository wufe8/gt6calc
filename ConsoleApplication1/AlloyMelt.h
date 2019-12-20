#pragma once
#ifndef ALLOYMELT_H_

//class pototype here

class heatCalc
{
private:
	chamber* pChamber;   //ChamberData
	crucible* pCrucible;     //CrucibleData
	matter* pItem;     //ItemData
	u16 ChamberLen, CrucibleLen, ItemLen;
	u16 ChamberValue, CrucibleValue, ItemValue[16];      //getValue
	u16 ItemCount;         //count how many kind of Item
	f32 countIn, totalCount;     //count how many item in the crucible
	f32 Q, Q0;        //m = total matter(kg), T = tamperture(K)  定义:1HU可使100kg物质温度上升1k T = Q0m / 100
	f32 m, T;         //Q=actual heat unit(HU), Q0 = useful heat unit(HU)
	f32 Power, Power0, eta, time;	  //Power = Power(HU/t) Power0 = useful Power(HU/t) eta = efficiency(%) time(tick/s) eta=P0/P*100% 
public:
	void ShowChamber();        //output the id list
	void ShowCrucible();
	void ShowItem();
	void getChamber();            //get xxxValue
	void getCrucible();
	u16 getItem();
	void reWriteItem(u16 jumpTo)     //setup ItemCount manual(inline)
	{
		heatCalc::ItemCount = jumpTo;
	}
	void bufferOutput(u16 level);
		heatCalc();
		~heatCalc();
};  //TODO:heat()

#endif // !ALLOYMELT_H_
