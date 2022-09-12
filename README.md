# Equation-Reverse-Solver
Reverse solve any multiplication equation. Ie given 9, and assigning 3 variables 1,2,3, find the combination(s) possible to find 9.

How to use::
1. Download the Git folder, and run the program "numbers.ccp" 
2. Run program, if errors occur please send message
3. In insert variables, insert your:
  3.1:: "What result would you expect from the function? 
        I.e. insert a number that you expect from the function into console, i.e. 3."
        Say we wanted 9, we insert 9 and hit enter.
        
  3.2:: "How many variables do you want to use?"
        Say I wanted 3 variables, x1, x2, x3. I input 3.
        
  3.3:: Now insert the three numbers you want. For example above, input 1, then 2, then 3 to input x1=1, x2=2, x3=3.
  
  Now the terminal will output a matrix.
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

Meaning, in the matrix above, for value 1 for example, would be x1*x1 or coordinate 00. Since x1 = 1 in this case, 00 = 1 in this coordinate.

