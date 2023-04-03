#include <deque>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int durability;
    bool isRobot;
    Data() {}
    Data(int durability, bool isRobot)
        : durability(durability), isRobot(isRobot) {}
};

class Container {
    deque<Data> top_container, bottom_container;
    int size, num_of_zero = 0;

   public:
    Container(deque<Data> container, int n) : size(n) {
        for (int i = 0; i < n; i++) {
            top_container.push_back(container.front());
            container.pop_front();
        }
        for (int i = 0; i < n; i++) {
            bottom_container.push_back(container.front());
            container.pop_front();
        }
    }
    void rotate() {
        top_container.push_front(bottom_container.back());
        bottom_container.pop_back();
        bottom_container.push_front(top_container.back());
        top_container.pop_back();
        if (top_container.back().isRobot) down();
    }
    void moveAllRobots() {
        for (auto it = top_container.end() - 2; it != top_container.begin() - 1;
             it--) {
            if (!(*it).isRobot) continue;
            if (!(*(it + 1)).isRobot && (*(it + 1)).durability > 0) {
                (*it).isRobot = false;
                (*(it + 1)).durability--;
                if ((*(it + 1)).durability == 0) num_of_zero++;
                (*(it + 1)).isRobot = true;
            }

            if ((it + 1) == top_container.end() - 1) down();
        }
    }
    void lift() {
        if (top_container.front().durability != 0) {
            top_container.front().durability--;
            if (top_container.front().durability == 0) num_of_zero++;
            top_container.front().isRobot = true;
        }
    }
    void down() { top_container.back().isRobot = false; }
    int getNumOfZero() { return num_of_zero; }
};

int main() {
    FASTIO();
    int N, K, A;
    cin >> N >> K;
    deque<Data> init_container;
    for (int i = 0; i < 2 * N; i++) {
        cin >> A;
        init_container.push_back({A, false});
    }
    Container container(init_container, N);

    int count = 0;
    while (1) {
        count++;
        container.rotate();
        container.moveAllRobots();
        container.lift();
        if (container.getNumOfZero() >= K) break;
    }
    cout << count << "\n";

    return 0;
}