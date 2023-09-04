#include <iostream>
#include <map>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Position {
    int x, y;
    Position() {}
    Position(int x, int y) : x(x), y(y) {}

    bool operator<(const Position& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }

    bool operator==(const Position& p) const { return x == p.x && y == p.y; }
};

enum GameStatus {
    IN_GAME,
    WIN,
    DIE,
    END_INPUT,
};

class GameStatusManager {
    GameStatus game_status;
    string killed_by;

   public:
    GameStatusManager() : game_status(GameStatus::IN_GAME) {}

    bool is_in_game() { return game_status == GameStatus::IN_GAME; }

    bool is_boss_alive() {
        return game_status == GameStatus::DIE ||
               game_status == GameStatus::END_INPUT;
    }

    void set_win() { game_status = GameStatus::WIN; }

    void set_die(string name) {
        game_status = GameStatus::DIE;
        killed_by = name;
    }

    void set_end_input() { game_status = GameStatus::END_INPUT; }

    void print_game_status() {
        switch (game_status) {
            case GameStatus::IN_GAME:
                cout << "Game not ended!!!\n";
                break;
            case GameStatus::WIN:
                cout << "YOU WIN!\n";
                break;
            case GameStatus::DIE:
                cout << "YOU HAVE BEEN KILLED BY " << killed_by << "..\n";
                break;
            case GameStatus::END_INPUT:
                cout << "Press any key to continue.\n";
                break;
        }
    }
};

enum BattleStatus {
    BATTLE_WIN,
    BATTLE_LOSS,
};

enum CellType {
    EMPTY,
    WALL,
    ITEM,
    TRAP,
    MONSTER,
};

enum ItemType {
    WEAPON,
    ARMOR,
    ACCESSORY,
};

enum AccessoryEffect {
    HR,  // HP Regeneration - 전투에서 승리할 때
    RE,  // Reincarnation - 주인공이 사망했을 때
    CO,  // Courage - 모든 전투에서 첫 공격 시
    EX,  // Experience - 모든 얻는 경험치 -> 전투 승리 시
    DX,  // Dexterity - 가시 함정 시, CO와 함께 착용 시
    HU,  // Hunter - 보스 몬스터 전투 시
    CU,  // Cursed
};

class AccessoryInventory {
    set<AccessoryEffect> accessory_effects;

   public:
    AccessoryInventory() {}

    bool has_accessory(AccessoryEffect accessory_effect) {
        return accessory_effects.find(accessory_effect) !=
               accessory_effects.end();
    }

    void save_accessory(AccessoryEffect accessory_effect) {
        if (accessory_effects.size() == 4) return;
        if (has_accessory(accessory_effect)) return;

        accessory_effects.insert(accessory_effect);
    }

    void remove_accessory(AccessoryEffect accessory_effect) {
        accessory_effects.erase(accessory_effect);
    }
};

class Item {
    ItemType item_type;
    int value;

   public:
    Item() {}
    Item(ItemType item_type, int value) : item_type(item_type), value(value) {}

    ItemType get_item_type() { return item_type; }

    int get_value() { return value; }
};

class Character {
    Position position_start;
    Position position_cur;
    int level;
    int exp;
    int hp_max;
    int hp_cur;
    int atk;
    int def;

    int weapon_value;
    int armor_value;
    AccessoryInventory accessory_inventory;

   public:
    Character() {}
    Character(Position position_start)
        : position_start(position_start),
          position_cur(position_start),
          level(1),
          exp(0),
          hp_max(20),
          hp_cur(20),
          atk(2),
          def(2),
          weapon_value(0),
          armor_value(0) {}

    Position get_position_cur() { return position_cur; }

    void move(Position next) { position_cur = next; }

    void obtain_item(Item item) {
        switch (item.get_item_type()) {
            case ItemType::WEAPON:
                weapon_value = item.get_value();
                break;
            case ItemType::ARMOR:
                armor_value = item.get_value();
                break;
            case ItemType::ACCESSORY:
                accessory_inventory.save_accessory(
                    (AccessoryEffect)item.get_value());
                break;
        }
    }

    int get_total_atk() { return atk + weapon_value; }

    int get_total_def() { return def + armor_value; }

    void be_damaged(int damage) { hp_cur -= damage; }

    bool is_dead() { return hp_cur <= 0; }

    void obtain_exp(int value) {
        // EX: 얻는 경험치 1.2배
        if (has_accessory(AccessoryEffect::EX)) value = value * 12 / 10;
        exp += value;
        if (exp >= 5 * level) level_up();
    }

    void level_up() {
        level++;
        exp = 0;
        hp_max += 5;
        hp_cur = hp_max;
        atk += 2;
        def += 2;
    }

    bool has_accessory(AccessoryEffect accessory_effect) {
        return accessory_inventory.has_accessory(accessory_effect);
    }

    void hp_full_recovery() { hp_cur = hp_max; }

    void hp_regeneration() { hp_cur = min(hp_cur + 3, hp_max); }

