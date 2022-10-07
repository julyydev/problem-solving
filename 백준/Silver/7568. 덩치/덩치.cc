// https://www.acmicpc.net/problem/
// written by julyy

#include <iostream>
using namespace std;

typedef struct _Person {
    int weight;
    int height;
    int rank = 1;
} Person;

int main() {
    int N;
    cin >> N;
    
    Person *arr = new Person[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i].weight >> arr[i].height;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)
                    arr[i].rank++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i].rank << ' ';
    }

    delete [] arr;
    
    return 0;
}
