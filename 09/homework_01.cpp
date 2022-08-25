// Homework 1: Guess the output

#include<iostream>
using namespace std;

int main() {

	int a = 10, b = 20, c = 30, d = 40;

	cout << (a + b == c) << "\n";   //output: 1
	cout << (a + b + c >= 2 * d) << "\n"; //output: 0

	cout << (a > 5 || d < 30) << "\n"; //output: 1
	cout << (a > 5 && d < 30) << "\n"; //output: 0
	cout << (a <= b && b <= c) << "\n"; //output: 1

	cout << (a > 5 && d < 30 || c - b == 10) << "\n"; //output: 1
	cout << (a <= b && b <= c && c <= d) << "\n"; //output: 1

	cout << (a > 5 && d < 30 || c > d || d % 2 == 0) << "\n"; //output: 1
	cout << (a > 5 && d < 30 || c > d && d % 2 == 0) << "\n"; //output: 0

	cout << ( a == 10 || b != 20  && c != 30 || d != 40) << "\n"; //output: 1
	cout << ((a == 10 || b != 20) && c != 30 || d != 40) << "\n"; //output: 0

	return 0;
}

