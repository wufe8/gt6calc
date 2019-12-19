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

struct chamber      //ȼ�����޶�
{          //����,����ȼ���ҵ�Ч���빦����ͬ  ���ܹ���,����,��ͨ���崲ȼ��������ͨ����,����ȼ���ҵ�4������,Ч����ͬ �������崲ȼ��������ͨ���崲��4������,Ч����ͬ
	string ingredient;	//��ѧʽ
	f32 effectiveness;    //Ч��(%)
	u16 HUoutput;        //�������(HU/t)
};

struct crucible      //�����޶�
{
	string ingredient;    //��ѧʽ
	u16 explore;       //�ۻٵ�(k)  ���۵��1.25��
	u16 meat;           //�۵�(k)
	u16 boil;           //�е�(k)
	f32 inside;		    //����(unit)
	f32 weight;		  //����(kg)
};

struct matter         //�������޶�    ����:T=T0+273k (������)
{
	string ingredient;  //��ѧʽ
	string type;       //���� inget=��,����Ѵ���Ʒ ore=��ʯ��δ����Ʒ block=��,��������ɵĻ����ȼӹ�Ʒ
	u16 meat;        //�۵�(k)
	u16 boil;        //�е�(k)
	f32 inside;      //����(unit)
	f32 weight;    //����(kg)
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

