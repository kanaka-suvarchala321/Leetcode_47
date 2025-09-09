class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int totalPersons = 1;
        int activePersons = 0;
        int MOD = 1e9 + 7;

        vector<pair<int, int>> tracker(n);

        if (delay < n)
            tracker[delay] = {0, 1};
        if (forget < n)
            tracker[forget] = {1, 0};

        for (int i = 1; i < n; i++) {
            totalPersons = (totalPersons - tracker[i].first + MOD) % MOD;
            activePersons = (activePersons - tracker[i].first + MOD) % MOD;
            activePersons = (activePersons + tracker[i].second) % MOD;
            totalPersons = (totalPersons + activePersons) % MOD;

            if (i + delay < n)
                tracker[i + delay].second = activePersons;
            if (i + forget < n)
                tracker[i + forget].first = activePersons;
        }
        return totalPersons;
    }
};