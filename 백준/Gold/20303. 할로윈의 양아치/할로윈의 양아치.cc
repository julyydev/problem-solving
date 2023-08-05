#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct CandyGroup {
    int candy, people;
    CandyGroup() {}
    CandyGroup(int candy, int people) : candy(candy), people(people) {}
};

class DisjointSet {
    int n;
    vector<int> parents;

   public:
    DisjointSet(int n) : n(n), parents(n) {
        for (int i = 0; i < n; i++) parents[i] = i;
    }

    int find(int x) {
        if (x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }

    bool merge(int x, int y) {
        int px = find(x), py = find(y);

        if (px == py) return false;
        parents[px] = py;
        return true;
    }

    void print_parents() {
        for (int p : parents) cout << find(p) + 1 << " ";
        cout << "\n";
    }

    vector<CandyGroup> make_candy_group(const vector<int>& candies) {
        vector<CandyGroup> temp_candy_group(n, {0, 0});
        for (int i = 0; i < n; i++) {
            temp_candy_group[find(parents[i])].candy += candies[i];
            temp_candy_group[find(parents[i])].people++;
        }

        vector<CandyGroup> CandyGroup;
        for (int i = 0; i < n; i++) {
            if (temp_candy_group[i].people == 0) continue;
            CandyGroup.push_back(temp_candy_group[i]);
        }

        return CandyGroup;
    }
};

int main() {
    FASTIO();
    int N, M, K, a, b;
    cin >> N >> M >> K;

    vector<int> candies(N);
    for (int i = 0; i < N; i++) cin >> candies[i];

    DisjointSet ds(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ds.merge(a - 1, b - 1);
    }

    vector<CandyGroup> candy_group = ds.make_candy_group(candies);
    vector<int> dp(K, 0);

    for (int i = 0; i < candy_group.size(); i++) {
        for (int j = K - 1; j >= 0; j--) {
            if (candy_group[i].people <= j)
                dp[j] = max(dp[j], dp[j - candy_group[i].people] +
                                       candy_group[i].candy);
        }
    }

    cout << dp[K - 1] << "\n";

    return 0;
}