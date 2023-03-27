#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

enum Direction { U, D, F, B, L, R };
enum Color { w, y, r, o, g, b };

string colorToString(Color color) {
    string colors[6] = {"w", "y", "r", "o", "g", "b"};
    return colors[color];
}

string directionToString(Direction direction) {
    string directions[6] = {"U", "D", "F", "B", "L", "R"};
    return directions[direction];
}

string getColorAsDirection(Direction direction) {
    string colors[6] = {"w", "y", "r", "o", "g", "b"};
    return colors[direction];
}

Direction stringToDirection(string s_direction) {
    if (s_direction == "U")
        return U;
    else if (s_direction == "D")
        return D;
    else if (s_direction == "F")
        return F;
    else if (s_direction == "B")
        return B;
    else if (s_direction == "L")
        return L;
    return R;
}

class Cell {
    Color color;
    Direction direction;

   public:
    Cell(Color color, Direction direction)
        : color(color), direction(direction) {}
    Color getColor() { return color; }
    Direction getDirection() { return direction; }
};

class Edge {
    vector<Cell> edge;

   public:
    Edge(vector<Cell> edge) : edge(edge) {}
    bool isContainDirection(const Direction& direction) {
        for (auto cell : edge)
            if (cell.getDirection() == direction) return true;
        return false;
    }
    Direction getSubDirection(const Direction& base) {
        for (auto cell : edge)
            if (cell.getDirection() != base) return cell.getDirection();
        return U;
    }
    vector<Cell> getCells() { return edge; }
};

class Corner {
    vector<Cell> corner;

   public:
    Corner(vector<Cell> corner) : corner(corner) {}
    bool isContainDirection(const Direction& direction) {
        for (auto cell : corner)
            if (cell.getDirection() == direction) return true;
        return false;
    }
    vector<Direction> getSubDirections(const Direction& base) {
        vector<Direction> d;
        for (auto cell : corner)
            if (cell.getDirection() != base) d.push_back(cell.getDirection());
        return d;
    }
    vector<Cell> getCells() { return corner; }
};

class Face {
    Direction base;
    vector<Edge*> edgePointers;
    vector<Corner*> cornerPointers;

   public:
    Face(const Direction& base, vector<Edge>& edges, vector<Corner>& corners,
         const vector<vector<Direction>>& direction_graph)
        : base(base) {
        edgePointers.resize(4);
        for (Edge& edge : edges) {
            if (edge.isContainDirection(base)) {
                auto it = find(direction_graph[base].begin(),
                               direction_graph[base].end(),
                               edge.getSubDirection(base));
                edgePointers[distance(direction_graph[base].begin(), it)] =
                    &edge;
            }
        }
        cornerPointers.resize(4);
        for (Corner& corner : corners) {
            if (corner.isContainDirection(base)) {
                vector<Direction> ds = corner.getSubDirections(base);
                int check = 1;
                for (Direction d : ds) {
                    auto it = find(direction_graph[base].begin(),
                                   direction_graph[base].end(), d);
                    check *= (distance(direction_graph[base].begin(), it) + 1);
                }
                if (check == 2)
                    cornerPointers[0] = &corner;
                else if (check == 6)
                    cornerPointers[1] = &corner;
                else if (check == 12)
                    cornerPointers[2] = &corner;
                else
                    cornerPointers[3] = &corner;
            }
        }
    }
    void printFace(const vector<vector<Direction>>& direction_graph) {
        vector<vector<string>> colors(3, vector<string>(3, "-"));
        colors[1][1] = getColorAsDirection(base);

        for (Edge* edgePointer : edgePointers) {
            vector<Cell> cells = edgePointer->getCells();
            string c;
            int index;
            for (Cell cell : cells) {
                if (cell.getDirection() == base) {
                    c = colorToString(cell.getColor());
                } else {
                    auto it =
                        find(direction_graph[base].begin(),
                             direction_graph[base].end(), cell.getDirection());
                    index = distance(direction_graph[base].begin(), it);
                }
            }
            if (index == 0)
                colors[0][1] = c;
            else if (index == 1)
                colors[1][2] = c;
            else if (index == 2)
                colors[2][1] = c;
            else if (index == 3)
                colors[1][0] = c;
        }

        for (Corner* cornerPointer : cornerPointers) {
            vector<Cell> cells = cornerPointer->getCells();
            string c;
            int check = 1;
            for (Cell cell : cells) {
                if (cell.getDirection() == base) {
                    c = colorToString(cell.getColor());
                } else {
                    vector<Direction> ds =
                        cornerPointer->getSubDirections(base);
                    for (Direction d : ds) {
                        auto it = find(direction_graph[base].begin(),
                                       direction_graph[base].end(), d);
                        check *=
                            (distance(direction_graph[base].begin(), it) + 1);
                    }
                }
            }
            if (check == 4)
                colors[0][2] = c;
            else if (check == 36)
                colors[2][2] = c;
            else if (check == 144)
                colors[2][0] = c;
            else
                colors[0][0] = c;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) cout << colors[i][j];
            cout << "\n";
        }
    }
    Direction getNextDirection(
        Direction target, bool isClockwise,
        const vector<vector<Direction>>& direction_graph) {
        if (isClockwise) {  // 시계
            auto it = find(direction_graph[base].begin(),
                           direction_graph[base].end(), target);
            if (it + 1 == direction_graph[base].end())
                return direction_graph[base].front();
            else
                return *(it + 1);
        } else {  // 반시계
            auto it = find(direction_graph[base].begin(),
                           direction_graph[base].end(), target);
            if (it == direction_graph[base].begin())
                return direction_graph[base].back();
            return *(it - 1);
        }
    }
    void turn(bool isClockwise,
              const vector<vector<Direction>>& direction_graph) {
        vector<vector<Cell>> newEdges;
        for (Edge* edgePointer : edgePointers) {
            Edge temp = *edgePointer;
            vector<Cell> cells = temp.getCells();
            vector<Cell> newCells;
            for (Cell cell : cells) {
                if (cell.getDirection() == base) {
                    newCells.push_back(cell);
                } else {
                    newCells.push_back(
                        {cell.getColor(),
                         getNextDirection(cell.getDirection(), isClockwise,
                                          direction_graph)});
                }
            }
            newEdges.push_back(newCells);
        }
        int i = 1 + (isClockwise ? 2 : 0);
        for (Edge* edgePointer : edgePointers) {
            *edgePointer = newEdges[i % 4];
            i++;
        }

        vector<vector<Cell>> newCorners;
        for (Corner* cornerPointer : cornerPointers) {
            vector<Cell> cells = cornerPointer->getCells();
            vector<Cell> newCells;
            for (Cell cell : cells) {
                if (cell.getDirection() == base) {
                    newCells.push_back(cell);
                } else {
                    newCells.push_back(
                        {cell.getColor(),
                         getNextDirection(cell.getDirection(), isClockwise,
                                          direction_graph)});
                }
            }
            newCorners.push_back(newCells);
        }
        i = 1 + (isClockwise ? 2 : 0);
        for (Corner* cornerPointer : cornerPointers) {
            *cornerPointer = newCorners[i % 4];
            i++;
        }
    }
};

