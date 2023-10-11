#pragma once
typedef struct 
{
	double voltage;
	double resistance;
}ElectricCircuit;

double ComputeCurrent(ElectricCircuit* electricCircuit);
