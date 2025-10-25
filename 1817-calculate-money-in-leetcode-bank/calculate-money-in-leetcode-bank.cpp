class Solution {
public:
    int totalMoney(int n) {
        int t1=n/7,t2=n%7;
        double ans=((double)t1/2)*(2*28+(t1-1)*7); 
        ans+=((double)t2/2)*(2*(t1+1)+(t2-1)*1);
        return (int)ans;
    }
};