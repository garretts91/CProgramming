#include "ElectricCircuit.h"

double ComputeCurrent(ElectricCircuit electricCircuit)
{
	double current = electricCircuit.voltage / electricCircuit.resistance;

	return current;
}