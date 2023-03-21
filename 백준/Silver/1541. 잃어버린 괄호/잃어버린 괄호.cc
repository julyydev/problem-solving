#include <iostream>
#include <sstream>
using namespace std;

int parsingAndAdd(string s) {
    int sum = 0;
    stringstream sstream(s);
    string buffer;
    while (getline(sstream, buffer, '+')) sum += stoi(buffer);

    return sum;
}

int parsingAndSubtract(string s) {
    stringstream sstream(s);
    string buffer;
    getline(sstream, buffer, '-');
    int sum = parsingAndAdd(buffer);
    while (getline(sstream, buffer, '-')) sum -= parsingAndAdd(buffer);

    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << parsingAndSubtract(s) << "\n";

    return 0;
}