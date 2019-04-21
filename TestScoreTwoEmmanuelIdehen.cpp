//
//  main.cpp
//  TestScoreTwoEmmanuelIdehen
//  due april 18. 2019
//  Created by Emmanuel Idehen on 4/18/19.
//  Copyright © 2019 Emmanuel Idehen. All rights reserved.
//  Submitted to Marcus Golden (cs204 computer programming II)
/*
 Test Scores #2
 Modify the program of Programming Challenge 1 to allow the user to enter name-score
 pairs. For each student taking a test, the user types a string representing the name of the
 student, followed by an integer representing the student’s score. Modify both the sorting
 and average-calculating functions so they take arrays of structures, with each structure
 containing the name and score of a single student. In traversing the arrays, use pointers
 rather than array indices.
 
 
 design:
 
 
 create a student structure
 crate a function that takes the student information and the score that is dynamically asigned by the user
 create a function that averges the score
 sort the input
 print out the result
 
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//student struture
struct student
{
    string Name;
    double Grade;
};

// Function prototypes
void Information(student*, int);
void selectionSort(student *, int);
double theAverage(student *, int);
void printInformation(student *, int, double);

int main()
{
    //declare variable
    student *Test;
    double Average;
    int memory;
    
    
    // Get number of scores
    cout << "how much space would you need to average your test scores?"<<endl;
    cout <<"Enter your input: "<<endl;
    cin  >> memory;
    
    //using new to dynamically allocate memory
   Test = new student[memory];    // Allocate memory
    
    //call functions 
    Information(Test, memory);
    
    selectionSort(Test, memory);
    
    Average = theAverage(Test, memory);
    
  
    printInformation(Test, memory, Average);
    
    
    
    // Free dynamically allocated memory in heap
    delete [] Test;
    Test = nullptr;
    
    return 0;
}

//get the information from the user
void Information(student *Test, int memory)
{
    //ask for the users information
    cout << "Enter the names and scores for each student.\n";
    for (int i = 0; i < memory; i++)
    {
        //take student name and score and validate the test score
        cout << "Student" << (i + 1) <<":" <<endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, (Test + i)->Name);
        do
        {
            cout << "Enter Score :";
            cin  >> (Test + i)->Grade;
            
            if ((Test + i)->Grade < 0)
            {
                cout << "Scores must be greater than 0.\n"<<endl;
            }
            cout << endl;
        } while ((Test + i)->Grade < 0);
    }
}
//selection sort, to arrange the scores in accending order
void selectionSort(student *Test, int memory)
{
    int startscan, minIndex;
    student *minValue;
    
    for (startscan = 0; startscan < (memory - 1); startscan++)
    {
        minIndex = startscan;
        *minValue = Test[startscan];
        for (int i = startscan + 1; i < memory; i++)
        {
            if ((Test + i)->Grade < minValue->Grade)
            {
                *minValue = Test[i];
                minIndex = i;
            }
            
        }
        Test[minIndex] = Test[startscan];
        Test[startscan] = * minValue;
    }
}
//calculate the average test scores
double theAverage(student *Test, int memory)
{
    double Total;
    
    for (int i = 0; i < memory; i++)
    {
        Total += (Test + i)->Grade;
    }
    
    return (Total / memory);
}
//function to display the users information
void printInformation(student *Test, int memory, double Avg)
{
    cout << "    Test scores\n";
    cout << "Number of scores: " << memory << endl;
    cout << "Scores in ascending order:\n";
    for (int i = 0; i < memory; i++)
    {
        cout << (Test + i)->Name << ": " << (Test + i)->Grade << endl;
    }
  
    cout << "The Average of your test scores is: " << Avg << endl;
}
/*
 Test case:
 
 
 how much space would you need to average your test scores?
 Enter your input:
 1
 Enter the names and scores for each student.
 Student1:
 Enter Name: em
 Enter Score :2
 
 Test scores
 Number of scores: 1
 Scores in ascending-order:
 em: 2
 The Average of your test scores is: 2
 Program ended with exit code: 0
 
 test case 2:
 
 how much space would you need to average your test scores?
 Enter your input:
 2
 Enter the names and scores for each student.
 Student1:
 Enter Name: d
 Enter Score :2
 
 Student2:
 Enter Name: e
 Enter Score :2
 
 Test scores
 Number of scores: 2
 Scores in ascending order:
 d: 2
 e: 2
 The Average of your test scores is: 2
 Program ended with exit code: 0
 
 
 
 
 
 */
