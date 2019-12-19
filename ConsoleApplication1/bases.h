#pragma once
#ifndef BASES_H_
#define BASES_H_

#include <iostream>
#include <string>

void ShowMemu();
void ShowAlloy(bool out = 1, bool ask = 0);
void ShowCrucible(bool out = 1, bool ask = 0);
void ShowChamber(bool out = 1, bool ask = 0);
void ShowItemtList(bool out = 1, u16 count = 0);

u16 askReceive(void (*fnOut)(bool, bool), u16 idOp, u16 idEd);
u16 askReceive(void (*fnOut)(bool, u16), u16 idOp, u16 idEd, u16& count);

struct chamber      //燃烧室限定
{          //固体,流体燃烧室的效率与功率相同  致密固体,流体,普通流体床燃烧室是普通固体,流体燃烧室的4倍功率,效率相同 致密流体床燃烧室是普通流体床的4倍功率,效率相同
	string ingredient;	//化学式
	f32 effectiveness;    //效率(%)
	u16 HUoutput;        //能量输出(HU/t)
};

struct crucible      //坩埚限定
{
	string ingredient;    //化学式
	u16 explore;       //熔毁点(k)  是熔点的1.25倍
	u16 meat;           //熔点(k)
	u16 boil;           //沸点(k)
	f32 inside;		    //含量(unit)
	f32 weight;		  //质量(kg)
};

struct matter         //纯净物限定    定义:T=T0+273k (开尔文)
{
	string ingredient;  //化学式
	string type;       //类型 inget=锭,板等已处理品 ore=矿石等未处理品 block=块,单物质组成的机器等加工品
	u16 meat;        //熔点(k)
	u16 boil;        //沸点(k)
	f32 inside;      //含量(unit)
	f32 weight;    //质量(kg)
};

extern chamber hEmpty;
extern chamber PbChamber;
extern chamber Cu3SnChamber;
extern chamber Fe50CChamber;
extern chamber CrChamber;
extern chamber TiChamber;
extern chamber WChamber;

extern crucible bEmpty;
extern crucible CeramicCrucible;
extern crucible SteelCrucible;
extern crucible CrCrucible;
extern crucible IrCrucible;
extern crucible CarbonCrucible;

extern matter iEmpty;
extern matter Fe3O4_PureO;
extern matter C_Bar;
extern matter FeRaw;
extern matter FeTink;
extern matter Steel;
extern matter Pb;
extern matter Cu;
extern matter Sn;
extern matter Cu3Sn;
extern matter Zn;
extern matter Cu3Zn;
extern matter Fe2Ni;
extern matter Cr;
extern matter Mn;
extern matter StainlessSteel;
extern matter W;
extern matter Fe50CW;
extern matter Mo;
extern matter V;
extern matter Co;
extern matter Si;
extern matter Os;
extern matter Ir;
extern matter OsIr;
extern matter HighSpeedSteelTypeG;
extern matter HighSpeedSteelTypeE;
extern matter HighSpeedSteelTypeS;

const chamber* const ChamberList[]
{
	&hEmpty,
	&PbChamber,
	&Cu3SnChamber,
	&Fe50CChamber,
	&CrChamber,
	&TiChamber,
	&WChamber		//1-6
};

const crucible* const CrucibleList[] =
{
	&bEmpty,
	&CeramicCrucible,
	&SteelCrucible,
	&CrCrucible,
	&IrCrucible,
	&CarbonCrucible		//1-5
};

const matter* const ItemList[] =
{
	&iEmpty,
	&Fe3O4_PureO,
	&C_Bar,
	&FeRaw,
	&FeTink,
	&Steel,
	&Pb,
	&Cu,
	&Sn,
	&Cu3Sn,
	&Zn,
	&Cu3Zn,
	&Fe2Ni,
	&Cr,
	&Mn,
	&StainlessSteel,
	&W,
	&Fe50CW,
	&Mo,
	&V,
	&Co,
	&Si,
	&Os,
	&Ir,
	&OsIr,
	&HighSpeedSteelTypeG,
	&HighSpeedSteelTypeE,
	&HighSpeedSteelTypeS		//0-27
};

#endif // !BASE_H_

