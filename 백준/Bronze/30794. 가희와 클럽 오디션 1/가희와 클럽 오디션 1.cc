#include <iostream>
using namespace std;

int main() {
	int x;
	string s;
	cin >> x >> s;
    
	if (s == "miss") cout << 0 << "\n";
	else if (s == "bad") cout << x * 200 << "\n";
	else if (s == "cool") cout << x * 400 << "\n";
	else if (s == "great") cout << x * 600 << "\n";
	else if (s == "perfect") cout << x * 1000 << "\n";
}