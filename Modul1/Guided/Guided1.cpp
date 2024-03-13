#include <iostream>
using namespace std;
//Main Program
int main()
{
    char op;
    float num1, num2;
    //it allows user to enter operator i,e,+,-,*,/
    cin >> op;
    //it allows user to enter the operand
    cin >> num1 >> num2;
    //swicth statement begins
    switch (op)
    {
    //if user center +
    case '+':
        cout << num1+num2;
        break;
    //if user center -
    case '-':
        cout << num1-num2;
        break;
    //if user center *
    case '*':
        cout << num1*num2;
        break;
    //if user center 
    case '/':
        cout << num1/num2;
        break;
    // if the operator is other than =,-,*, or /
    //error massage will be display
    default:
        cout << "error! operator is not correct";
    } //switch statement ends
    return 0;
}