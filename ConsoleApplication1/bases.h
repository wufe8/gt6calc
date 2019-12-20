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

extern chamber ChamberList[];
extern crucible CrucibleList[];
extern matter ItemList[];

#endif // !BASE_H_

