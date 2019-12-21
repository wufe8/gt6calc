#pragma once
#ifndef ALLOYMELT_H_

//class pototype here

class heatCalc
{
private:
	struct ChamberData
	{
		chamber* pos;      //ChamberData
		u16 len;         //the len in pos[]->...
		u16 value;       //getValue
	}ChamberAbout;
	struct CrucibleData
	{
		crucible* pos;     //CrucibleData
		u16 len;         //the len in pos[]->...
		u16 value;        //getValue
		u16 inBaseSize;     //the size about crucible in wheather mega crucible
	}CrucibleAbout;
	struct ItemData
	{
		matter* pos;      //ItemData
		u16 len;         //the len in pos[]->...
		u16 value[16];      //getValue
		u16 count[16];      //count how many item inside the crucible
		u16 total;         //the totel with count[]
		u16 kind;         //count how many kind of Item
	}ItemAbout;
	f32 Q, Q0;        //Q=actual heat unit(HU), Q0 = useful heat unit(HU)
	f32 m, T;         //m = total matter(kg), T = tamperture(K)  定义:1HU可使100kg物质温度上升1k T = Q0m / 100
	f32 Power, Power0, eta, time;	  //Power = Power(HU/t) Power0 = useful Power(HU/t) eta = efficiency(%) time(tick/s) eta=P0/P*100% 
	void reWriteItem(u16 jumpTo)     //setup ItemCount manual(inline)
	{
		heatCalc::ItemAbout.kind = jumpTo;
	}
	void ShowChamber();        //output the id list
	void ShowCrucible();
	void ShowItem();
public:
	void getCrucible();
	u16 getItem(u16 id = 0, u16 n = 0, u16 pos = 0, u16 mode = 0);
	void getChamber();            //get xxxValue
	void setTempture();
	void bufferOutput(u16 level = 0);
	void featureOutput();
	u16 getItemPos()
	{
		return ItemAbout.kind;
	}
		heatCalc();
		~heatCalc();
};  //TODO:heat()

#endif // !ALLOYMELT_H_
