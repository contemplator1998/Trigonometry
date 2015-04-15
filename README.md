This is a basic formalas trainer in trigonometry
The initial packet consists of 42 main formulas
You can practice or test yourself

"data" file contains equations in format as follows:
*first part* = *second part*
(any spaces are ignored)

Example of data file:

sin(A)^2 + cos(A)^2 = 1
sin(2*A)   = 2 * sin(A) * cos(A)
tg(2 *    A) =2*tg(A)    / ( 1 - tg(A)^2)

To compile the source code:
g++ -Wall -O2 main.cpp -o Trigonometry