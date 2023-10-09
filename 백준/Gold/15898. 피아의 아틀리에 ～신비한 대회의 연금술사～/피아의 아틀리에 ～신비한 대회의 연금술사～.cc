#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

enum Color { R, B, G, Y, W };

struct Cell {
    int efficacy;
    Color element;
    Cell() : efficacy(0), element(Color::W) {}
    Cell(int efficacy, Color element) : efficacy(efficacy), element(element) {}
};

typedef vector<vector<Cell>> Material;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Kiln {
    int n;
    vector<vector<Material>> materials;

   public:
    Kiln() {}

   private:
    Color convertCharToColor(char c) {
        switch (c) {
            case 'R':
                return Color::R;
            case 'B':
                return Color::B;
            case 'G':
                return Color::G;
            case 'Y':
                return Color::Y;
            case 'W':
                return Color::W;
        }
        return Color::W;
    }

    void backtracking(vector<vector<Cell>> map, vector<bool>& is_added,
                      int& max_quality, int count) {
        if (count == 3) {
            max_quality = max(max_quality, calculate_quality(map));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (is_added[i]) continue;

            is_added[i] = true;

            for (int j = 0; j < 4; j++) {
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        vector<vector<Cell>> new_map =
                            add_material(map, materials[i][j], {x, y});
                        backtracking(new_map, is_added, max_quality, count + 1);
                    }
                }
            }

            is_added[i] = false;
        }
    }

    vector<vector<Cell>> add_material(vector<vector<Cell>> map,
                                      const Material& material,
                                      const Point& start) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                Point temp(start.x + i, start.y + j);

                map[temp.x][temp.y].efficacy += material[i][j].efficacy;
                if (map[temp.x][temp.y].efficacy < 0)
                    map[temp.x][temp.y].efficacy = 0;
                else if (map[temp.x][temp.y].efficacy > 9)
                    map[temp.x][temp.y].efficacy = 9;

                if (material[i][j].element == Color::W) continue;
                map[temp.x][temp.y].element = material[i][j].element;
            }
        }
        return map;
    }

    int calculate_quality(const vector<vector<Cell>>& map) {
        int quality = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                switch (map[i][j].element) {
                    case Color::R:
                        quality += 7 * map[i][j].efficacy;
                        break;
                    case Color::B:
                        quality += 5 * map[i][j].efficacy;
                        break;
                    case Color::G:
                        quality += 3 * map[i][j].efficacy;
                        break;
                    case Color::Y:
                        quality += 2 * map[i][j].efficacy;
                        break;
                    default:
                        break;
                }
            }
        }
        return quality;
    }

   public:
    void init() {
        cin >> n;
        vector<Material> init_materials(n);

        int q;
        char e;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> efficacies(4, vector<int>(4));
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) cin >> efficacies[j][k];

            vector<vector<char>> elements(4, vector<char>(4));
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++) cin >> elements[j][k];

            Material material(4, vector<Cell>(4));
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    material[j][k] = {efficacies[j][k],
                                      convertCharToColor(elements[j][k])};

            init_materials[i] = material;
        }

        materials.resize(n, vector<Material>(4));
        for (int i = 0; i < n; i++) {
            materials[i][0] = init_materials[i];
            for (int j = 1; j < 4; j++) {
                Material new_material(4, vector<Cell>(4));

                for (int x = 0; x < 4; x++) {
                    for (int y = 0; y < 4; y++) {
                        new_material[x][y] = materials[i][j - 1][3 - y][x];
                    }
                }
                materials[i][j] = new_material;
            }
        }
    }

    int get_max_quality() {
        int max_quality = 0;
        vector<bool> is_added(n, false);
        vector<vector<Cell>> map(5, vector<Cell>(5));

        backtracking(map, is_added, max_quality, 0);

        return max_quality;
    }
};

int main() {
    FASTIO();
    Kiln kiln;
    kiln.init();
    cout << kiln.get_max_quality() << "\n";

    return 0;
}
