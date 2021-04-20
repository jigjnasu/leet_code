/*
  Leetcode.com
  Problem No : 1396
  Problem : Design Underground System
  Author : cpp.rakesh@gmail.com
  Date: 20/04/2021
*/

#include <bits/stdc++.h>

struct Trip {
    std::string station_name;
    int time = 0;

    Trip() {}
    Trip(const std::string& s, int t) : station_name(s), time(t) {}
};

struct Journey {
    int total_time = 0;
    int count = 0;
};

class UndergroundSystem {
public:
    UndergroundSystem() {}

    void checkIn(int id, std::string s, int t) {
        passenger[id] = Trip(s, t);
    }

    void checkOut(int id, std::string s, int t) {
        if (passenger.find(id) != passenger.end()) {
            const std::string key = passenger[id].station_name + "->" + s;
            Journey j;
            j.count = 1;
            j.total_time = t - passenger[id].time;
            if (records.find(key) != records.end()) {
                j.count += records[key].count;
                j.total_time += records[key].total_time;
            }
            records[key] = j;
        }
    }

    double getAverageTime(std::string s, std::string e) {
        const std::string key = s + "->" + e;
        return records[key].total_time / static_cast<double>(records[key].count);
    }

    void print_trips() {
        printf("-----------------------------------------------------\n");
        printf("                     trips\n");
        for (auto& it : passenger)
            printf("id == [%d] || station == [%s] || start time == [%d]\n", it.first, it.second.station_name.c_str(), it.second.time);
        printf("-----------------------------------------------------\n");
    }

    void print_records() {
        printf("-----------------------------------------------------\n");
        printf("                     records\n");
        for (auto& it : records)
            printf("key == [%s] || count == [%d] || total time == [%d]\n", it.first.c_str(), it.second.count, it.second.total_time);
        printf("-----------------------------------------------------\n");
    }

private:
    std::unordered_map<int, Trip> passenger;
    std::unordered_map<std::string, Journey> records;
};

void test() {
    UndergroundSystem us;
    us.checkIn(45, "Leyton", 3);
    us.checkIn(32, "Paradise", 8);
    us.checkIn(27, "Leyton", 10);
    //us.print_trips();
    us.checkOut(45, "Waterloo", 15);
    us.checkOut(27, "Waterloo", 20);
    us.checkOut(32, "Cambridge", 22);
    //us.print_records();
    printf("Paradise -> Cambridge == [%f]\n", us.getAverageTime("Paradise", "Cambridge"));
    printf("Leyton   -> Waterloo  == [%f]\n", us.getAverageTime("Leyton", "Waterloo"));
    us.checkIn(10, "Leyton", 24);
    printf("Leyton   -> Waterloo  == [%f]\n", us.getAverageTime("Leyton", "Waterloo"));
    us.checkOut(10, "Waterloo", 38);
    printf("Leyton   -> Waterloo  == [%f]\n", us.getAverageTime("Leyton", "Waterloo"));
}

int main() {
    test();

    return 0;
}
