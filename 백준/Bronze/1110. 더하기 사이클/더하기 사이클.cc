// https://www.acmicpc.net/problem/1110
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int n, c = 0;
    cin >> n;
    int newNumber = n;
    
    while(1) {
        newNumber = (newNumber % 10) * 10 + ((newNumber / 10) + (newNumber % 10)) % 10;
        c++;
        if (newNumber == n) {
            break;
        }
    }
    cout << c << "\n";

	return 0;
}
