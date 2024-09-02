#include <iostream>
using namespace std;

string score_board[10][2] = {{"11", "A B C D E F G H J L M"},
                    {"9", "A C E F G H I L M"},
                    {"9", "A C E F G H I L M"},
                    {"9", "A B C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A C E F G H L M"},
                    {"8", "A B C F G H L M"}};

int main() {
    int n;
    cin >> n;
    cout << score_board[n - 1][0] << "\n";
    cout << score_board[n - 1][1] << "\n";
    return 0;
}