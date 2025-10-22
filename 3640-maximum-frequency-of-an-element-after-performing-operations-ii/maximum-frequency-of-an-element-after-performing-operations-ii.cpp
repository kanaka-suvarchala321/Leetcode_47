class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> freq, sweep;
        for (auto num : nums) {
            freq[num]++;
            sweep[num - k]++;
            sweep[num + k + 1]--;
        }

        int res = 0, count = 0;
        for (auto it = sweep.begin(); it != sweep.end(); it++) {
            if (it != sweep.begin()) {
                auto l = freq.lower_bound(prev(it)->first);
                auto r = freq.lower_bound(it->first);
                while (l != r) {
                    res = max(res, l->second + min(count - l->second, numOperations));
                    l++;
                }
            }

            count += it->second;

            res = max(res, min(count, numOperations));
        }
        return res;
    }
};