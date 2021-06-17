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
	
	BOOL EC8;
	BOOL Y7;
	BOOL X7;
	BOOL Y6;
	BOOL X6;
	BOOL X5;
	BOOL X4;
	BOOL Y5;
	BOOL Y4;
	BOOL X3;
	BOOL Y3;
	BOOL X2;
	BOOL Y2;
	BOOL Y1;
	BOOL X1;
	BOOL X0;
	BOOL Y0;
	BOOL Cn;
	BOOL Cn1;
	BOOL Cn2;
	BOOL Cn3;
	BOOL Cn4;
	BOOL Cn5;
	BOOL Cn6;
	BOOL Cn7;
	BOOL Cn8;

	// IDEBUGPOPUP *myPopup;
};
