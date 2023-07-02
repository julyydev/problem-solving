#include <iostream>
using namespace std;

int main() {
    string mbti, s;
    int n, count = 0;
    cin >> mbti >> n;
    
    while (n--) {
        cin >> s;
        if (s == mbti) count++;
    }
    cout << count << "\n";
    
    return 0;
}