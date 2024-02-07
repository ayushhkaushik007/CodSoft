#include <iostream>

using namespace std;

int main() {
    float num1, num2, result;
    char operation;
    bool continueCalculations = true;
    while (continueCalculations) {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
        cout << "Select operation (+, -, *, /): ";
        cin >> operation;
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Cannot divide by zero." << endl;
                    continue;
                }
                break;
            default:
                cout << "Invalid operation. Please choose a valid operation." << endl;
                continue;
        }

        cout << "Result: " << result << endl;
        cout << "Do you want to perform another calculation? (y/n): ";
        char choice;
        cin >> choice;
        continueCalculations = (choice == 'y' || choice == 'Y');
    }
    return 0;
}
