#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    if (s.length() <= 2 || !(s.front() == '\"' && s.back() == '\"')) {
        cout << "CE";
        return 0;
    }
    
    for (int i = 1; i < s.length() - 1; ++i) {
        cout << s[i];
    }
    
    return 0;
}