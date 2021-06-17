#include "StdAfx.h"
#include "DsimModel.h"

INT DsimModel::isdigital (CHAR *pinname) {
	return TRUE;							// Indicates this is a digital model
}

BOOL DsimModel::indicate(REALTIME time, ACTIVEDATA* data) {
	return FALSE;
}
VOID DsimModel::setup (IINSTANCE *instance, IDSIMCKT *dsimckt) {
	inst = instance;
	ckt = dsimckt;
	
	pin_EC8 = inst->getdsimpin("EC8",true);
	pin_Y7  = inst->getdsimpin("Y7",true);
	pin_X7  = inst->getdsimpin("X7",true);
	pin_Y6  = inst->getdsimpin("Y6",true);
	pin_X6  = inst->getdsimpin("X6",true);
	pin_X5  = inst->getdsimpin("X5",true);
	pin_X4  = inst->getdsimpin("X4",true);
	pin_Y5  = inst->getdsimpin("Y5",true);
	pin_Y4  = inst->getdsimpin("Y4",true);
	pin_X3  = inst->getdsimpin("X3",true);
	pin_Y3  = inst->getdsimpin("Y3",true);
	pin_X2  = inst->getdsimpin("X2",true);
	pin_Y2  = inst->getdsimpin("Y2",true);
	pin_Y1  = inst->getdsimpin("Y1",true);
	pin_X1  = inst->getdsimpin("X1",true);
	pin_X0  = inst->getdsimpin("X0",true);
	pin_Y0  = inst->getdsimpin("Y0",true);
	pin_Cn  = inst->getdsimpin("Cn",true);
	pin_Cn1 = inst->getdsimpin("Cn+1",true);
	pin_Cn2 = inst->getdsimpin("Cn+2",true);
	pin_Cn3 = inst->getdsimpin("Cn+3",true);
	pin_Cn4 = inst->getdsimpin("Cn+4",true);
	pin_Cn5 = inst->getdsimpin("Cn+5",true);
	pin_Cn6 = inst->getdsimpin("Cn+6",true);
	pin_Cn7 = inst->getdsimpin("Cn+7",true);
	pin_Cn8 = inst->getdsimpin("Cn+8",true);


}

VOID DsimModel::simulate(ABSTIME time, DSIMMODES mode) {
	EC8 = ishigh(pin_EC8->istate());
	Y7  = ishigh(pin_Y7->istate());
	X7  = ishigh(pin_X7->istate());
	Y6  = ishigh(pin_Y6->istate());;
	X6  = ishigh(pin_X6->istate());;
	X5  = ishigh(pin_X5->istate());;
	X4  = ishigh(pin_X4->istate());;
	Y5  = ishigh(pin_Y5->istate());;
	Y4  = ishigh(pin_Y4->istate());;
	X3  = ishigh(pin_X3->istate());;
	Y3  = ishigh(pin_Y3->istate());;
	X2  = ishigh(pin_X2->istate());;
	Y2  = ishigh(pin_Y2->istate());;
	Y1  = ishigh(pin_Y1->istate());;
	X1  = ishigh(pin_X1->istate());;
	X0  = ishigh(pin_X0->istate());;
	Y0  = ishigh(pin_Y0->istate());;
	Cn  = islow(pin_Cn->istate());;

	Cn1 = !(Y0 & X0 | Y0 & Cn);
	Cn2 = !(Y1 & X1 | Y1 & Y0 & X0 | Y0 & Y1 & Cn);
	Cn3 = !(Y2 & X2 | Y2 & Y1 & X1 | Y2 & Y1 & Y0 & X0 | Y2 & Y1 & Y0 & Cn);
	Cn4 = !(Y3 & X3 | Y3 & Y2 & X2 | Y3 & Y2 & Y1 & X1 | Y3 & Y2 & Y1 & Y0 & X0 | Y3 & Y2 & Y1 & Y0 & Cn);
	Cn5 = !(Y4 & X4 | Y4 & Y3 & X3 | Y4 & Y3 & Y2 & X2 | Y4 & Y3 & Y2 & Y1 & X1 | Y4 & Y3 & Y2 & Y1 & Y0 & X0 
		            | Y4 & Y3 & Y2 & Y1 & Y0 & Cn);
	Cn6 = !(Y5 & X5 | Y5 & Y4 & X4 | Y5 & Y4 & Y3 & X3 | Y5 & Y4 & Y3 & Y2 & X2 | Y5 & Y4 & Y3 & Y2 & Y1 & X1 
		            | Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & X0 | Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & Cn);
	Cn7 = !(Y6 & X6 | Y6 & Y5 & X5 | Y6 & Y5 & Y4 & X4 | Y6 & Y5 & Y4 & Y3 & X3 | Y6 & Y5 & Y4 & Y3 & Y2 & X2 
					| Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & X1 | Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & X0 
					| Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & Cn);
	Cn8 = !(Y7 & X7 | Y7 & Y6 & X6 | Y7 & Y6 & Y5 & X5 | Y7 & Y6 & Y5 & Y4 & X4 | Y7 & Y6 & Y5 & Y4 & Y3 & X3 
					| Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & X2 | Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & X1 
					| Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & X0 | Y7 & Y6 & Y5 & Y4 & Y3 & Y2 & Y1 & Y0 & Cn);

	pin_Cn1->setstate(time, 0, Cn1 ? SHI : SLO);
	pin_Cn2->setstate(time, 0, Cn2 ? SHI : SLO);
	pin_Cn3->setstate(time, 0, Cn3 ? SHI : SLO);
	pin_Cn4->setstate(time, 0, Cn4 ? SHI : SLO);
	pin_Cn5->setstate(time, 0, Cn5 ? SHI : SLO);
	pin_Cn6->setstate(time, 0, Cn6 ? SHI : SLO);
	pin_Cn7->setstate(time, 0, Cn7 ? SHI : SLO);
	pin_Cn8->setstate(time, 0, EC8 ? (Cn8 ? SLO : SHI) : FLT);
} 

VOID DsimModel::runctrl (RUNMODES mode) {}

VOID DsimModel::actuate (REALTIME time, ACTIVESTATE newstate) {}

VOID DsimModel::callback (ABSTIME time, EVENTID eventid) {}
