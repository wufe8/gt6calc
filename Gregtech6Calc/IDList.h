#pragma once
#ifndef IDLIST_H
#define IDLIST_H

#include "using.h"

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

chamber ChamberList[];
crucible CrucibleList[];
matter ItemList[];

u16 Get_ChamberList_Len();         //get struct leigth
u16 Get_CrucibleList_Len();
u16 Get_ItemList_Len();

#endif