#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    map<string, bool> map;
    string name;
    int N, M, count = 0;
    cin >> N >> M;

    while (N--) {
        cin >> name;
        map.insert({name, false});
    }
    while (M--) {
        cin >> name;
        if (map.find(name) != map.end()) {
            map[name] = true;
            count++;
        }
    }

    cout << count << "\n";
    for (auto it = map.begin(); it != map.end(); it++)
        if (it->second) cout << it->first << "\n";

    return 0;
}