class Cube {
    vector<Edge> edges = {
        Edge({{w, U}, {r, F}}), Edge({{w, U}, {b, R}}), Edge({{w, U}, {o, B}}),
        Edge({{w, U}, {g, L}}), Edge({{r, F}, {b, R}}), Edge({{b, R}, {o, B}}),
        Edge({{o, B}, {g, L}}), Edge({{g, L}, {r, F}}), Edge({{y, D}, {r, F}}),
        Edge({{y, D}, {b, R}}), Edge({{y, D}, {o, B}}), Edge({{y, D}, {g, L}})};
    vector<Corner> corners = {
        Corner({{w, U}, {o, B}, {b, R}}), Corner({{w, U}, {b, R}, {r, F}}),
        Corner({{w, U}, {r, F}, {g, L}}), Corner({{w, U}, {g, L}, {o, B}}),
        Corner({{y, D}, {o, B}, {g, L}}), Corner({{y, D}, {b, R}, {o, B}}),
        Corner({{y, D}, {r, F}, {b, R}}), Corner({{y, D}, {g, L}, {r, F}})};
    const vector<vector<Direction>> graph = {{B, R, F, L}, {F, R, B, L},
                                             {U, R, D, L}, {U, L, D, R},
                                             {U, F, D, B}, {U, B, D, F}};
    vector<Face> faces;

   public:
    Cube() {
        faces.push_back(Face(U, edges, corners, graph));
        faces.push_back(Face(D, edges, corners, graph));
        faces.push_back(Face(F, edges, corners, graph));
        faces.push_back(Face(B, edges, corners, graph));
        faces.push_back(Face(L, edges, corners, graph));
        faces.push_back(Face(R, edges, corners, graph));
    }
    void printUpSide() { faces[U].printFace(graph); }
    void turn(Direction base, bool isClockwise) {
        faces[base].turn(isClockwise, graph);
    }
    void clockwise(Direction base) {}
    void counterclockwise() {}
};

int main() {
    FASTIO();
    int T, n;
    string cmd;
    cin >> T;

    while (T--) {
        Cube cube{};
        cin >> n;
        while (n--) {
            cin >> cmd;
            cube.turn(stringToDirection(cmd.substr(0, 1)),
                      cmd.substr(1, 1) == "+");
        }
        cube.printUpSide();
    }

    return 0;
}