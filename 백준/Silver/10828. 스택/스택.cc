// https://www.acmicpc.net/problem/10828
// written by julyy

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int s;
int stack[10001];

void push(int x) {
    stack[s] = x;
    s++;
}

int pop() {
    if (s == 0)
        return -1;
    s--;
    return stack[s];
}

int size() {
    return s;
}

int empty() {
    if (s == 0)
        return 1;
    else
        return 0;
}

int top() {
    if (s == 0)
        return -1;
    return stack[s - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string command, num;
    cin >> n;

    s = 0;

    for (int i = 0; i <= n; i++) {
        getline(cin, command);
        if (command.length() > 5) { // push
            num = command.substr(5);
            push(stoi(num));
        }
        else if (command == "pop")
            cout << pop() << '\n';
        else if (command == "size")
            cout << size() << '\n';
        else if (command == "empty")
            cout << empty() << '\n';
        else if (command == "top")
            cout << top() << '\n';
    }
    
    return 0;
}
