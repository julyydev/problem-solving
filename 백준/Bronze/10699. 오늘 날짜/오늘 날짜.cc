#include <ctime>
#include <iostream>
using namespace std;

int main() {
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    cout << t->tm_year + 1900 << "-" << (t->tm_mon < 9 ? "0" : "")
         << t->tm_mon + 1 << "-" << t->tm_mday << "\n";

    return 0;
}