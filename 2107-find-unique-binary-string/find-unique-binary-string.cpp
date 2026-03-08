#include <vector>
#include <string>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::string result;
        for (int i = 0; i < nums.size(); ++i) {
            result += (nums[i][i] == '1') ? '0' : '1';
        }
        return result;}
};