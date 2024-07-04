#include <iostream>
using namespace std;

int main() {
    int max_count = 0, count;
    string max_name, name;
    for (int i = 0; i < 7; i++) {
        cin >> name >> count;
        if (count > max_count) {
            max_count = count;
            max_name = name;
        }
    }
    cout << max_name << "\n";
    
    return 0;
}