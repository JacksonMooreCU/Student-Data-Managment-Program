#ifndef CREATE_STRUCTS
#define CREATE_STRUCTS

//magic numbers
#define LENGTH_OF_NAME 16
#define VALUES_LESS_THAN_3 1
#define VALUES_LESS_THAN_16 4
#define VALUES_LESS_THAN_64 6
#define LENGTH_OF_PHONENUMBERS 11


//student structure
struct student {

	unsigned int gpa : VALUES_LESS_THAN_16;
	unsigned int numCourses: VALUES_LESS_THAN_64;
	float tuitionFees;
	
};
//employee structure
struct employee {

	float salary;
	unsigned int yearsService: VALUES_LESS_THAN_64;
	unsigned int level: VALUES_LESS_THAN_16;

};

//person structure
struct person {

	char firstName[LENGTH_OF_NAME];
	char familyName[LENGTH_OF_NAME];
	char telephone[LENGTH_OF_PHONENUMBERS];
	unsigned int employeeOrStudent: VALUES_LESS_THAN_3;

	//person can only be a student or employee but no both so union
	union {
		struct student stu;
		struct employee emp;
	}u;	
};

#endif
