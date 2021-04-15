/*
  LeetCode.com
  Problem No: 911
  Problem: Online Election
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 15/04/2021
*/

#include <bits/stdc++.h>

class TopVotedCandidate {
public:
    TopVotedCandidate(std::vector<int>& persons, std::vector<int>& times) {
        int max_votes = 0;
        std::unordered_map<int, int> votes;
        leader.resize(times.size());
        for (std::size_t i = 0; i < persons.size(); ++i) {
            ++votes[persons[i]];
            if (votes[persons[i]] >= max_votes) {
                max_votes = votes[persons[i]];
                leader[i] = persons[i];
            } else {
                leader[i] = leader[i - 1];
            }
        }
        this->times = std::move(times);
        //print();
    }

    int q(int t) {
        return bs(t);
    }

private:
    std::vector<int> times;
    std::vector<int> leader;

    int bs(int t) {
        int s = 0;
        int e = static_cast<int>(times.size() - 1);
        while (s <= e) {
            if (s == e) {
                if (times[s] > t)
                    return leader[s - 1];
                else
                    return leader[s];
            }
            const int mid = (s + e) >> 1;
            if (t <= times[mid])
                e = mid;
            else
                s = mid + 1;
        }
        return -1;
    }

    void print() const {
        printf("----------------------------------------------\n");
        for (int t : times)
            printf("%4d ", t);
        printf("\n----------------------------------------------\n");
        printf("----------------------------------------------\n");
        for (int l : leader)
            printf("%4d ", l);
        printf("\n----------------------------------------------\n");
    }
};

int main() {
    std::vector<int> p1 = {0,1,1,0,0,1,0};
    std::vector<int> t1 = {0,5,10,15,20,25,30};
    std::vector<int> q1 = {3,12,25,15,24,8};

    TopVotedCandidate tvc1(p1, t1);
    for (int tt :  q1)
        printf("%d\n", tvc1.q(tt));

    std::vector<int> p2 = {0,0,1,1,2};
    std::vector<int> t2 = {0,67,69,74,87};
    std::vector<int> q2 = {4,62,100, 88, 70, 73, 22, 75, 29, 10};
    TopVotedCandidate tvc2(p2, t2);
    for (int tt : q2)
        printf("%d\n", tvc2.q(tt));

    return 0;
}
