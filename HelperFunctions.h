#pragma once
#include <string>
#include"DEFS.h";
using namespace std;
string orderTypeToString(OrderType type) {

	switch (type) {
	case ODN: return "ODN";
	case ODG: return "ODG";
	case OVN: return "OVN";
	case OVG: return "OVG";
	case OVC: return "OVC";
	case OT:  return "OT";
	default:  return "UNKNOWN";
	}
}