// https://www.acmicpc.net/problem/10866
// written by julyy

#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;
    string command;

    deque<int> deq;

    for (int i = 0; i < n; i++) {
        cin >> command;

        if (command == "push_front") {
            cin >> x;
            deq.push_front(x);
        }
        else if (command == "push_back") {
            cin >> x;
            deq.push_back(x);
        }
        else if (command == "pop_front") {
            if (deq.empty())
                cout << "-1\n";
            else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if (command == "pop_back") {
            if (deq.empty())
                cout << "-1\n";
            else {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        else if (command == "size") {
            cout << deq.size() << '\n';
        }
        else if (command == "empty") {
            if (deq.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (command == "front") {
            if (deq.empty())
                cout << "-1\n";
            else {
                cout << deq.front() << '\n';
            }
        }
        else if (command == "back") {
            if (deq.empty())
                cout << "-1\n";
            else {
                cout << deq.back() << '\n';
            }
        }
    }
    
    return 0;
}
