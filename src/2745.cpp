// https://www.acmicpc.net/problem/2745
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string n;
    long b, result = 0, dim = 0;
    cin >> n >> b;

    for (int i = n.length() - 1; i >= 0; i--) {
        if (n[i] >= 'A' && n[i] <= 'Z')
            result += (n[i] - 'A' + 10) * pow(b, dim);
        else if (n[i] >= '0' && n[i] <= '9')
            result += (n[i] - '0') * pow(b, dim);
        dim++;
    }
    cout << result;
    
    return 0;
}
