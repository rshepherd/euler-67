Euler67
=======

A solution in C++ to the problem 67 of Project Euler found at http://projecteuler.net/index.php?section=problems&id=67

By starting at the top of the triangle below and moving to adjacent numbers on the row below, 
the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt, a 15K text file containing a triangle with one-hundred rows.

It is not possible to try every route to solve this problem, as there are 299 altogether! 
If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. 

This solution is a more efficient solution.

This algorithm begins with the base of the triangle and 'rolls up' the rows into the one above by comparing 
each row's elements to its immediate neighbor choosing the one with the higher value and adding that to the 
shared adjacent element in the next row. 

This continues until the 'top' of the triangle is reached.

Assumptions: The input file is in perfect format containing only positive integers and spaces in a 'triangle' format
like the included sample file.