//////////////////////////
//   Greg Zubatov       //
//   Student ID ######  //
//   CS41 - 9/17/17     //
//   Professor: Lane    //
//////////////////////////
#include <iostream>
#include <string>
#include <iomanip>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList list; // create "stack" to store RPN input/calculations
	bool run = true; // program run/quit switch

	cout << "Welcome to Greg Zubatov's \"Reverse Polish Notation\" calculator." << endl;
	cout << "Please enter your operators and operands, each separated by a single space,"
		<< "\nand terminate the expression with an equals sign." << endl;
	cout << "Example: 2 2 + = will print out 4" << endl;
	cout << "Enter 0 by itself to exit program." << endl;

	while (run) {
		string input;			// user input
		double result{ 0 };
		int operands{ 0 };		// keeps track of valid # of operands
		int operators{ 0 };		// keeps track of valid # of operators

		cout << "\nEnter input: ";
		// while user hasn't entered 0 to quit or = to calculate RPN
		while (run == true && input != "=") {
			cin >> input;
			// Check for program quit parameter
			if (input == "0" && operands == 0) {
				run = false;
				break;
			}
			// if '=' then calculate RPN
			if (input == "=") {
				if ((operands - operators) > 1) {
					cout << "ERROR: Too many operands" << endl;
					// clear list for next round of RPN
					list.eraseList(list.head);
					break;
				}
				else if ((operands - operators) < 1) {
					cout << "ERROR: Too many operators" << endl;
					// clear list for next round of RPN
					list.eraseList(list.head);
					break;
				}
				else {
					string endResult = list.pop(list.head, list.tail);
					cout << fixed << setprecision(2);
					cout << stod(endResult) << endl;
					//break;
				}
			}
			// otherwise add input to linked list
			else {
				list.insert(list.head, list.tail, input);
				// keep track of operators & operands
				if (input == "+" || input == "-" || input == "*" || input == "/")
					operators++;
				else
					operands++;
			}

			// if input is an operator, pop previous 2 entries and process
			if (input == "+" || input == "-" || input == "*" || input == "/") {
				double result{ 0 };
				string operatorRPN = list.pop(list.head, list.tail);
				string secondNum = list.pop(list.head, list.tail);

				// check if operator is for division and if denominator is zero
				if (operatorRPN == "/" && secondNum == "0") {
					cout << "ERROR: Division by zero\n";
					// clear list for next round of RPN
					list.eraseList(list.head);
					// flush input stream
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					break;
					
				}

				// check if there is another element of list to pop
				if (list.isEmpty(list.head)) {
					cout << "ERROR: Too many operators\n";
					// flush input stream
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
				else {
					// pop next operand
					string firstNum = list.pop(list.head, list.tail);
					// process input
					if (operatorRPN == "+")
						result = stod(firstNum) + stod(secondNum);
					if (operatorRPN == "-")
						result = stod(firstNum) - stod(secondNum);
					if (operatorRPN == "*")
						result = stod(firstNum) * stod(secondNum);
					if (operatorRPN == "/")
						result = stod(firstNum) / stod(secondNum);
					// push result back onto list
					list.insert(list.head, list.tail, to_string(result));
				}
			}
		}
	}
	cout << "\nEXIT\n";
	system("pause");
}

// OUTPUT
/*
Welcome to Greg Zubatov's "Reverse Polish Notation" calculator.
Please enter your operators and operands, each separated by a single space,
and terminate the expression with an equals sign.
Example: 2 2 + = will print out 4
Enter 0 by itself to exit program.

Enter input: 10 15 + =
25.00

Enter input: 10 15 - =
-5.00

Enter input: 2.5 3.5 + =
6.00

Enter input: 10 0 / =
ERROR: Division by zero

Enter input: 10 20 * / =
ERROR: Too many operators

Enter input: 12 20 30 / =
ERROR: Too many operands

Enter input: -10 -30 - =
20.00

Enter input: 100 10 50 25 / * - -2 / =
-40.00

Enter input: 0

EXIT
*/

