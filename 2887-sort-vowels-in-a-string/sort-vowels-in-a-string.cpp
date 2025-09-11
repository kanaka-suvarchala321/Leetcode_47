class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char> extractedVowels;

        // Extract vowels
        for (char c : s) {
            if (vowels.count(c)) {
                extractedVowels.push_back(c);
            }
        }

        // Sort vowels by ASCII value
        sort(extractedVowels.begin(), extractedVowels.end());

        // Rebuild string
        string result = "";
        int vowelIndex = 0;
        for (char c : s) {
            if (vowels.count(c)) {
                result.push_back(extractedVowels[vowelIndex++]);
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
};