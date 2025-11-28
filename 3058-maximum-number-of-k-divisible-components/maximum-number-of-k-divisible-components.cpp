class Solution {
public:
    void dfs(int node,int par,vector<vector<int>>& adj,vector<int>& prefix,int k){
        prefix[node]%=k;
        for(auto child:adj[node]){
            if(child != par){
                dfs(child,node,adj,prefix,k);
                prefix[node]+=prefix[child];
                prefix[node]%=k;
            }
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int> > adj(n + 1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> prefix = values;
        dfs(0,-1,adj,prefix, k);

        int res = 0;
        for(auto ele:prefix)res+=ele == 0;
        return res;
    }
};