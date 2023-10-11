#include "ElectricCircuit.h"

double ComputeCurrent(ElectricCircuitPtr electricCircuit)
{
	double current = electricCircuit->voltage / electricCircuit->resistance;

	return current;
}