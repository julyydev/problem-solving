#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int w, h;
  cin >> w >> h;
  cout << ceil((double)(w * h) / 4840 / 5) << "\n";
  return 0;
}