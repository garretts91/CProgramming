#pragma once
typedef struct 
{
	double voltage;
	double resistance;
}ElectricCircuit, *ElectricCircuitPtr;

double ComputeCurrent(ElectricCircuitPtr electricCircuit);
