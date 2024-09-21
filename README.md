# postfixcalc
Postfix Calculator
The calculator should be able to do calculations on integers, using the operators +, -, *, /. With an ='s sign used to return the answer.

It should return an error message if an expression is malformed, i.e. doesn't have enough operands or operators.

The calculator should work by taking one input, an operator or an operand, at a time. Operators are our mathematical functions: +, -, *, /. Operands are what the operators are applied to, in this case numbers, although in other cases operands can include variables. Because the program gets both characters (+, -, ...) and numbers (5, 2.1, ...) you will need to use a string to get the input and then parse it. String functions like stod() or isdigit() can help.

For each input, if it's a numeric value it should be pushed onto the stack. If it's an operand it should be applied to the top two elements of the stack and the result should be pushed back onto the stack. If two values aren't available, the program should print an error message. 

When the user enters an = the stack should be checked. If it only has one element that value should be returned as the answer. Otherwise, it should report an error. 

The program should begin by printing a brief explanation of how it works and what the available operators are.
