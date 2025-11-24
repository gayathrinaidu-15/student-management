ABSTRACT

This project presents a menu-driven Student Management System developed in the C programming language using structures, dynamic memory allocation, and binary file handling. The system enables efficient management of student records by supporting essential operations such as adding new students, viewing all students, searching for individual students by ID, updating existing information, and deleting records. All data is stored permanently in a binary file (students.dat) to ensure durability even after the program terminates. The program uses a structured approach to organize student details, including ID, name, age, gender, grade, course, and contact information. The implementation demonstrates practical usage of file operations, arrays, pointers, and modular programming in C, making the system reliable, efficient, and easy to use.
SUMMARY OF THE CODE

This C program is a Student Management System that stores student details in a binary file (students.dat).
It allows the user to:

Add a student

View all students

Search a student by ID

Update student details

Delete a student

Exit the program

The program uses a struct Student to store:

ID

Name

Age

Gender

Grade

Course

Contact number

All operations use file handling (binary read/write) to store and update data permanently.

✅ MAIN FEATURES / FUNCTIONS
1. addStudent()

Takes input from user for all fields.

Checks if ID already exists.

Saves student record using saveStudent().

2. listStudents()

Loads all students using loadAll().

Displays them in table format.

3. searchStudent()

Reads file sequentially.

Searches for student by ID.

Prints details if found.

4. updateStudent()

Loads all students into an array.

Finds student by ID.

Updates contact, grade, course.

Writes updated array back to file.

5. deleteStudent()

Loads all students.

Locates the student by ID.

Confirms deletion.

Removes the record.

Writes updated list back to file.

6. idExists(id)

Checks if a student ID already exists in the file.

7. loadAll()

Reads all records from the file into a dynamically allocated array.

Returns pointer + record count.

8. writeAll()

Overwrites entire file with the provided student array (used after update/delete).

✅ HOW THE PROGRAM WORKS — STEP-BY-STEP INSTRUCTIONS
1. Run the program

You will see:

=========== STUDENT MANAGEMENT SYSTEM ===========
1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
Enter choice:

2. Add a Student

Enter ID

Enter name

Enter age

Enter gender

Enter grade

Enter course

Enter contact

The details get stored in students.dat.

3. View Students

Shows all students in a formatted table:

ID    Name            Age  Gender   Grade  Course       Contact

4. Search a Student

Enter ID

The program shows full details if found.

5. Update a Student

Enter ID

Update:

Contact

Grade

Course

Changes are saved permanently.

6. Delete a Student

Enter ID

Program shows name and asks:

Confirm (y/n):
If yes → student removed

If no → cancel

✅ KEY POINTS ABOUT THE CODE

Uses binary file handling (rb, wb, ab).

Uses structs to store multiple student fields.

Uses dynamic memory allocation for loading all students.

Provides complete CRUD operations:

Create

Read

Update

Delete

Prevents duplicate IDs using idExists().
INSTRUCTIONS FOR THE STUDENT MANAGEMENT SYSTEM PROGRAM

Follow these steps to run and use the program properly.

1. Compile the Program

Use any C compiler (GCC recommended):

gcc filename.c -o student


Run the program:

./student

2. Program Menu

When the program starts, you will see this menu:

1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit


Enter a number (1–6) to choose an option.

🔹 DETAILS OF EACH OPERATION
1. Add Student

Enter a unique ID

Enter name

Enter age

Enter gender

Enter grade

Enter course

Enter contact number

✔ The student is saved in the students.dat file.
✔ If the ID already exists, you cannot add that student.

2. View Students

Displays all saved students in table format.

If no data exists, it shows: “No students found.”

3. Search Student

Enter the student ID.

The program finds and displays:

Name

Gender

Grade

Course

Contact

If the ID does not exist, it shows “Student not found.”

4. Update Student

Enter the student ID.

If found, the program asks for:

New contact

New grade

New course

The updated details are saved back to the file.

If the ID does not exist, it shows “ID not found.”

5. Delete Student

Enter the student ID.

If found, the program displays the student’s name and asks:

Confirm (y/n):


Press y → Student is deleted

Press n → Delete cancelled

6. Exit

Ends the program.

HOW THE PROGRAM STORES DATA

All student records are saved in a binary file: students.dat

Records remain saved even after the program stops.

Dynamic memory is used to load, update, and delete records.

IMPORTANT NOTES

✔ Enter valid IDs (no duplicates).
✔ Always press Enter after entering text.
✔ The file is created automatically if it doesn’t exist.
<img width="565" height="257" alt="Screenshot 2025-11-24 220529" src="https://github.com/user-attachments/assets/470f68f7-0c23-40b6-ac85-44d1af5b4250" />

<img width="246" height="128" alt="Screenshot 2025-11-24 221224" src="https://github.com/user-attachments/assets/142f40ee-6b26-407f-a557-3542000ec6e0" />


