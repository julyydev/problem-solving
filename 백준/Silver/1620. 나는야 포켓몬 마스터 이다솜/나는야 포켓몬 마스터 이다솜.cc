#include <iostream>
#include <map>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    map<string, int> map;
    vector<string> vec;
    string s;
    int N, M;
    cin >> N >> M;

    int id = 1;
    while (N--) {
        cin >> s;
        map.insert({s, id++});
        vec.push_back(s);
    }

    while (M--) {
        cin >> s;
        int x = atoi(s.c_str());
        if (x)
            cout << vec[x - 1] << "\n";
        else
            cout << map[s] << "\n";
    }

    return 0;
}