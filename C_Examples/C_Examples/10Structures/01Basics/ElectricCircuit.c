#include "ElectricCircuit.h"

double ComputeCurrent(struct ElectricCircuit electricCircuit)
{
	double current = electricCircuit.voltage / electricCircuit.resistance;

	return current;
}