<H1> COP3530 - Project 2 </h1>

<H2> Yum Yum in My Tum Tum </H2>

<H3> Requirements and Setup </H3>

This program was developed in C++ using CLion. To run the program, users should have a C++ compiler or a C++ IDE such 
as CLion installed.

1. Download or clone the GitHub repository.
2. Open the project in CLion (or respective C++ IDE).
3. Make sure the food.csv file is accessible from the program's working directory.
4. Build and run the program using the project's configured build target.

<H3> How to Run Yum Yum in My Tum Tum </H3>

We will run this code in the terminal. To begin, user will be prompted to enter a food category.
Valid inputs must begin with a capital letter and be lowercase throughout the rest of it (e.g. "Milk shake").
If input is valid and category has data associated with it, user will be then told how many items have been found.

<H4> Sorting Algorithm Selection </H4>

User will be then prompted with a selection menu asking how they would like their food category sorted (max heap or merge sort).
A valid input for this menu is a number between 0 and 2. If input is not a number between 0 and 2, user will be prompted again to 
select a sorting option. 

<H4> Nutrient Selection and Results </H4>

Once valid input is entered, the user will be asked which nutrient they want to focus on. 
This will follow the same format, picking a number between 0 and 3, and if invalid be prompted again. After this, the food item
that follows the selected options from previous menus will be returned. 

<H4> Exiting the Program </H4>

The program will run again until the user enters "exit" to exit the program.