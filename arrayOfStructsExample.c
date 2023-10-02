#include <stdio.h>
#include <string.h>

// Define a struct for an employee record
struct Employee {
    int employeeID;
    char firstName[50];
    char lastName[50];
    float salary;
};

int main() {
    // Create an array of structures to store employee records
    struct Employee employees[3];

    // Fill in the details for each employee
    employees[0].employeeID = 101;
    strcpy(employees[0].firstName, "John");
    strcpy(employees[0].lastName, "Doe");
    employees[0].salary = 55000.0;

    employees[1].employeeID = 102;
    strcpy(employees[1].firstName, "Alice");
    strcpy(employees[1].lastName, "Smith");
    employees[1].salary = 60000.0;

    employees[2].employeeID = 103;
    strcpy(employees[2].firstName, "Bob");
    strcpy(employees[2].lastName, "Johnson");
    employees[2].salary = 52000.0;

    // Display the employee records
    printf("Employee Records:\n");
    for (int i = 0; i < 3; i++) {
        printf("Employee ID: %d\n", employees[i].employeeID);
        printf("Name: %s %s\n", employees[i].firstName, employees[i].lastName);
        printf("Salary: $%.2f\n\n", employees[i].salary);
    }

    return 0;
}
