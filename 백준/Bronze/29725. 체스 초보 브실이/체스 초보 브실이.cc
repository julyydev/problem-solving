#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    char c;
    for (int i = 0; i < 64; i++) {
        cin >> c;
        if (c == 'P') sum += 1;
        else if (c == 'p') sum -= 1;
        else if (c == 'N') sum += 3;
        else if (c == 'n') sum -= 3;
        else if (c == 'B') sum += 3;
        else if (c == 'b') sum -= 3;
        else if (c == 'R') sum += 5;
        else if (c == 'r') sum -= 5;
        else if (c == 'Q') sum += 9;
        else if (c == 'q') sum -= 9;
    }
    cout << sum << "\n";
    
    return 0;
}