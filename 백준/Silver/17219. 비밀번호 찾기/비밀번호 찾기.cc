#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;

    map<string, string> map;
    string site, password;
    while (N--) {
        cin >> site >> password;
        map.insert({site, password});
    }

    while (M--) {
        cin >> site;
        cout << map[site] << "\n";
    }

    return 0;
}