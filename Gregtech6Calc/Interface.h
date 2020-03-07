#pragma once
#ifndef INTERFACE_H
#include "AlloyMelt.h"

class Interface :  //I* input, S* show, O* output
	public heatCalc
{
public:
	void ShowChamber();        //output the id list
	void ShowCrucible();        //output the id list
	void ShowItem();        //output the id list
	void IChamber();
	void ICrucible();
	u16 IItem();
	void ITempture();
	void tr();        //translate heatCalc::receive into cout
	void  ODetail(u8 level = 1);
	void OFeature();
};

#endif //!INTERFACE_H