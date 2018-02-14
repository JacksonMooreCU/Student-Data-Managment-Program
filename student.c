//include header files
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "struct.h"
#include "student.h"

//magic numbers
#define NUM_RECORDS 20
#define STUDENT 1

//print a student in the required fasion
void printStudent(struct person *person){
	
	//combineing first and last name into one string for spacing purposes
	char str[33];
   	sprintf(str, "%s %s",person->firstName, person->familyName);
   	printf("%-33s GPA:%3u, Courses :%3u, Tuition:%9.2f\n",
	str,person->u.stu.gpa,person->u.stu.numCourses,person->u.stu.tuitionFees);
}
//print disply the information for all students with a chosen last name
void searchStudentFamilyName(struct person *person){
	
	//ask the user for the last name
	printf("Insert the family name you would like to search for.\n");
	char lastName[16];
	scanf("%s",lastName);

	//print only the students with the desired last name
	printStudents(person,lastName);
}

//insted of using 2 function to print student information 
//one function is used and an extra parameter is used to 
//deterime which students should be printed
void printStudents(struct person *person,char lastName[16]){
	
	//iterate through all records
	for (int index = 0; index < NUM_RECORDS; index ++){

		//check if all students should be printed or a select few
		int nameCheck;
		if((strcmp(lastName,"All"))==0){
			nameCheck =0;	
		}
		else{
			nameCheck = strcmp(lastName,person->familyName);
		}
		//cheeck if the person has the correct last name and they are a student 
		if((nameCheck == 0) && (person->employeeOrStudent == STUDENT)){
			//then print
			printStudent(person);
		}
		//increse the pointer to traverse the array
		person++;
	}
}

//display all the student records
void studentRecords(struct person *person){
	
	//create and set default values for required vairables
	int numStudents = 0;
	float averageGpa=0;
	float averageNumCourses=0;
	float averageTuitionFees=0;
	float totalGpa=0;
	float totalNumCourses=0;
	float totalTuitionFees=0;

	//for all people
	for (int index = 0; index < NUM_RECORDS; index ++){
		
		//if the person is a student
		if(person->employeeOrStudent == STUDENT){
			
			//icrease the varaible based upon the students values
			numStudents++;
			totalGpa += person->u.stu.gpa;
			totalNumCourses += person->u.stu.numCourses;
			totalTuitionFees += person->u.stu.tuitionFees;
		}
		//increse the pointer to traverse the array
		person++;
	}

	//calculate averages
	averageGpa = totalGpa/numStudents;
	averageNumCourses = totalNumCourses/numStudents;
	averageTuitionFees = totalTuitionFees/numStudents;

	//display the reuslts in the required fashion
	printf("Student Stats:\n");
	printf("Number of Students: %d\n",numStudents);
	printf("Average GPA: %5.2f, Average Number of courses: %5.2f, Average Tuition Fees: %7.2f\n"
	,averageGpa,averageNumCourses,averageTuitionFees);
	
}
