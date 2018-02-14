Purpose: display records of students and employees
Developer Name: Jackson Moore
Date: November 9th 2017
Software Organization: 4 header files and 4 .c files
	strcuct.h contains the required structures
	uni.c contains main() and all main menu functions and headers
	employee.c contains all employee functions
	employee.h contains all employee headers
	student.c contains all student functions
	student.h contains all student headers
	populateRecords.c contains all functions to populate the records
	populateRecords.h contains all headers for populatin the records
Compile Program: To compile program follow these steps:
	1. Extract a3.tar to a3 directory
	2. navigate to a3 directory in terminal
	3. type : gcc -o main struct.h populateRecords.c populateRecords.h employee.c employee.h student.c student.h uni.c
	4. type : ./main 
Issues: Can not enter anything over than a natural number (can type 0) into main menu.
How to use Software: Once in the menu the user can enter in any of the options on the menu by entering the number 
	indicated to the left of the menu option name (1,2,3,4,0). For option 3 the user can enter a name and if 
	a student has that last name a there records will be displayed. For option 0 the user can confirm to quit
	by entering y for yes or can confirm not to quit by entering n for no.
