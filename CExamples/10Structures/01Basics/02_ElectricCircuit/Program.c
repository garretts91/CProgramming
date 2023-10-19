#include <stdio.h>
#include "ElectricCircuit.h"

void main()
{
	struct ElectricCircuit electricCircuit;

	printf("Enter voltage: ");
	int result = scanf("%lf", &(electricCircuit.voltage));

	printf("Enter resistance: ");
	result = scanf("%lf", &(electricCircuit.resistance));

	double current = ComputeCurrent(electricCircuit);

	printf("Current: %lf\n", current);
}