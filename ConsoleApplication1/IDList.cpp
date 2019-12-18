#include "pch.h"
#include <iostream>
#include "bases.h"

chamber hEmpty     //ÎÞ
{
	"NULL",0,0
};

chamber PbChamber     //Ç¦È¼ÉÕÊÒ
{
	"Pb",0.5,16
};

chamber Cu3SnChamber     //ÇàÍ­È¼ÉÕÊÒ
{
	"Cu3Sn", 0.75,24
};

chamber Fe50CChamber     //¸ÖÈ¼ÉÕÊÒ
{
	"Fe50C",0.7,32
};

chamber CrChamber     //¸õÈ¼ÉÕÊÒ
{
	"Cr",0.85,112
};

chamber TiChamber    //îÑÈ¼ÉÕÊÒ
{
	"Ti",0.85,96
};

chamber WChamber      //ÎÙÈ¼ÉÕÊÒ
{
	"W",1,128
};

crucible bEmpty =      //0.ÎÞ
{
	"NULL",0,
	0,0,
	0,
	0
};

crucible CeramicCrucible =      //1.ÌÕ´ÉÛáÛö
{
	"Li(Al2O3)2,5(SiO2)2,3",2500,
	2000,4000,
	7,
	687.898
};

crucible SteelCrucible =    //2.¸ÖÛáÛö
{
	"Fe50C",2557,
	2046,3156,
	7,
	6159.486
};

crucible CrCrucible =       //3.¸õÛáÛö
{
	"Cr",2725,
	2180,2944,
	7,
	5561.111
};

crucible IrCrucible =    //4.Ò¿ÛáÛö
{
	"Ir",3398,
	2719,4701,
	7,
	17546.666
};

crucible CarbonCrucible =      //5.Ì¼ÛáÛö
{
	"C",4750,
	4300,4400,
	7,
	1763.222
};

matter iEmpty =			//0.ÎÞ
{
	"null","null",
	0,0,
	0,
	0
};

matter Fe3O4_PureO =        //1.´¿¾»´ÅÌú¿óÊ¯
{
	"Fe3O4","ore",
	1811,3622,
	1.25,
	468.803
};

matter C_Bar =                //2.Ê¯Ä«°ô
{
	"C","inget",
	2000,4300,
	1,
	251.888
};

matter FeRaw =               //3.Ìú	7Fe3O4+1.5C -> Fe(r)  in 1811k
{
	"Fe(r)","inget",
	1811,3134,
	1,
	874.888
};
matter FeTink =            //4.ÖýÌú	 Fe(r) -> Fe(w)  in 2011k
{
	"Fe","inget",
	2011,3134,
	1,
	874.888
};

matter Steel =              //5,¸Ö	Fe(w)+1/50C -> Fe50C  in 2046k
{
	"Fe50C","inget",
	1811,3134,
	1,
	874.888
};

matter Pb =             //6.Ç¦
{
	"Pb","inget",
	600,2022,
	1,
	1260.222
};

matter Cu =            //7.Í­
{
	"Cu","inget",
	1357,2835,
	1,
	995.555
};

matter Sn =               //8.Îý
{
	"Sn","inget",
	505,2875,
	1,
	809.666
};

matter Cu3Sn =          //9.ÇàÍ­	3Cu+Sn -> 4Cu3Sn  in 1367k
{
	"Cu3Sn","inget",
	1357,2835,
	1,
	949.083
};

matter Zn =              //10.Ð¿
{
	"Zn","inget",
	692,1180,
	1,
	792.666
};

matter Cu3Zn =           //11.»ÆÍ­	3Cu+Zn -> 4Cu3Zn  in 1160k
{
	"Cu3Zn","inget",
	1160,2835,
	1,
	944.833
};

matter Fe2Ni =           //12.Òó¸Ö(ÒòÍßºÏ½ð)	2Fe(r)+Ni -> 3Fe2Ni  in 1916k
{
	"Fe2Ni","inget",
	1916,3151,
	1,
	913.333
};

matter Cr =           //13.¸õ
{
	"Cr","inget",
	2180,2944,
	1,
	794.444
};

matter Mn =           //14.ÃÌ
{
	"Mn","inget",
	1519,2334,
	1,
	826.666
};

matter StainlessSteel =   //15.²»Ðâ¸Ö	4Fe(w)+3Fe2Ni+Cr+Mn -> 9Fe4(Fe2Ni)CrMn  in 2011k
{
	"Fe4(Fe2Ni)CrMn","inget",
	1943,3029,
	1,
	873.407
};

matter W =           //16.ÎÙ
{
	"W","inget",
	3695,5828,
	1,
	2138.888
};

matter Fe50CW =           //17.ÎÙ¸Ö	Fe50C+W -> (Fe50C)W  in 2870k
{
	"(Fe50C)W","inget",
	2870,4492,
	1,
	1509.407
};

matter Mo =           //18.îâ
{
	"Mo","inget",
	2896,4912,
	1,
	1135.555
};

matter V =           //19.·°
{
	"V","inget",
	2183,3680,
	1,
	678.888
};

matter Co =           //20.îÜ
{
	"Co","inget",
	1768,3200,
	1,
	984.444
};

matter Si =           //21.¹è
{
	"Si","inget",
	1687,3538,
	1,
	258.844
};

matter Os =           //22.ï°
{
	"Os","inget",
	3306,5285,
	1,
	2512.222
};

matter Ir =           //23.Ò¿
{
	"Ir","inget",
	2719,4701,
	1,
	2506.666
};

matter OsIr =           //24.Ò¿ï°ºÏ½ð	Os+Ir -> 2OsIr  in 3012k
{
	"OsIr","inget",
	3012,4993,
	1,
	2509.444
};

matter HighSpeedSteelTypeG =    //25.¸ßËÙ¸Ö-G	5Fe50CW+Cr+2Mo+V -> 9((Fe50C)W)5,2CrMo2V  in 2870k
{
	"((Fe50C)W)5,2CrMo2V","inget",
	2722,4323,
	1,
	1254.609
};

matter HighSpeedSteelTypeE =    //26.¸ßËÙ¸Ö-E	6((Fe50C)W)5,2CrMo2V+Co+Mn+Si -> 9(((Fe50C)W)5,2CrMo2V)6,9CoMnSi  in 2314k
{
	"(((Fe50C)W)5,2CrMo2V)6,9CoMnSi","inget",
	2314,3890,
	1,
	1066.401
};

matter HighSpeedSteelTypeS =    //27.¸ßËÙ¸Ö-S	6((Fe50C)W)5,2CrMo2V+2OsIr+Ir -> 9(((Fe50C)W)5,2CrMo2V)6,9(OsIr)Ir  in 2786k
{
	"(((Fe50C)W)5,2CrMo2V)6,9(OsIr)Ir","inget",
	2786,4513,
	1,
	1672.579
};
