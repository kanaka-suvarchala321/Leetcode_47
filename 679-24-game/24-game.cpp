class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> permutation(cards.size());
        return permutate(cards, permutation, 0);
    }
    
private:
    const double TARGET = 24.0;
    const double EPS = 0.00000000001;
    
    bool eq(double a, double b) {
        return abs(a - b) < EPS;
    }
    
    bool check(vector<double>& p) {
        vector<function<double(double, double)>> operations = {
            [](double a, double b) { return a + b; },
            [](double a, double b) { return a - b; },
            [](double a, double b) { return a * b; },
            [](double a, double b) { return a / b; }
        };
        
        for (auto& o1 : operations) {
            for (auto& o2 : operations) {
                for (auto& o3 : operations) {
                    if (eq(o3(o2(o1(p[0], p[1]), p[2]), p[3]), TARGET) ||
                        eq(o3(o1(p[0], p[1]), o2(p[2], p[3])), TARGET) ||
                        eq(o3(o2(p[0], o1(p[1], p[2])), p[3]), TARGET) ||
                        eq(o3(p[0], o2(o1(p[1], p[2]), p[3])), TARGET) ||
                        eq(o3(p[0], o2(p[1], o1(p[2], p[3]))), TARGET)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool permutate(vector<int>& cards, vector<double>& permutation, int index) {
        if (index == permutation.size()) {
            return check(permutation);
        }
        for (int i = 0; i < cards.size(); i++) {
            if (cards[i] != -1) {
                int value = cards[i];
                permutation[index] = (double)value;
                cards[i] = -1;
                if (permutate(cards, permutation, index + 1)) {
                    return true;
                }
                cards[i] = value;
            }
        }
        return false;
    }
};