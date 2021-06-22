#pragma once

#include "StdAfx.h"
#include "sdk/vsm.hpp"

#include <string>
#include <vector>

class DsimModel : public IDSIMMODEL
{
public:
	INT isdigital (CHAR *pinname);
	VOID setup (IINSTANCE *inst, IDSIMCKT *dsim);
	VOID runctrl (RUNMODES mode);
	VOID actuate (REALTIME time, ACTIVESTATE newstate);
	BOOL indicate (REALTIME time, ACTIVEDATA *data);
	VOID simulate (ABSTIME time, DSIMMODES mode);
	VOID callback (ABSTIME time, EVENTID eventid);
private:
	IINSTANCE *inst;
	IDSIMCKT *ckt;
	
	//= input pins
	IDSIMPIN* pin_EC8;
	std::vector<IDSIMPIN*> pins_X;
	std::vector<IDSIMPIN*> pins_Y;
	//= inverted
	IDSIMPIN* pin_Cn;
	//= output
	std::vector<IDSIMPIN*> pins_Cn;
	
	bool EC8;
	bool Y7;
	bool X7;
	bool Y6;
	bool X6;
	bool X5;
	bool X4;
	bool Y5;
	bool Y4;
	bool X3;
	bool Y3;
	bool X2;
	bool Y2;
	bool Y1;
	bool X1;
	bool X0;
	bool Y0;
	bool Cn;
	bool Cn1;
	bool Cn2;
	bool Cn3;
	bool Cn4;
	bool Cn5;
	bool Cn6;
	bool Cn7;
	bool Cn8;
};
