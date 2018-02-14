

#include "stdio.h"
//Inlcude needed header files
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "employee.h"
#include "student.h"

//magic numbers
#define NUM_RECORDS 20

//prototype for menu functions
void mainMenu(struct person *person);
void summaryOfRecords(struct person *person);
void quit(struct person *person);

int main()
{
	//create and poplute the person array
	struct person person[NUM_RECORDS];
	populateRecords(person, NUM_RECORDS);

	//run the main menu
	mainMenu(person);
	return 0;
}
void mainMenu(struct person *person){

	//create option
	int option;
	
	//Ask user for what option they would like to choose
	printf("1. Print all employees\n2. Print all students\n3. Search students using Family Name\n4. Summary of Data\n0. Quit\n");
	scanf("%d",&option);

	//set the default print to all last names
	char lastName[16];
	strcpy(lastName,"All");


	//switch for each case
	//show the user wich option they chose
	//run the function for that option
	//call the menu again except for quit
	switch(option){

		case 1 : 
			printf("1. Print all employees\n");
			printEmployees(person);
			mainMenu(person);
			break;
		case 2 : 
			printf("2. Print all students\n");
			printStudents(person,lastName);
			mainMenu(person);
			break;
		case 3 : 
			printf("3. Search students using Family Name\n");
			searchStudentFamilyName(person);
			mainMenu(person);
			break;
		case 4 : 
			printf("4. Summary of Data\n");
			summaryOfRecords(person);
			mainMenu(person);
			break;
		case 0 : 
			printf("0. Quit\n");
			quit(person);
			break;
		default : 
			//if the user does not input a correct value
			printf("Invalid option %d\n",option);
			mainMenu(person);
			break;
	}
}
void summaryOfRecords(struct person *person){

	//display the totall number of records
	printf("Total number of records: %2d\n",NUM_RECORDS);
	//show student and employee records
	studentRecords(person);
	employeeRecords(person);
}
void quit(struct person *person){

	//create option variable
	char quitOption;
	strcpy(&quitOption," ");
	//ask the user if they are sure they want to quit
	printf("Are you sure you want to quit (y/n)?\n");
	scanf("%s", &quitOption);

	//if they don't want to then call main menu
	if (strcmp(&quitOption,"n") == 0){
		mainMenu(person);
	}
	else if (strcmp(&quitOption,"y") == 0){
	}
	else{
		printf("Invalid Option!\n");
		quit(person);
	}
	//if not then just let the function end
}




