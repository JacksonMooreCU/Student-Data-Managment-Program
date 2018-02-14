//include header files
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"

//magic numbers
#define NUM_RECORDS 20
#define EMPLOYEE 0

//print an employee in the required format
void printEmployee(struct person *person){
	
	//combineing first and last name into one string for spacing purposes
	char str[33];
   	sprintf(str, "%s %s",person->firstName, person->familyName);
   	printf("%-33s Years:%3u, Level:%3u, Salary:%9.2f\n",
	str,person->u.emp.yearsService,person->u.emp.level,person->u.emp.salary);

}
//loop through each person in the structure and print each employee
void printEmployees(struct person *person){
	
	for (int index = 0; index < NUM_RECORDS; index ++){
		if(person->employeeOrStudent == EMPLOYEE){
			printEmployee(person);
		}
		person++;
	}
}

//print the employee records
void employeeRecords(struct person *person){

	//create and set default values for required vairables
	int numEmployees = 0;
	int minLevel=15;
	int maxLevel=0;
	float totalYearsService=0;
	float totalSalary=0;
	float averageYearsService=0;
	float averageSalary=0;

	//go through each person
	for (int index = 0; index < NUM_RECORDS; index ++){
		
		//if the person is an employee
		if((person->employeeOrStudent == EMPLOYEE)){
			
			//increase the amout of employees by 1
			numEmployees++;

			//add the workers years of service to the total years of service
			totalYearsService += person->u.emp.yearsService;

			//add the workers salary to the total salary
			totalSalary += person->u.emp.salary;

			//check if the workers level is higher then the current max or lower than the current min
			//and set it for that if it is.
			if((maxLevel) < (person->u.emp.level)){
				maxLevel = person->u.emp.level;
			}
			else if((minLevel) > (person->u.emp.level)){
				minLevel = person->u.emp.level;
			}	
		}
		//increse the pointer to traverse the array
		person++;
	}

	//calculate averages
	averageYearsService = totalYearsService/numEmployees;
	averageSalary = totalSalary/numEmployees;

	//display results in the required fashion
	printf("Employee Stats:\n");
	printf("Number of Employees: %d Min Level: %d Max Level: %d\n",numEmployees,minLevel,maxLevel);
	printf("Average Years of Service: %5.2f, Average Salary: %9.2f\n",averageYearsService,averageSalary);

}
