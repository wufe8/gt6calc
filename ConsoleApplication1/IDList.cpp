#include "pch.h"
#include <iostream>
#include "bases.h"

chamber hEmpty     //��
{
	"NULL",0,0
};

chamber PbChamber     //Ǧȼ����
{
	"Pb",0.5,16
};

chamber Cu3SnChamber     //��ͭȼ����
{
	"Cu3Sn", 0.75,24
};

chamber Fe50CChamber     //��ȼ����
{
	"Fe50C",0.7,32
};

chamber CrChamber     //��ȼ����
{
	"Cr",0.85,112
};

chamber TiChamber    //��ȼ����
{
	"Ti",0.85,96
};

chamber WChamber      //��ȼ����
{
	"W",1,128
};

crucible bEmpty =      //0.��
{
	"NULL",0,
	0,0,
	0,
	0
};

crucible CeramicCrucible =      //1.�մ�����
{
	"Li(Al2O3)2,5(SiO2)2,3",2500,
	2000,4000,
	7,
	687.898
};

crucible SteelCrucible =    //2.������
{
	"Fe50C",2557,
	2046,3156,
	7,
	6159.486
};

crucible CrCrucible =       //3.������
{
	"Cr",2725,
	2180,2944,
	7,
	5561.111
};

crucible IrCrucible =    //4.ҿ����
{
	"Ir",3398,
	2719,4701,
	7,
	17546.666
};

crucible CarbonCrucible =      //5.̼����
{
	"C",4750,
	4300,4400,
	7,
	1763.222
};

matter iEmpty =			//0.��
{
	"null","null",
	0,0,
	0,
	0
};

matter Fe3O4_PureO =        //1.����������ʯ
{
	"Fe3O4","ore",
	1811,3622,
	1.25,
	468.803
};

matter C_Bar =                //2.ʯī��
{
	"C","inget",
	2000,4300,
	1,
	251.888
};

matter FeRaw =               //3.��	7Fe3O4+1.5C -> Fe(r)  in 1811k
{
	"Fe(r)","inget",
	1811,3134,
	1,
	874.888
};
matter FeTink =            //4.����	 Fe(r) -> Fe(w)  in 2011k
{
	"Fe","inget",
	2011,3134,
	1,
	874.888
};

matter Steel =              //5,��	Fe(w)+1/50C -> Fe50C  in 2046k
{
	"Fe50C","inget",
	1811,3134,
	1,
	874.888
};

matter Pb =             //6.Ǧ
{
	"Pb","inget",
	600,2022,
	1,
	1260.222
};

matter Cu =            //7.ͭ
{
	"Cu","inget",
	1357,2835,
	1,
	995.555
};

matter Sn =               //8.��
{
	"Sn","inget",
	505,2875,
	1,
	809.666
};

matter Cu3Sn =          //9.��ͭ	3Cu+Sn -> 4Cu3Sn  in 1367k
{
	"Cu3Sn","inget",
	1357,2835,
	1,
	949.083
};

matter Zn =              //10.п
{
	"Zn","inget",
	692,1180,
	1,
	792.666
};

matter Cu3Zn =           //11.��ͭ	3Cu+Zn -> 4Cu3Zn  in 1160k
{
	"Cu3Zn","inget",
	1160,2835,
	1,
	944.833
};

matter Fe2Ni =           //12.���(���ߺϽ�)	2Fe(r)+Ni -> 3Fe2Ni  in 1916k
{
	"Fe2Ni","inget",
	1916,3151,
	1,
	913.333
};

matter Cr =           //13.��
{
	"Cr","inget",
	2180,2944,
	1,
	794.444
};

matter Mn =           //14.��
{
	"Mn","inget",
	1519,2334,
	1,
	826.666
};

matter StainlessSteel =   //15.�����	4Fe(w)+3Fe2Ni+Cr+Mn -> 9Fe4(Fe2Ni)CrMn  in 2011k
{
	"Fe4(Fe2Ni)CrMn","inget",
	1943,3029,
	1,
	873.407
};

matter W =           //16.��
{
	"W","inget",
	3695,5828,
	1,
	2138.888
};

matter Fe50CW =           //17.�ٸ�	Fe50C+W -> (Fe50C)W  in 2870k
{
	"(Fe50C)W","inget",
	2870,4492,
	1,
	1509.407
};

matter Mo =           //18.��
{
	"Mo","inget",
	2896,4912,
	1,
	1135.555
};

matter V =           //19.��
{
	"V","inget",
	2183,3680,
	1,
	678.888
};

matter Co =           //20.��
{
	"Co","inget",
	1768,3200,
	1,
	984.444
};

matter Si =           //21.��
{
	"Si","inget",
	1687,3538,
	1,
	258.844
};

matter Os =           //22.�
{
	"Os","inget",
	3306,5285,
	1,
	2512.222
};

matter Ir =           //23.ҿ
{
	"Ir","inget",
	2719,4701,
	1,
	2506.666
};

matter OsIr =           //24.ҿﰺϽ�	Os+Ir -> 2OsIr  in 3012k
{
	"OsIr","inget",
	3012,4993,
	1,
	2509.444
};

matter HighSpeedSteelTypeG =    //25.���ٸ�-G	5Fe50CW+Cr+2Mo+V -> 9((Fe50C)W)5,2CrMo2V  in 2870k
{
	"((Fe50C)W)5,2CrMo2V","inget",
	2722,4323,
	1,
	1254.609
};

matter HighSpeedSteelTypeE =    //26.���ٸ�-E	6((Fe50C)W)5,2CrMo2V+Co+Mn+Si -> 9(((Fe50C)W)5,2CrMo2V)6,9CoMnSi  in 2314k
{
	"(((Fe50C)W)5,2CrMo2V)6,9CoMnSi","inget",
	2314,3890,
	1,
	1066.401
};

matter HighSpeedSteelTypeS =    //27.���ٸ�-S	6((Fe50C)W)5,2CrMo2V+2OsIr+Ir -> 9(((Fe50C)W)5,2CrMo2V)6,9(OsIr)Ir  in 2786k
{
	"(((Fe50C)W)5,2CrMo2V)6,9(OsIr)Ir","inget",
	2786,4513,
	1,
	1672.579
};
