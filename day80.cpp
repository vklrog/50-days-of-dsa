// problem 1) 3331. Find Subtree Sizes After Changes
class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,string& s,vector<int> alp,vector<int>& parent){   
        if(alp[s[node]-'a']!=-1){
            parent[node]=alp[s[node]-'a'];
        }
        alp[s[node]-'a']=node;
        for(auto& nd:adj[node]){
            dfs(nd,adj,s,alp,parent);
        }
    }
    void dfs2(int u, const vector<vector<int>>& adj_nw, vector<int>& sz) {
        for (int v : adj_nw[u]) {
            dfs2(v, adj_nw, sz);
            sz[u] += sz[v];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        vector<int> alp(26,-1);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0,adj,s,alp,parent);
        vector<vector<int>> adj_nw(n);
        vector<int> sz(n, 1);
        for(int i=1;i<n;i++){
            adj_nw[parent[i]].push_back(i);
        }
        dfs2(0, adj_nw, sz);
        return sz;

        

    }
};