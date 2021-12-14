// https://www.acmicpc.net/problem/1008
// written by julyy

/*
소숫점 자리수 표시
*/

#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;

    cout.precision(12);
    cout << fixed;
    cout << a / b << endl;

	return 0;
}
