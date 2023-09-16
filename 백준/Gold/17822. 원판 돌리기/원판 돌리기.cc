#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Disks {
    int n, m;
    vector<vector<int>> nums;

   public:
    Disks(int n, int m, vector<vector<int>> nums) : n(n), m(m), nums(nums) {}

    void rotate(int x, int d, int k) {
        // 1. 회전
        for (int i = 1; i <= n; i++) {
            if (i % x != 0) continue;

            if (d == 0) {  // 시계 방향
                std::rotate(nums[i - 1].begin(), nums[i - 1].end() - k,
                            nums[i - 1].end());
            } else {  // 반시계 방향
                std::rotate(nums[i - 1].begin(), nums[i - 1].begin() + k,
                            nums[i - 1].end());
            }
        }

        // 2. 인접 수 제거
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};

        bool check = false;
        int sum = 0, count = 0;
        vector<vector<bool>> is_adjacent(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 0) continue;

                sum += nums[i][j];
                count++;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = (j + m + dy[k]) % m;
                    if (ni < 0 || ni >= n) continue;

                    if (nums[i][j] == nums[ni][nj]) {
                        is_adjacent[i][j] = is_adjacent[ni][nj] = true;
                        check = true;
                    }
                }
            }
        }

        if (check) {  // 2-1
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (is_adjacent[i][j]) nums[i][j] = 0;
        } else {  // 2-2
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (nums[i][j] == 0) continue;

                    if (nums[i][j] * count > sum)
                        nums[i][j]--;
                    else if (nums[i][j] * count < sum)
                        nums[i][j]++;
                }
            }
        }
    }

    int get_sum() {
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) sum += nums[i][j];
        return sum;
    }
};

int main() {
    FASTIO();
    int N, M, T, x, d, k;
    cin >> N >> M >> T;

    vector<vector<int>> nums(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) cin >> nums[i][j];

    Disks disks(N, M, nums);
    while (T--) {
        cin >> x >> d >> k;
        disks.rotate(x, d, k);
    }

    cout << disks.get_sum() << "\n";

    return 0;
}