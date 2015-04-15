# What is it?

This is a simple trainer in trigonometry.

The initial packet consists of 42 basic formulas.

You can practice or test yourself.


# Format of data file

\*first part\* = \*second part\*

(any spaces are ignored)


# Example of data file

sin(A)^2 + cos(A)^2 = 1

sin(2\*A)   = 2 * sin(A) * cos(A)

tg(2 \*    A) =2\*tg(A)    / ( 1 - tg(A)^2)


# Compiling

g++ -Wall -O2 main.cpp -o Trigonometry
