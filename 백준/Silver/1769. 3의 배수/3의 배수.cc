#include <iostream>
using namespace std;

string get_sum_of_digits(string n) {
    int sum = 0;
    
    for (auto c : n)
        sum += c - '0';
    
    return to_string(sum);
}

int main() {
    string x;
    cin >> x;
    
    int count = 0;
    while (x.length() > 1) {
        x = get_sum_of_digits(x);
        count++;
    }
    
    cout << count << "\n";
    if (x == "3" || x == "6" || x == "9")
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}