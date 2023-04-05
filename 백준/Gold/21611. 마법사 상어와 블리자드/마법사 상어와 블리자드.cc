#include <deque>
#include <iostream>
#include <list>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Wizard {
    list<int> ice;
    vector<int> count;
    int n;

   public:
    Wizard(const vector<vector<int>>& init_ice, const int& N) : n(N) {
        init(init_ice);
        count.assign(4, 0);
    }

   private:
    void init(
        const vector<vector<int>>& init_ice) {  // 2차원 배열을 리스트로 변환
        int x = n / 2, y = n / 2;
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {-1, 0, 1, 0};

        int n = 1, i = 0;
        while (1) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < n; k++) {
                    x += dx[i], y += dy[i];
                    if (init_ice[x][y] == 0) return;
                    ice.push_back(init_ice[x][y]);
                    if (x == 0 && y == 0) return;
                }
                i = (i + 1) % 4;
            }
            n++;
        }
    }
    void destroy(int d, int s) {
        const int direction[5] = {0, 1, 5, 7, 3};  // x, ↑, ↓, ←, →
        deque<int> target;
        for (int i = 1; i <= s; i++)
            target.push_back((2 * i + 1) * (2 * i + 1) - i * direction[d] - 2);

        int i = 0, size = ice.size();
        for (auto it = ice.begin(); it != ice.end(); it++) {
            if (target.empty() || i == size) break;
            if (i == target.front()) {
                ice.erase(it--);
                target.pop_front();
            }
            i++;
        }
    }
    void explode() {
        bool isFinished = false;
        while (!isFinished) {
            isFinished = true;
            int num = 0, cnt = 0;
            auto it = ice.begin();
            while (it != ice.end()) {
                if (*it != num) {
                    if (cnt >= 4) {
                        isFinished = false;
                        it--;
                        for (int i = 0; i < cnt; i++) ice.erase(it--);
                        it++;
                        count[num] += cnt;
                    }
                    num = *it;
                    cnt = 1;
                } else
                    cnt++;
                it++;
            }
            if (cnt >= 4) {
                isFinished = false;
                it--;
                for (int i = 0; i < cnt; i++) ice.erase(it--);
                it++;
                count[num] += cnt;
            }
        }
    }
    void change() {
        if (ice.empty()) return;
        int num = 0, cnt = 0;
        auto it = ice.begin();
        while (it != ice.end()) {
            if (*it != num) {
                if (cnt != 0) {
                    it--;
                    for (int i = 0; i < cnt; i++) ice.erase(it--);
                    ice.insert(++it, cnt);
                    ice.insert(it, num);
                }
                num = *it;
                cnt = 1;
            } else
                cnt++;
            it++;
        }
        it--;
        for (int i = 0; i < cnt; i++) ice.erase(it--);
        ice.insert(++it, cnt);
        ice.insert(it, num);

        while (static_cast<int>(ice.size()) > n * n - 1) ice.pop_back();
    }

   public:
    void blizzard(int d, int s) {
        destroy(d, s);
        explode();
        change();
    }
    int result() {
        int result = 0;
        for (int i = 1; i <= 3; i++) result += i * count[i];
        return result;
    }
};

int main() {
    FASTIO();
    int N, M, d, s;
    cin >> N >> M;
    vector<vector<int>> init_ice(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> init_ice[i][j];

    Wizard wizard(init_ice, N);
    while (M--) {
        cin >> d >> s;
        wizard.blizzard(d, s);
    }
    cout << wizard.result() << "\n";

    return 0;
}