#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<bool> isSubmit(31);
    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        isSubmit[n] = true;
    }

    for (int i = 1; i <= 30; i++)
        if (!isSubmit[i]) cout << i << "\n";

    return 0;
}
