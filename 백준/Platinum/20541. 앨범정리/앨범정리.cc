#include <iostream>
#include <map>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Directory {
    string name;
    Directory* parent_directory;
    map<string, Directory*> child_directories;
    set<string> photos;

   public:
    Directory() {}
    Directory(string name, Directory* parent_directory)
        : name(name), parent_directory(parent_directory) {}

    string get_name() { return name; }

    Directory* get_parent_directory() { return parent_directory; }

    Directory* get_child_directory(string name) {
        if (child_directories.find(name) == child_directories.end())
            return nullptr;
        else
            return child_directories[name];
    }

    map<string, Directory*> get_child_directories() {
        return child_directories;
    }

    void make_child_directory(string name, Directory* parent) {
        Directory* new_child_directory = new Directory(name, parent);
        child_directories.insert({name, new_child_directory});
    }

    void recursion(Directory* directory, int& d_size, int& p_size) {
        d_size += directory->get_child_directories().size();
        p_size += directory->get_photos_number();
        if (directory->get_child_directories().empty()) return;

        for (auto d : directory->get_child_directories())
            recursion(d.second, d_size, p_size);
    }

    pair<int, int> remove_child_directory(string name) {
        if (child_directories.find(name) == child_directories.end())
            return {0, 0};

        int d_size = 1, p_size = 0;
        recursion(child_directories[name], d_size, p_size);
        child_directories.erase(name);
        return {d_size, p_size};
    }

    pair<int, int> remove_first_child_directory() {
        if (child_directories.empty()) return {0, 0};

        int d_size = 1, p_size = 0;
        recursion(child_directories.begin()->second, d_size, p_size);
        child_directories.erase(child_directories.begin());
        return {d_size, p_size};
    }

    pair<int, int> remove_all_child_directory() {
        int d_size = child_directories.size(), p_size = 0;
        for (auto c : child_directories) recursion(c.second, d_size, p_size);
        child_directories.clear();
        return {d_size, p_size};
    }

    pair<int, int> remove_last_child_directory() {
        if (child_directories.empty()) return {0, 0};

        int d_size = 1, p_size = 0;
        recursion(prev(child_directories.end())->second, d_size, p_size);
        child_directories.erase(prev(child_directories.end()));
        return {d_size, p_size};
    }

    bool has_photo(string name) {
        if (photos.find(name) == photos.end()) return false;
        return true;
    }

    void insert_photo(string name) { photos.insert(name); }

    int get_photos_number() { return photos.size(); }

    int delete_photo(string name) {
        if (photos.find(name) == photos.end()) return 0;
        photos.erase(name);
        return 1;
    }

    int delete_first_photo() {
        if (photos.empty()) return 0;
        photos.erase(photos.begin());
        return 1;
    }

    int delete_all_photo() {
        int size = get_photos_number();
        photos.clear();
        return size;
    }

    int delete_last_photo() {
        if (photos.empty()) return 0;
        photos.erase(prev(photos.end()));
        return 1;
    }
};

class Album {
    Directory* current_directory;
    Directory* root_directory;

   public:
    Album() {
        root_directory = new Directory("album", nullptr);
        current_directory = root_directory;
    }

    void make_album(string s) {
        if (current_directory->get_child_directory(s) == nullptr)
            current_directory->make_child_directory(s, current_directory);
        else
            cout << "duplicated album name\n";
    }

    void remove_album(string s) {
        pair<int, int> result;
        if (s == "-1") {
            result = current_directory->remove_first_child_directory();
        } else if (s == "0") {
            result = current_directory->remove_all_child_directory();
        } else if (s == "1") {
            result = current_directory->remove_last_child_directory();

        } else {
            result = current_directory->remove_child_directory(s);
        }
        cout << result.first << " " << result.second << "\n";
    }

    void insert_photo(string s) {
        if (current_directory->has_photo(s))
            cout << "duplicated photo name\n";
        else
            current_directory->insert_photo(s);
    }

    void delete_photo(string s) {
        int result;
        if (s == "-1") {
            result = current_directory->delete_first_photo();
        } else if (s == "0") {
            result = current_directory->delete_all_photo();
        } else if (s == "1") {
            result = current_directory->delete_last_photo();
        } else {
            result = current_directory->delete_photo(s);
        }
        cout << result << "\n";
    }

    void ca(string s) {
        if (s == "..") {
            if (current_directory != root_directory)
                current_directory = current_directory->get_parent_directory();
        } else if (s == "/") {
            current_directory = root_directory;
        } else {
            if (current_directory->get_child_directory(s) != nullptr) {
                current_directory = current_directory->get_child_directory(s);
            }
        }
        cout << current_directory->get_name() << "\n";
    }
};

int main() {
    FASTIO();
    int n;
    cin >> n;
    string cmd, argument;

    Album album;
    while (n--) {
        cin >> cmd >> argument;

        if (cmd == "mkalb") {
            album.make_album(argument);
        } else if (cmd == "rmalb") {
            album.remove_album(argument);
        } else if (cmd == "insert") {
            album.insert_photo(argument);
        } else if (cmd == "delete") {
            album.delete_photo(argument);
        } else if (cmd == "ca") {
            album.ca(argument);
        } else {
            cout << "not defined command\n";
        }
    }

    return 0;
}