    void reincarnation() {
        hp_full_recovery();
        position_cur = position_start;
        accessory_inventory.remove_accessory(AccessoryEffect::RE);
    }

    void print_status() {
        int hp_rem = max(hp_cur, 0);
        cout << "LV : " << level << "\n";
        cout << "HP : " << hp_rem << "/" << hp_max << "\n";
        cout << "ATT : " << atk << "+" << weapon_value << "\n";
        cout << "DEF : " << def << "+" << armor_value << "\n";
        cout << "EXP : " << exp << "/" << 5 * level << "\n";
    }
};

class Monster {
    int exp;
    int hp_max;
    int hp_cur;
    int atk;
    int def;
    string name;
    bool is_boss;

   public:
    Monster() {}
    Monster(int exp, int hp_max, int hp_cur, int atk, int def, string name,
            bool is_boss)
        : exp(exp),
          hp_max(hp_max),
          hp_cur(hp_cur),
          atk(atk),
          def(def),
          name(name),
          is_boss(is_boss) {}

    int get_total_atk() { return atk; }

    int get_total_def() { return def; }

    void be_damaged(int damage) { hp_cur -= damage; }

    bool is_dead() { return hp_cur <= 0; }

    string get_name() { return name; }

    bool check_is_boss() { return is_boss; }

    int get_exp() { return exp; }
};

class Game {
    int n, m;
    vector<vector<CellType>> cells;
    Character character;
    map<Position, Monster> monster_map;
    map<Position, Item> item_map;
    string directions;
    int passed_turns;
    GameStatusManager game_status_manager;
    Position boss_position;

   public:
    Game() {}

