class Solution {
public:
    int isReachable(int l , int r , int st , int k) {
        int leftToRight = abs(st - l) + (r - l);
        int rightToLeft = abs(st - r) + (r - l);
        return min(leftToRight , rightToLeft) <= k;
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int maxFruits = 0;
        int currSum = 0;

        while(r < n) {
            int pos = fruits[r][0];
            currSum += fruits[r][1];
            
            while(l <= r && !isReachable(fruits[l][0] , pos , startPos , k)) {
                currSum -= fruits[l][1];
                l++;
            }
            maxFruits = max(maxFruits , currSum);
            r++;
        }
        return maxFruits;
    }
};