#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int distributeCandies(int n, int limit) {
        unordered_map<pair<int, int>, int, pair_hash> memo;
        return helper(n, 3, limit, memo);
    }

private:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Combining hashes in a way that preserves order
            return h1 ^ h2;
        }
    };

    int helper(int candies, int children, int limit, unordered_map<pair<int, int>, int, pair_hash>& memo) {
        if (candies == 0 && children == 0) {
            return 1;
        }
        if (candies < 0 || children == 0) {
            return 0;
        }

        auto key = make_pair(candies, children);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int ways = 0;
        for (int i = 0; i <= min(candies, limit); ++i) {
            ways += helper(candies - i, children - 1, limit, memo);
        }

        memo[key] = ways;
        return ways;
    }
};

int main(){
    Solution sol;
    cout << sol.distributeCandies(7, 4) << endl;
    cout << sol.distributeCandies(10, 3) << endl;
    cout << sol.distributeCandies(1000000000, 100000) << endl;
    return 0;
}