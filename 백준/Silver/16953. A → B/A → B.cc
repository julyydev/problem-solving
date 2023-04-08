#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int count = 1;

    while (A != B) {
        if (B % 2 == 1) {
            if (B % 10 == 1) {
                B /= 10;
                count++;
            } else {
                count = -1;
                break;
            }
        } else {
            B /= 2;
            count++;
        }

        if (A > B) {
            count = -1;
            break;
        }
    }

    cout << count << "\n";

    return 0;
}