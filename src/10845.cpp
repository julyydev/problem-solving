// https://www.acmicpc.net/problem/10845
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

vector<int> queue;

void push(int x) {
    queue.push_back(x);
}

int pop() {
    if (queue.size() == 0)
        return -1;
    int ret = queue.front();
    queue.erase(queue.begin());
    return ret;
}

int size() {
    return queue.size();
}

int empty() {
    if (queue.size() == 0)
        return 1;
    else
        return 0;
}

int front() {
    if (queue.size() == 0)
        return -1;
    return queue.front();
}

int back() {
    if (queue.size() == 0)
        return -1;
    return queue.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;
    string command;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            cin >> x;
            push(x);
        }
        else if (command == "pop")
            cout << pop() << '\n';
        else if (command == "size")
            cout << size() << '\n';
        else if (command == "empty")
            cout << empty() << '\n';
        else if (command == "front")
            cout << front() << '\n';
        else if (command == "back")
            cout << back() << '\n';
    }
    
    return 0;
}
