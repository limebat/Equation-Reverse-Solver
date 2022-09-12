#ifndef _INITIALIZATION
#define _INITIALIZATION
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "functions.h"
#include "arraymaker.h"
#include "introduction.h"

enum Functions {
    Multiplication,
    Division,
    Addition,
    Subtraction,
    Net 
};
int getInputs(){
    double expectedAnswer{};
    short int functionsAllowed{2};
    Functions Multiplication, Division, Net;
    printf("What result would you expect from the function? \n");
    printf("I.e. insert a number that you expect from the function into console, i.e. 3. \n");
    std::cin >> expectedAnswer;
    printf("How many variables do you want to use?", '\n');
    int size{} ;
    short int counter{0};
    bool solved = false; // if true, we found 100% correct solution. If not, give best solution.
    std::cin >> size;
    double variables[size];
    double uniqueVaraibles[2*size+1][functionsAllowed]; // will change after finding unique values 
    short uniqueCoordinates[2*size+1][2][functionsAllowed];
    for (short int i{0}; i < size ; i++){
        if(std::cin >> variables[i]){
            //print is number of variables
            counter++;
        }
        else{
            //print is character
            printf("Character type not allowed\n"); 
            break ;
        }
    };
    printf("Your variable values are:: \n");
    for (short int i{0}; i < size ; i++){
        //std::cout << variables[i] << std::endl;
        std::cout << variables[i] << std::endl;
    };
    
        printf("\n You have entered %d variables \n", counter);
    for (short int i{0}, counter{0}, sequentier{0}; i < (size) ; i++){ //multiply for all unique variables
        for (short int j{0}; j < (size) ; j++){
            if (i == (counter+1)){
                counter++;
                j = counter; //delete all variables off half-transpose of imaginary size*size matrix
            }
            double z = variables[i] * variables[j];
            //std::cout << z << " testing all possible values, coordinates are:: " << i << j << std::endl;
            uniqueVaraibles[sequentier][Multiplication] = z;
            uniqueCoordinates[sequentier][1][Multiplication] = {i};
            uniqueCoordinates[sequentier][2][Multiplication] = {j};
            sequentier++;
        };
    };
    for (short int i{0}, counter{0}, sequentier{0}; i < (size) ; i++){ //DIVIDE for all unique variables
        for (short int j{0}; j < (size) ; j++){
            if (i == (counter+1)){
                counter++;
                j = counter; //delete all variables off half-transpose of imaginary size*size matrix
            }
            double z = variables[i] / variables[j];
            //std::cout << z << " testing all possible values, coordinates are:: " << i << j << std::endl;
            uniqueVaraibles[sequentier][Division] = z;
            uniqueCoordinates[sequentier][1][Division] = {i};
            uniqueCoordinates[sequentier][2][Division] = {j}; //store information into (2*n)^2 size matrix
            sequentier++;
        }
    }
    std::cout << uniqueVaraibles[5][Division] << std::endl;

    return 0;
};

#endif // _INITIALIZATION