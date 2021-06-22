#include "StdAfx.h"
#include "DsimModel.h"

INT DsimModel::isdigital (CHAR *pinname) {
	return TRUE;							
}

BOOL DsimModel::indicate(REALTIME time, ACTIVEDATA* data) {
	return FALSE;
}
VOID DsimModel::runctrl(RUNMODES mode) {}
VOID DsimModel::actuate(REALTIME time, ACTIVESTATE newstate) {}
VOID DsimModel::callback(ABSTIME time, EVENTID eventid) {}

VOID DsimModel::setup (IINSTANCE *instance, IDSIMCKT *dsimckt) {
	inst = instance;
	ckt = dsimckt;
	
	pins_X.resize(8);
	pins_Y.resize(8);
	pins_Cn.resize(8);

	char n[3];
	for (SIZE_T i = 0; i < 8; i++) {
		n[0] = 'X';
		_itoa_s(i, &n[1], 2, 10);
		pins_X[i] = inst->getdsimpin(n, true);
	}
	for (SIZE_T i = 0; i < 8; i++) {
		n[0] = 'Y';
		_itoa_s(i, &n[1], 2, 10);
		pins_Y[i] = inst->getdsimpin(n, true);
	}

	char s[5];
	for (SIZE_T i = 1; i <= 8; i++) {
		s[0] = 'C';
		s[1] = 'n';
		s[2] = '+';
		_itoa_s(i, &s[3], 4, 10);
		pins_Cn[i] = inst->getdsimpin(s, true);
	}

	pin_EC8 = inst->getdsimpin("EC8", true);
	pin_Cn = inst->getdsimpin("Cn", true);

	pin_Cn->invert();
	pins_Cn[1]->invert();
	pins_Cn[2]->invert();
	pins_Cn[3]->invert();
	pins_Cn[4]->invert();
	pins_Cn[5]->invert();
	pins_Cn[6]->invert();
	pins_Cn[7]->invert();
	pins_Cn[8]->invert();

	pins_Cn[1]->setstate(SHI);
	pins_Cn[2]->setstate(SHI);
	pins_Cn[3]->setstate(SHI);
	pins_Cn[4]->setstate(SHI);
	pins_Cn[5]->setstate(SHI);
	pins_Cn[6]->setstate(SHI);
	pins_Cn[7]->setstate(SHI);
	pins_Cn[8]->setstate(SHI);
}

VOID DsimModel::simulate(ABSTIME time, DSIMMODES mode) {
	EC8 = ishigh(pin_EC8->istate());
	Y7  = ishigh(pins_Y[7]->istate());
	X7  = ishigh(pins_X[7]->istate());
	Y6  = ishigh(pins_Y[6]->istate());;
	X6  = ishigh(pins_X[6]->istate());;
	X5  = ishigh(pins_X[5]->istate());;
	X4  = ishigh(pins_X[4]->istate());;
	Y5  = ishigh(pins_Y[5]->istate());;
	Y4  = ishigh(pins_Y[4]->istate());;
	X3  = ishigh(pins_X[3]->istate());;
	Y3  = ishigh(pins_Y[3]->istate());;
	X2  = ishigh(pins_X[2]->istate());;
	Y2  = ishigh(pins_Y[2]->istate());;
	Y1  = ishigh(pins_Y[1]->istate());;
	X1  = ishigh(pins_X[1]->istate());;
	X0  = ishigh(pins_X[0]->istate());;
	Y0  = ishigh(pins_Y[0]->istate());;
	Cn  = ishigh(pin_Cn->istate());;

	Cn1 = (Y0 & X0 | Y0 & Cn);
	Cn2 = (Y1 & X1 | Y1 & Y0 & X0 | Y0 & Y1 & Cn);
	Cn3 = (Y2 & X2 | Y2 & Y1 & X1 | Y2 & Y1 & Y0 & X0 | Y2 & Y1 & Y0 & Cn);
	Cn4 = (Y3 & X3 | Y3 & Y2 & X2 | Y3 & Y2 & Y1 & X1 | Y3 & Y2 & Y1 & Y0 & X0 | Y3 & Y2 & Y1 & Y0 & Cn);
	Cn5 = (Y4 & X4 | Y4 & Y3 & X3 | Y4 & Y3 & Y2 & X2 | Y4 & Y3 & Y2 & Y1 & X1 | Y4 & Y3 & Y2 & Y1 & Y0 & X0 
		           | Y4 & Y3 & Y2 & Y1 & Y0 & Cn);
	Cn6 = (Y5 & X5 | Y5 & Y4 & X4 | Y5 & Y4 & Y3 & X3 | Y5 & Y4 & Y3 & Y2 & X2 | Y5 & Y4 & Y3 & Y2 & Y1 & X1 
		           | Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & X0 | Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & Cn);
	Cn7 = (Y6 & X6 | Y6 & Y5 & X5 | Y6 & Y5 & Y4 & X4 | Y6 & Y5 & Y4 & Y3 & X3 | Y6 & Y5 & Y4 & Y3 & Y2 & X2 
			   	   | Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & X1 | Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & X0 
				   | Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & Cn);
	Cn8 = (Y7 & X7 | Y7 & Y6 & X6 | Y7 & Y6 & Y5 & X5 | Y7 & Y6 & Y5 & Y4 & X4 | Y7 & Y6 & Y5 & Y4 & Y3 & X3 
				   | Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & X2 | Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & X1 
				   | Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & X0 | Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & Cn);

	pins_Cn[1]->drivebool(time, Cn1);
	pins_Cn[2]->drivebool(time, Cn2);
	pins_Cn[3]->drivebool(time, Cn3);
	pins_Cn[4]->drivebool(time, Cn4);
	pins_Cn[5]->drivebool(time, Cn5);
	pins_Cn[6]->drivebool(time, Cn6);
	pins_Cn[7]->drivebool(time, Cn7);
	EC8 ? pins_Cn[8]->drivebool(time, Cn8) : pins_Cn[8]->drivestate(time, FLT);
}