#include <stdio.h>
#include <string.h>

// Define a struct for a payroll record
struct PayrollRecord {
    int employeeID;
    char firstName[50];
    char lastName[50];
    float hourlyRate;
    int hoursWorked;
    float totalPay;
};

int main() {
    // Create a payroll record
    struct PayrollRecord employee;

    // Fill in the details
    employee.employeeID = 101;
    strcpy(employee.firstName, "John");
    strcpy(employee.lastName, "Doe");
    employee.hourlyRate = 15.50;
    employee.hoursWorked = 40;
    employee.totalPay = employee.hourlyRate * employee.hoursWorked;

    // Display the payroll record
    printf("Employee ID: %d\n", employee.employeeID);
    printf("Name: %s %s\n", employee.firstName, employee.lastName);
    printf("Hourly Rate: %.2f\n", employee.hourlyRate);
    printf("Hours Worked: %d\n", employee.hoursWorked);
    printf("Total Pay: %.2f\n", employee.totalPay);

    return 0;
}
