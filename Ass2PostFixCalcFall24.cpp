#include <iostream>
#include <stack>
#include <string>
#include <cctype> 
#include <cmath>  // For extra math 
#include <stdexcept> // For stod exceptions, important

using namespace std;

// Displays the introduction
void showHelp() {
    cout << "Welcome to the postfix calculator. Enter integers and operators in postfix order.\n";
    cout << "Supported operators: +, -, *, /, abs, %, sin (for trigonometric calculations), and = \n";
}

// Check if the string is a valid number
bool isNumber(const string& s) {
    try {
        stod(s); // Attempt to convert the string to a double
        return true;
    } catch (invalid_argument&) {
        return false;
    }
}

// Main postfix function
void evaluatePostfix() {
    stack<double> calcStack; 
    string input;
    double operand1, operand2, result;

    while (true) {
        cout << "> ";
        cin >> input;

        // Check if the input is a number
        if (isNumber(input)) {
            // Convert the string to a double and push
            calcStack.push(stod(input));
        }
        // Check if the input is an operator
        else if (input == "+" || input == "-" || input == "*" || input == "/") {
            // Ensure there are at least two operands on the stack
            if (calcStack.size() < 2) {
                cout << "Error: Not enough operands.\n";
                continue;
            }

            // Pop the top two operands from the stack
            operand1 = calcStack.top(); calcStack.pop();
            operand2 = calcStack.top(); calcStack.pop();

            // Perform the operation based on the operator
            if (input == "+") result = operand2 + operand1;
            else if (input == "-") result = operand2 - operand1;
            else if (input == "*") result = operand2 * operand1;
            else if (input == "/") {
                if (operand1 == 0) {
                    cout << "Error: Division by zero.\n";
                    calcStack.push(operand2); // Push back operands
                    calcStack.push(operand1);
                    continue;
                }
                result = operand2 / operand1;
            }

            // Push the result back onto the stack
            calcStack.push(result);
        }
        // To check if problem should be solved
        else if (input == "=") {
            // Check if there's exactly one element in the stack
            if (calcStack.size() == 1) {
                cout << "The result is " << calcStack.top() << ".\n";
                calcStack.pop(); // Clear the result from the stack
            } else {
                cout << "Error: Malformed expression.\n";
            }
            break;
        }
        // Handle special functions
        else if (input == "abs") {
            if (calcStack.empty()) {
                cout << "Error: No operand for abs.\n";
            } else {
                operand1 = calcStack.top(); calcStack.pop();
                calcStack.push(fabs(operand1)); // Absolute value
            }
        }
        else if (input == "%") {
            if (calcStack.size() < 2) {
                cout << "Error: Not enough operands for modulus.\n";
                continue;
            }
            operand1 = calcStack.top(); calcStack.pop();
            operand2 = calcStack.top(); calcStack.pop();
            calcStack.push(fmod(operand2, operand1));
        } 
        else if (input == "sin") {
            if (calcStack.empty()) {
                cout << "Error: No operand for sin.\n";
            } else {
                operand1 = calcStack.top(); calcStack.pop();
                calcStack.push(sin(operand1)); // Sine operation
            }
        }
        // Handle invalid input
        else {
            cout << "Error: Invalid input.\n";
        }
    }
}

// Driver code
int main() {
    showHelp();
    evaluatePostfix();
    return 0;
}
