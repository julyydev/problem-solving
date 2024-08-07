#include <iostream>
using namespace std;

int get_bit(char c) {
    return 1 << (c - 'a');
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    int bit = get_bit(s1[0]) + get_bit(s2[0]) + get_bit(s3[0]);
    if (bit == get_bit('l') + get_bit('k') + get_bit('p')) cout << "GLOBAL\n";
    else cout << "PONIX\n";
    
    return 0;
}