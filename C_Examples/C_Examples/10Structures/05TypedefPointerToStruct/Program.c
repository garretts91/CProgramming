#include <stdio.h>
#include "ElectricCircuit.h"

void main()
{
	ElectricCircuit electricCircuit;
	ElectricCircuitPtr electricCircuitPtr = &electricCircuit;

	printf("Enter voltage: ");
	int result = scanf("%lf", &electricCircuit.voltage);

	printf("Enter resistance: ");
	result = scanf("%lf", &electricCircuit.resistance);

	double current = ComputeCurrent(electricCircuitPtr);

	printf("Current: %lf\n", current);
}