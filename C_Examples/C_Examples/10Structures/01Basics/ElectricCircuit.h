#pragma once
struct ElectricCircuit
{
	double voltage;
	double resistance;
};

double ComputeCurrent(struct ElectricCircuit electricCircuit);
