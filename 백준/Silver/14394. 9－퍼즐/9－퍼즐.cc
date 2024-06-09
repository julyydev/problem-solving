#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string init, target;
    cin >> init >> target;

    unordered_map<char, int> initCount, targetCount;
    initCount['R'] = initCount['G'] = initCount['B'] = initCount['Y'] = 0;
    targetCount['R'] = targetCount['G'] = targetCount['B'] = targetCount['Y'] =
        0;

    for (char color : init) {
        if (initCount.find(color) != initCount.end()) {
            initCount[color]++;
        }
    }

    for (char color : target) {
        if (targetCount.find(color) != targetCount.end()) {
            targetCount[color]++;
        }
    }

    int changes = 0;
    for (char color : {'R', 'G', 'B', 'Y'}) {
        changes += max(targetCount[color] - initCount[color], 0);
    }

    cout << changes << "\n";
    return 0;
}
