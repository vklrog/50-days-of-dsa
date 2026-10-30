// problem 1) 3970. Shortest Path With At Most K Consecutive Identical Characters
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        vector<vector<int>> dist(n, vector<int>(k+1,INT_MAX));
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int d = top[0];
            int node = top[1];
            int count = top[2];
            if(d > dist[node][count]) continue;
            for(auto [v, wt] : adj[node]) {
                int cnt;
                if(labels[node] == labels[v]) {
                    cnt=count+1;
                }
                else {
                    cnt=1;
                }
                if(cnt > k) continue;
                int newD=d+wt;
                if(newD<dist[v][cnt]){
                    dist[v][cnt] = newD;
                    pq.push({newD, v, cnt});
                }
            }
        }
        int ans = INT_MAX;
        for(int cnt = 1; cnt <= k; cnt++) {
            ans = min(ans, dist[n-1][cnt]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};