   private:
    void print_cells() {
        Position character_position = character.get_position_cur();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (game_status_manager.is_boss_alive() &&
                    boss_position.x == i && boss_position.y == j) {
                    cout << 'M';
                    continue;
                }

                if (!character.is_dead() && character_position.x == i &&
                    character_position.y == j) {
                    cout << '@';
                    continue;
                }

                switch (cells[i][j]) {
                    case CellType::EMPTY:  // 빈 칸
                        cout << '.';
                        break;
                    case CellType::WALL:  // 벽
                        cout << '#';
                        break;
                    case CellType::ITEM:  // 아이템 상자
                        cout << 'B';
                        break;
                    case CellType::TRAP:  // 가시 함정
                        cout << '^';
                        break;
                    case CellType::MONSTER:  // 몬스터
                        cout << '&';
                        break;
                }
            }
            cout << "\n";
        }
    }

    int get_index_by_direction(char d) {
        switch (d) {
            case 'R':
                return 0;
            case 'D':
                return 1;
            case 'L':
                return 2;
            case 'U':
                return 3;
        }
        return -1;
    }

    BattleStatus battle(Character& character, Monster& monster) {
        bool is_first_phase = true;
        int atk_multiple = 1;

        // HU: 보스 몬스터 전투 시 체력 회복
        if (monster.check_is_boss() &&
            character.has_accessory(AccessoryEffect::HU))
            character.hp_full_recovery();

        // CO: 전투 시 첫 공격 공격력 두 배
        if (character.has_accessory(AccessoryEffect::CO)) {
            // DX: CO와 함께 착용 시 공격력 세 배
            if (character.has_accessory(AccessoryEffect::DX))
                atk_multiple = 3;
            else
                atk_multiple = 2;
        }

        while (1) {
            if (is_first_phase) {
                monster.be_damaged(
                    max(1, character.get_total_atk() * atk_multiple -
                               monster.get_total_def()));
                if (monster.is_dead()) return BattleStatus::BATTLE_WIN;

                int monster_damage =
                    max(1, monster.get_total_atk() - character.get_total_def());

                // HU: 보스 몬스터 전투 시 첫 데미지 0
                if (monster.check_is_boss() &&
                    character.has_accessory(AccessoryEffect::HU))
                    monster_damage = 0;

                character.be_damaged(monster_damage);
                if (character.is_dead()) return BattleStatus::BATTLE_LOSS;

                is_first_phase = false;
                continue;
            }

            monster.be_damaged(
                max(1, character.get_total_atk() - monster.get_total_def()));
            if (monster.is_dead()) return BattleStatus::BATTLE_WIN;

            character.be_damaged(
                max(1, monster.get_total_atk() - character.get_total_def()));
            if (character.is_dead()) return BattleStatus::BATTLE_LOSS;
        }
    }

   public:
    void init() {
        cin >> n >> m;
        char c;
        int num_monsters = 0;
        int num_items = 0;
        Position character_position_start;

        cells.resize(n, vector<CellType>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                switch (c) {
                    case '@':  // 주인공
                        cells[i][j] = CellType::EMPTY;
                        character_position_start = {i, j};
                        break;
                    case '.':  // 빈 칸
                        cells[i][j] = CellType::EMPTY;
                        break;
                    case '#':  // 벽
                        cells[i][j] = CellType::WALL;
                        break;
                    case 'B':  // 아이템 상자
                        cells[i][j] = CellType::ITEM;
                        num_items++;
                        break;
                    case '^':  // 가시 함정
                        cells[i][j] = CellType::TRAP;
                        break;
                    case '&':  // 몬스터
                        cells[i][j] = CellType::MONSTER;
                        num_monsters++;
                        break;
                    case 'M':  // 보스 몬스터
                        cells[i][j] = CellType::MONSTER;
                        num_monsters++;
                        boss_position = {i, j};
                        break;
                }
            }
        }

        cin >> directions;

        int R, C, W, A, H, E;
        string S;
        for (int i = 0; i < num_monsters; i++) {
            cin >> R >> C >> S >> W >> A >> H >> E;
            Position position(R - 1, C - 1);
            monster_map.insert({position, Monster(E, H, H, W, A, S,
                                                  position == boss_position)});
        }

        char T;
        for (int i = 0; i < num_items; i++) {
            cin >> R >> C >> T >> S;
            Position position(R - 1, C - 1);
            switch (T) {
                case 'W':
                    item_map.insert(
                        {position, Item(ItemType::WEAPON, stoi(S))});
                    break;
                case 'A':
                    item_map.insert({position, Item(ItemType::ARMOR, stoi(S))});
                    break;
                case 'O':
                    if (S == "HR")
                        item_map.insert({position, Item(ItemType::ACCESSORY,
                                                        AccessoryEffect::HR)});
                    else if (S == "RE")
                        item_map.insert({position, Item(ItemType::ACCESSORY,
                                                        AccessoryEffect::RE)});
                    else if (S == "CO")
                        item_map.insert({position, Item(ItemType::ACCESSORY,
                                                        AccessoryEffect::CO)});
                    else if (S == "EX")
                        item_map.insert({position, Item(ItemType::ACCESSORY,
                                                        AccessoryEffect::EX)});
                    else if (S == "DX")
                        item_map.insert({position, Item(ItemType::ACCESSORY,
                                                        AccessoryEffect::DX)});
                    else if (S == "HU")
                        item_map.insert({position, Item(ItemType::ACCESSORY,
                                                        AccessoryEffect::HU)});
                    else if (S == "CU")
                        item_map.insert({position, Item(ItemType::ACCESSORY,
                                                        AccessoryEffect::CU)});
                    break;
            }
        }

        passed_turns = 0;

        character = Character(character_position_start);

        game_status_manager = GameStatusManager();
    }

    void play() {
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};

        for (char d : directions) {
            // 게임이 종료된 경우 중단
            if (!game_status_manager.is_in_game()) return;

            int i = get_index_by_direction(d);
            Position cur = character.get_position_cur();
            Position next(cur.x + dx[i], cur.y + dy[i]);

            // 그리드를 벗어나거나 벽을 향하는 경우 이동 X
            if ((next.x < 0 || next.x >= n || next.y < 0 || next.y >= m ||
                 cells[next.x][next.y] == CellType::WALL))
                next = cur;

            character.move(next);

            switch (cells[next.x][next.y]) {
                case CellType::ITEM: {
                    Item item = item_map[next];
                    character.obtain_item(item);
                    cells[next.x][next.y] = CellType::EMPTY;

                    break;
                }

                case CellType::TRAP: {
                    int trap_damage = 5;
                    // DX: 가시 함정 데미지 1 고정
                    if (character.has_accessory(AccessoryEffect::DX))
                        trap_damage = 1;
                    character.be_damaged(trap_damage);
                    if (character.is_dead()) {
                        // RE: 주인공 사망 시 1회 부활
                        if (character.has_accessory(AccessoryEffect::RE))
                            character.reincarnation();
                        else
                            game_status_manager.set_die("SPIKE TRAP");
                    }

                    break;
                }

                case CellType::MONSTER: {
                    Monster monster = monster_map[next];
                    BattleStatus battle_status = battle(character, monster);

                    if (battle_status == BattleStatus::BATTLE_WIN) {
                        if (monster.check_is_boss())
                            game_status_manager.set_win();
                        character.obtain_exp(monster.get_exp());

                        // HR: 전투에서 승리 시 체력 3 회복
                        if (character.has_accessory(AccessoryEffect::HR))
                            character.hp_regeneration();

                        cells[next.x][next.y] = CellType::EMPTY;
                    } else {
                        // RE: 주인공 사망 시 1회 부활
                        if (character.has_accessory(AccessoryEffect::RE))
                            character.reincarnation();
                        else
                            game_status_manager.set_die(monster.get_name());
                    }

                    break;
                }

                default:
                    break;
            }

            passed_turns++;
        }

        if (game_status_manager.is_in_game())
            game_status_manager.set_end_input();
    }

    void print_result() {
        print_cells();
        cout << "Passed Turns : " << passed_turns << "\n";
        character.print_status();
        game_status_manager.print_game_status();
    }
};

int main() {
    FASTIO();

    Game game;
    game.init();
    game.play();
    game.print_result();

    return 0;
}