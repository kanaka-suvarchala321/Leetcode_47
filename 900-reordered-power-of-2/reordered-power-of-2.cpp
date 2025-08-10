class Solution {
public:

    bool reorderedPowerOf2(int n) {
        if(n == 1) return true;
        bool got = false;
        string str = to_string(n);
        permutation(got,0,str);
        return got;
    }
    void permutation(bool & got , int ind , string & str){
        if(!got){
          if(ind == str.size()){
            if(str[0] != '0'){
                long long num = stoi(str);
                if((num & (num-1)) == 0){
                    got = true;
                    return;
                }
            }
          }
          for(int i = ind ; i < str.size() ; i++){
            swap(str[ind],str[i]);
            permutation(got,ind+1,str);
            swap(str[ind],str[i]);
          }
        }
    }
};