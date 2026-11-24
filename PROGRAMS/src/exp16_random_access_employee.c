/*
 * Experiment 16: Random Access File for Processing Employee Details
 * Aim: Develop a C program for implementing random access file with fseek(), fread(), fwrite().
 */
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int empId;
    char empName[50];
    float empSalary;
};

int main() {
    FILE *filePtr = fopen("employee.dat", "wb+");
    if (filePtr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Employee emp1 = {101, "Alice Johnson", 75000.0f};
    struct Employee emp2 = {102, "Bob Smith", 62000.0f};

    // Write employee records using random access offsets
    fseek(filePtr, (emp1.empId - 100) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp1, sizeof(struct Employee), 1, filePtr);

    fseek(filePtr, (emp2.empId - 100) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp2, sizeof(struct Employee), 1, filePtr);
    printf("Employee records saved to binary file.\n\n");

    // Random access read: Read emp 102 directly
    struct Employee readEmp;
    int searchId = 102;
    fseek(filePtr, (searchId - 100) * sizeof(struct Employee), SEEK_SET);
    fread(&readEmp, sizeof(struct Employee), 1, filePtr);

    printf("Random Access Retrieval for ID %d:\n", searchId);
    printf("Employee ID   : %d\n", readEmp.empId);
    printf("Employee Name : %s\n", readEmp.empName);
    printf("Salary        : $%.2f\n", readEmp.empSalary);

    fclose(filePtr);
    return 0;
}
