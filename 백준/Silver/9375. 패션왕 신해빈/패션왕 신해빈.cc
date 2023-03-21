#include <iostream>
#include <map>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int T, n;
    string name, type;

    cin >> T;
    while (T--) {
        map<string, int> map;
        cin >> n;
        while (n--) {
            cin >> name >> type;
            if (map.find(type) != map.end())
                map[type]++;
            else
                map.insert({type, 1});
        }
        int result = 1;
        for (const auto& [type, value] : map) result *= (value + 1);
        cout << result - 1 << "\n";
    }

    return 0;
}