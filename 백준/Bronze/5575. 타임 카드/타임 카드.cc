#include <iostream>
using namespace std;

int to_second(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

void get_time_card() {
    int h1, h2, m1, m2, s1, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int t = to_second(h2, m2, s2) - to_second(h1, m1, s1);
    int s = t % 60;
    t /= 60;
    int m = t % 60;
    t /= 60;
    int h = t;
    cout << h << ' ' << m << ' ' << s << '\n';
}

int main() {
    get_time_card();
    get_time_card();
    get_time_card();
    return 0;
}