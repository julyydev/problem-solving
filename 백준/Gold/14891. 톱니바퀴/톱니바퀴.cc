#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

enum Polarity { N, S };

class Gear {
    vector<Polarity> polarities;

   public:
    Gear() {}
    Gear(string s) {
        polarities.resize(8);
        for (int i = 0; i < 8; i++) {
            switch (s[i]) {
                case '0':
                    polarities[i] = Polarity::N;
                    break;
                case '1':
                    polarities[i] = Polarity::S;
                    break;
            }
        }
    }

    Polarity get_top() { return polarities[0]; }

    Polarity get_left() { return polarities[6]; }

    Polarity get_right() { return polarities[2]; }

    void turn(int direction) {
        if (direction == 1)
            rotate(polarities.begin(), polarities.end() - 1, polarities.end());
        else
            rotate(polarities.begin(), polarities.begin() + 1,
                   polarities.end());
    }
};

class Gears {
    vector<Gear> gears;

   public:
    Gears() {}

    void init() {
        gears.resize(4);
        string s;
        for (int i = 0; i < 4; i++) {
            cin >> s;
            gears[i] = Gear(s);
        }
    }

    void turn(int num, int direction) {
        vector<bool> is_connected(3, false);
        for (int i = 0; i < 3; i++) {
            if (gears[i].get_right() != gears[i + 1].get_left())
                is_connected[i] = true;
        }

        switch (num) {
            case 1: {
                gears[0].turn(direction);
                if (!is_connected[0]) return;
                gears[1].turn(-direction);
                if (!is_connected[1]) return;
                gears[2].turn(direction);
                if (!is_connected[2]) return;
                gears[3].turn(-direction);
                return;
            }
            case 2: {
                gears[1].turn(direction);
                if (is_connected[0]) gears[0].turn(-direction);
                if (!is_connected[1]) return;
                gears[2].turn(-direction);
                if (!is_connected[2]) return;
                gears[3].turn(direction);
                return;
            }
            case 3: {
                gears[2].turn(direction);
                if (is_connected[2]) gears[3].turn(-direction);
                if (!is_connected[1]) return;
                gears[1].turn(-direction);
                if (!is_connected[0]) return;
                gears[0].turn(direction);
                return;
            }
            case 4: {
                gears[3].turn(direction);
                if (!is_connected[2]) return;
                gears[2].turn(-direction);
                if (!is_connected[1]) return;
                gears[1].turn(direction);
                if (!is_connected[0]) return;
                gears[0].turn(-direction);
                return;
            }
        }
    }

    int get_score() {
        int score = 0;
        for (int i = 0; i < 4; i++) {
            if (gears[i].get_top() == Polarity::N) continue;
            score += 1 << i;
        }
        return score;
    }
};

int main() {
    FASTIO();
    Gears gears;
    gears.init();

    int K, num, direction;
    cin >> K;
    while (K--) {
        cin >> num >> direction;
        gears.turn(num, direction);
    }
    cout << gears.get_score() << "\n";

    return 0;
}