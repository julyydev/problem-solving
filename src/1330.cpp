// https://www.acmicpc.net/problem/1330
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << "<" << endl;
    }
    else if (a > b) {
        cout << ">" << endl;
    }
    else {
        cout << "==" << endl;
    }

	return 0;
}
