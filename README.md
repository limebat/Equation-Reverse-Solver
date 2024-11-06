# Equation-Reverse-Solver
Hello, hope all is well. This is my undergraduate freshman side-project as a hobby introduction for my own towards C++ and linear algebra. Now 2 years later as I update this repository, I hope this function may assist anyone who is interested in reverse-solving an equation based on input data. I am now in my Master's, where I am now updating my old projects with the description ReadMe only -- all code here was from my freshman undergraduate, and I won't be updating this project anymore unfortunately. This is for memento's sake and for assisting those who are interested.

**Motivation**

The goal of this project is to solve all possible combinations of variables for a given dataset. Ie, given that I have variables x1, x2, x3 as a dataset of [1, 2, 3], then what equations are possible for an answer of 9? In this case, we would say x3*x3 is possible. There are a total of 3^{2} combinations possible in this example -- can you see if it's possible to find an answer 9 given x1, x2, x3 datasets and 3^{2} possible solutions?

**How to use**

1. Download the Git folder, and run the program "numbers.ccp" 
2. In the prompt, insert the following:
  3.1:: "What result would you expect from the function? 
        I.e. insert a number that you expect from the function into console, i.e. 3."
        Say we wanted 9 as our end-answer from all of our possible products; we insert 9 and hit enter.
        
  3.2:: "How many variables do you want to use?"
        Say I wanted 3 variables total, x1, x2, x3. I input 3 to insert these 3 variables, which will intialize a 3x3 array for x1->x3.
        
  3.3:: Now insert the three numbers you want. For example above, input 1, then 2, then 3 to input x1=1, x2=2, x3=3.
  
  Now the terminal will output a matrix, whose form is below.
  
  [ x1 x2 x3
  x1 x2 x3
  x1 x2 x3 ]
  
  And will say
  
1 testing all possible values, coordinates are:: 00

2 testing all possible values, coordinates are:: 01

3 testing all possible values, coordinates are:: 02

4 testing all possible values, coordinates are:: 11

6 testing all possible values, coordinates are:: 12

9 testing all possible values, coordinates are:: 22

1 testing all possible values, coordinates are:: 00

0.5 testing all possible values, coordinates are:: 01

0.333333 testing all possible values, coordinates are:: 02

The left number of each one is just the result of multiplying the respective coordinate. Ie, given coordinate 02, we are multiplying x1 \[dot\] x3 = 1 \[dot\] 3 = 3 in this output example. As seen from the code, it will correctly identify that the only possible 'coordinate' is 22, corresponding to x3*x3. 

This project is quite old, but I do truly hope this will assist anyone's endeavors who are interested. Attached is the C++ code.

Best regards.
