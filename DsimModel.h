#pragma once
#include "StdAfx.h"
#include "sdk/vsm.hpp"

#define InfoLog(__s__) inst->log(__s__);

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
	
	// input pins
	IDSIMPIN* pin_EC8;
	IDSIMPIN* pin_Y7;
	IDSIMPIN* pin_X7;
	IDSIMPIN* pin_Y6;
	IDSIMPIN* pin_X6;
	IDSIMPIN* pin_X5;
	IDSIMPIN* pin_X4;
	IDSIMPIN* pin_Y5;
	IDSIMPIN* pin_Y4;
	IDSIMPIN* pin_X3;
	IDSIMPIN* pin_Y3;
	IDSIMPIN* pin_X2;
	IDSIMPIN* pin_Y2;
	IDSIMPIN* pin_Y1;
	IDSIMPIN* pin_X1;
	IDSIMPIN* pin_X0;
	IDSIMPIN* pin_Y0;
	IDSIMPIN* pin_Cn;
	// output
	IDSIMPIN* pin_Cn1;
	IDSIMPIN* pin_Cn2;
	IDSIMPIN* pin_Cn3;
	IDSIMPIN* pin_Cn4;
	IDSIMPIN* pin_Cn5;
	IDSIMPIN* pin_Cn6;
	IDSIMPIN* pin_Cn7;
	IDSIMPIN* pin_Cn8;
	
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

	// IDEBUGPOPUP *myPopup;
};
