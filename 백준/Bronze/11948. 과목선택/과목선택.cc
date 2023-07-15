#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    vector<int> science(4), society(2);

    for (int i = 0; i < 4; i++) cin >> science[i];
    for (int i = 0; i < 2; i++) cin >> society[i];
    sort(science.begin(), science.end(), greater<int>());
    sort(society.begin(), society.end(), greater<int>());

    cout << science[0] + science[1] + science[2] + society[0] << "\n";

    return 0;
}