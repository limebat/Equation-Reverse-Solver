#ifndef _INTROUDCTION
#define _INTROUDCTION
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "functions.h"
#include "arraymaker.h"

enum Functions {
    Multiplication,
    Division,
    Addition,
    Subtraction,
    Net
};
int Introduction(){
    double expectedAnswer{};
    short int functionsAllowed{2};
    Functions Multiplication, Division, Addition, Subtraction, Net;
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


    


    //COMBINATION FUNCTION
    for (short int i{0}, counter{0}, sequentier{0}, sequentierOperator{0}, h{0}; i < (2*size) ; i++){ //COMBINE for all unique variables
        double z{};
        for (short int j{0}; j < (2*size) ; j++){
            std::cout << i << " :: The value of i in this loop" << std::endl;
            double z = uniqueVaraibles[sequentier][Multiplication] * uniqueVaraibles[i][Division];
            uniqueVaraibles[sequentier+2*h*size][Net] = z;
            //std::cout << z << " testing all possible values, coordinates are:: " << sequentier << j << std::endl;
            uniqueCoordinates[sequentier][1][Net] = {sequentier};
            uniqueCoordinates[sequentier][2][Net] = {i}; //store information into (2*n)^2 size matrix
            std::cout << uniqueVaraibles[sequentier+2*h*size][Net] << " From combination of x:: " << uniqueCoordinates[sequentier][1][Net] << uniqueCoordinates[sequentier][2][Net] << std::endl;         
            
            std::cout << sequentier+2*h*size << std::endl;
            sequentier++;
        }
        sequentier=0;
        std::cout << "Here is what i is equal to:: " << i << std::endl;
        h++; //to make sure our other numbers are not overwritten when writing sequentier
        //sequentier++; //Shift all uniqueVaraibles[i][Multiplication] to be +1 ahead of operator wheel
    }



    
   
    for (short int k{0}; k < 2*size; k++){ //for multiply only
        if (uniqueVaraibles[k][Net] = expectedAnswer) {
            std::cout << "The closest value is thus a result of multiplying x" << uniqueCoordinates[k][1][Net] << " , x" << uniqueCoordinates[k][2][Net] << std::endl;
            std::cout << "Which results in a value of " << uniqueVaraibles[k][Net] << std::endl;
            bool solved = true;
        }
    }

    if (solved == false){
        printf("Answer not solved for all possible correctness. Alternative closest solution(s) are:: \n");
        for (short int k{0}; k < 2*size; k++ && k != 2*size && k!= 0){
            if (abs(expectedAnswer-uniqueVaraibles[k+1][Multiplication]) < abs(uniqueVaraibles[k][Multiplication])){ 
                double closestAnswer = uniqueVaraibles[k+1][Multiplication];
            std::cout << "The closest value of thus a result of multiplying x" << uniqueCoordinates[k+1][1][Net] << " , x" << uniqueCoordinates[k+1][2][Net] << std::endl;
            std::cout << "Which results in a value of " << closestAnswer << std::endl;      
            }
        }

    }

    printf("Your expected answer is %d \n", expectedAnswer);
    std::cout << std::endl;


    return 0;
}

#endif // _INTROUDCTION