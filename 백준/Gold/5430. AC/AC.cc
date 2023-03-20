#include <deque>
#include <iostream>
#include <sstream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

deque<int> parsingArray(string array_s) {
    deque<int> dq;
    stringstream sstream(array_s.substr(1, array_s.length() - 2));
    string buffer;
    while (getline(sstream, buffer, ',')) dq.push_back(stoi(buffer.c_str()));
    return dq;
}

int main() {
    FASTIO();
    int T;
    cin >> T;

    while (T--) {
        int n;
        string cmd, array_s;
        bool isFront = true, isError = false;

        cin >> cmd >> n >> array_s;
        deque<int> dq = parsingArray(array_s);

        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R')
                isFront = !isFront;
            else if (cmd[i] == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                }

                if (isFront)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (isError)
            cout << "error\n";
        else {
            cout << "[";
            if (isFront) {
                for (int i = 0; i < (int)dq.size() - 1; i++)
                    cout << dq[i] << ",";
                if (!dq.empty()) cout << dq[dq.size() - 1];
            } else {
                for (int i = (int)dq.size() - 1; i > 0; i--)
                    cout << dq[i] << ",";
                if (!dq.empty()) cout << dq[0];
            }
            cout << "]\n";
        }
    }

    return 0;
}