#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    for (auto c : s) {
        if (c == '0') {
            cout << "0000\n";
            cout << "0  0\n";
            cout << "0  0\n";
            cout << "0  0\n";
            cout << "0000\n";
            cout << "\n";
        }
        else if (c == '1') {
            cout << "   1\n";
            cout << "   1\n";
            cout << "   1\n";
            cout << "   1\n";
            cout << "   1\n";
            cout << "\n";
        }
        else if (c == '2') {
            cout << "2222\n";
            cout << "   2\n";
            cout << "2222\n";
            cout << "2\n";
            cout << "2222\n";
            cout << "\n";
        }
        else if (c == '3') {
            cout << "3333\n";
            cout << "   3\n";
            cout << "3333\n";
            cout << "   3\n";
            cout << "3333\n";
            cout << "\n";
        }
        else if (c == '4') {
            cout << "4  4\n";
            cout << "4  4\n";
            cout << "4444\n";
            cout << "   4\n";
            cout << "   4\n";
            cout << "\n";
        }
        else if (c == '5') {
            cout << "5555\n";
            cout << "5\n";
            cout << "5555\n";
            cout << "   5\n";
            cout << "5555\n";
            cout << "\n";
        }        
        else if (c == '6') {
            cout << "6666\n";
            cout << "6\n";
            cout << "6666\n";
            cout << "6  6\n";
            cout << "6666\n";
            cout << "\n";
        } 
        else if (c == '7') {
            cout << "7777\n";
            cout << "   7\n";
            cout << "   7\n";
            cout << "   7\n";
            cout << "   7\n";
            cout << "\n";
        }      
        else if (c == '8') {
            cout << "8888\n";
            cout << "8  8\n";
            cout << "8888\n";
            cout << "8  8\n";
            cout << "8888\n";
            cout << "\n";
        }
        else if (c == '9') {
            cout << "9999\n";
            cout << "9  9\n";
            cout << "9999\n";
            cout << "   9\n";
            cout << "   9\n";
            cout << "\n";
        }
    }
    
    return 0;
}