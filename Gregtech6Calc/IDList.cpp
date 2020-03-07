#include "pch.h"

#include "using.h"
#include "AlloyMelt.h"

//id list here

chamber ChamberList[]    //1-6
{
	{
		"NULL",0,0           //��
	},{
		"Pb", 0.5, 16        //Ǧȼ����
	},{
		"Cu3Sn", 0.75,24     //��ͭȼ����
	},{
		"Fe50C",0.7,32	     //��ȼ����
	},{
		"Cr",0.85,112	     //��ȼ����
	},{
		"Ti",0.85,96	     //��ȼ����
	},{
		"W",1,128		     //��ȼ����
	}
};

crucible CrucibleList[]    //1-5
{
	{
		"NULL",0,                         //0.��
		0,0,
		0,0
	},{
		"Li(Al2O3)2,5(SiO2)2,3",2500,    //1.�մ�����
		2000,4000,
		7,687.898
	},{
		"Fe50C",2557,                    //2.������
		2046,3156,
		7,6159.486
	},{
		"Cr",2725,                       //3.������
		2180,2944,
		7,5561.111
	},{
		"Ir",3398,                      //4.ҿ����
		2719,4701,
		7,17546.666
	}, {
		"C",4750,                       //5.̼����
		4300,4400,
		7,1763.222
	}
};

matter ItemList[] =    //1-27
{
	{
		"null","null",        //0.��
		0,0,
		0,
		0
	},{
		"Fe3O4","ore",        //1.����������ʯ
		1811,3622,
		1.25,
		468.803
	},{
		"C","inget",          //2.ʯī��
		2000,4300,
		1,
		251.888
	},{
		"Fe(r)","inget",      //3.��   7Fe3O4+1.5C -> Fe(r)  in 1811k
		1811,3134,
		1,
		874.888
	},{
		"Fe","inget",         //4.����   Fe(r) -> Fe(w)  in 2011k
		2011,3134,
		1,
		874.888
	},{
		"Fe50C","inget",      //5,��   Fe(w)+1/50C -> Fe50C  in 2046k
		1811,3134,
		1,
		874.888
	},{
		"Pb","inget",         //6.Ǧ
		600,2022,
		1,
		1260.222
	},{
		"Cu","inget",		  //7.ͭ
		1357,2835,
		1,
		995.555
	},{
		"Sn","inget",		  //8.��
		505,2875,
		1,
		809.666
	},{
		"Cu3Sn","inget",	  //9.��ͭ    3Cu+Sn -> 4Cu3Sn  in 1367k
		1357,2835,
		1,
		949.083
	},{
		"Zn","inget",		  //10.п
		692,1180,
		1,
		792.666
	},{
		"Cu3Zn","inget",	  //11.��ͭ   3Cu+Zn -> 4Cu3Zn  in 1160k
		1160,2835,
		1,
		944.833
	},{
		"Fe2Ni","inget",	  //12.���(���ߺϽ�)    2Fe(r)+Ni -> 3Fe2Ni  in 1916k
		1916,3151,
		1,
		913.333
	},{
		"Cr","inget",         //13.��
		2180,2944,
		1,
		794.444
	},{
		"Mn","inget",         //14.��
		1519,2334,
		1,
		826.666
	},{
		"Fe4(Fe2Ni)CrMn","inget",    //15.�����    4Fe(w)+3Fe2Ni+Cr+Mn -> 9Fe4(Fe2Ni)CrMn  in 2011k
		1943,3029,
		1,
		873.407
	},{
		"W","inget",          //16.��
		3695,5828,
		1,
		2138.888
	},{
		"(Fe50C)W","inget",    //17.�ٸ�    Fe50C+W -> (Fe50C)W  in 2870k
		2870,4492,
		1,
		1509.407
	},{
		"Mo","inget",    //18.��
		2896,4912,
		1,
		1135.555
	},{
		"V","inget",	 //19.��
		2183,3680,
		1,
		678.888
	},{
		"Co","inget",	 //20.��
		1768,3200,
		1,
		984.444
	},{
		"Si","inget",	 //21.��
		1687,3538,
		1,
		258.844
	},{
		"Os","inget",	 //22.�
		3306,5285,
		1,
		2512.222
	},{
		"Ir","inget",	 //23.ҿ
		2719,4701,
		1,
		2506.666
	},{
		"OsIr","inget",                               //24.ҿﰺϽ�    Os+Ir -> 2OsIr  in 3012k
		3012,4993,
		1,
		2509.444
	},{
		"((Fe50C)W)5,2CrMo2V","inget",                //25.���ٸ�-G    5Fe50CW+Cr+2Mo+V -> 9((Fe50C)W)5,2CrMo2V  in 2870k
		2722,4323,
		1,
		1254.609
	},{
		"(((Fe50C)W)5,2CrMo2V)6,9CoMnSi","inget",     //26.���ٸ�-E    6((Fe50C)W)5,2CrMo2V+Co+Mn+Si -> 9(((Fe50C)W)5,2CrMo2V)6,9CoMnSi  in 2314k
		2314,3890,
		1,
		1066.401
	},{
		"(((Fe50C)W)5,2CrMo2V)6,9(OsIr)Ir","inget",    //27.���ٸ�-S    6((Fe50C)W)5,2CrMo2V+2OsIr+Ir -> 9(((Fe50C)W)5,2CrMo2V)6,9(OsIr)Ir  in 2786k
		2786,4513,
		1,
		1672.579
	},
};

u16 Get_ChamberList_Len()         //cant use parameter because will get pointer
{
	return sizeof(ChamberList) / sizeof(ChamberList[0]);
}

u16 Get_CrucibleList_Len()
{
	return sizeof(CrucibleList) / sizeof(CrucibleList[0]);
}

u16 Get_ItemList_Len()
{
	return sizeof(ItemList) / sizeof(ItemList[0]);
}