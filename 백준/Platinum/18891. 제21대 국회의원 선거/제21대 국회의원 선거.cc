#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Party {
    int id;               // 기호
    string name;          // 정당명
    int district_seats;   // 지역구 의석 수
    int allocated_seats;  // 연동 배분 의석 수
    int total_seats;
    int proportional_votes;               // 비례대표 득표 수
    double proportional_vote_percentage;  // 비례대표 국회의원 선거 득표비율
    bool is_allocation_party;  // 의석할당정당여부 (봉쇄조항 만족 시)

   public:
    Party() {}
    Party(int id, string name, int district_seats, int proportional_votes)
        : id(id),
          name(name),
          district_seats(district_seats),
          allocated_seats(0),
          total_seats(0),
          proportional_votes(proportional_votes),
          proportional_vote_percentage(0),
          is_allocation_party(false) {}

    void calculate_vote_percentage(const int valid_votes, int& R) {
        double vote_percentage = (double)proportional_votes / valid_votes;
        if (vote_percentage < 0.03 && district_seats < 5) {
            R += district_seats;
            return;
        }

        is_allocation_party = true;
    }

    bool check_is_allocation_party() { return is_allocation_party; }

    int get_allocated_seats() { return allocated_seats; }

    void add_allocated_seats(int value) { allocated_seats += value; }

    int get_proportional_votes() { return proportional_votes; }

    int step1(const int& N, const int& R, const int& valid_votes) {
        double p = (double)proportional_votes / valid_votes;
        proportional_vote_percentage = p;
        int r = district_seats;
        double result = (double)((N - R) * p - r) / 2;

        if (result < 1) return 0;
        allocated_seats = round(result);
        return allocated_seats;
    }

    double step2(const int& sum_allocated_seats, int& sum) {
        double p;
        if (sum_allocated_seats < 30)  // step 2-1
            p = (double)allocated_seats +
                (30 - sum_allocated_seats) * proportional_vote_percentage;
        else if (sum_allocated_seats > 30)  // step 2-2
            p = (double)30 * allocated_seats / sum_allocated_seats;

        allocated_seats = floor(p);
        sum += floor(p);
        return p - floor(p);
    }

    double step3(int& sum) {
        double p = (double)17 * proportional_vote_percentage;
        allocated_seats += floor(p);
        sum += floor(p);
        return p - floor(p);
    }

    void calculate_total_seats() {
        total_seats = district_seats + allocated_seats;
    }

    void print() { cout << name << " " << total_seats << "\n"; }

    bool operator<(const Party& p) const {
        if (total_seats == p.total_seats) return name < p.name;
        return total_seats > p.total_seats;
    }
};

struct Rest {
    int index;
    double decimal;

    Rest() {}
    Rest(int index, double decimal) : index(index), decimal(decimal) {}

    bool operator<(const Rest& r) const {
        if (decimal == r.decimal) return index < r.index;
        return decimal > r.decimal;
    }
};

void distribute_by_decimal(vector<Party>& parties, vector<Rest>& rests,
                           int rest) {
    sort(rests.begin(), rests.end());
    int i = 0;
    while (rest--) {
        parties[rests[i].index].add_allocated_seats(1);
        i = (i + 1) % rests.size();
    }
}

int main() {
    FASTIO();
    int P, V;
    cin >> P >> V;

    string name;
    int seats, votes;

    vector<Party> parties(P);
    const int N = 300;  // 국회의원 정수
    int R = 253;  // 의석할당정당이 아닌 정당의 당선인 + 무소속 당선인
    int valid_votes = 0;

    for (int i = 0; i < P; i++) {
        cin >> name >> seats >> votes;
        parties[i] = Party(i + 1, name, seats, votes);
        R -= seats;
        valid_votes += votes;
    }

    for (Party& party : parties)
        party.calculate_vote_percentage(valid_votes, R);
    for (Party& party : parties) {
        if (party.check_is_allocation_party()) continue;
        valid_votes -= party.get_proportional_votes();
    }

    // step1 : 30석에 대해 전국단위 준연동(연동비율 50%) 방식으로 각 정당별
    // 연동배분의석수 산정
    int sum_allocated_seats = 0;
    for (Party& party : parties) {
        if (!party.check_is_allocation_party()) continue;
        sum_allocated_seats += party.step1(N, R, valid_votes);
    }

    // step2 : 30석이 되도록 다시 배분
    vector<Rest> rests;
    int sum = 0;
    for (int i = 0; i < P; i++) {
        if (!parties[i].check_is_allocation_party()) continue;
        double decimal = parties[i].step2(sum_allocated_seats, sum);
        rests.push_back({i, decimal});
    }
    distribute_by_decimal(parties, rests, 30 - sum);

    // step3 : 17석에 대해 기존 의석배분방식(병립형) 적용 배분
    rests.clear();
    sum = 0;
    for (int i = 0; i < P; i++) {
        if (!parties[i].check_is_allocation_party()) continue;
        double decimal = parties[i].step3(sum);
        rests.push_back({i, decimal});
    }
    distribute_by_decimal(parties, rests, 17 - sum);

    for (Party& party : parties) party.calculate_total_seats();

    sort(parties.begin(), parties.end());
    for (Party& party : parties) party.print();

    return 0;
}