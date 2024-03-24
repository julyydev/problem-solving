#include <deque>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, k;
    cin >> n >> k;

    vector<int> names(k);
    unordered_map<int, deque<int>> um;
    for (int i = 0; i < k; i++) {
        cin >> names[i];
        if (um.find(names[i]) == um.end())
            um.insert({names[i], {i}});
        else
            um.at(names[i]).push_back(i);
    }

    int pop_count = 0;
    unordered_set<int> us;
    for (int name : names) {
        um.at(name).pop_front();

        if (us.find(name) != us.end()) continue;

        if (us.size() < n) {
            us.insert(name);
            continue;
        }

        int target, target_next = 0;
        for (int s : us) {
            if (um.at(s).empty()) {
                target = s;
                break;
            }

            if (um.at(s).front() > target_next) {
                target = s;
                target_next = um.at(s).front();
            }
        }
        us.erase(target);
        us.insert(name);
        pop_count++;
    }

    cout << pop_count << "\n";

    return 0;
}