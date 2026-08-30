class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited (n+1, false);
        vector<bool> seen (n+1, false);
        unordered_map<int, vector<pair<int, int>>> out_edges;
        for (vector<int>& time : times) {
            out_edges[time[0]].emplace_back(time[1], time[2]);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0,k);
        int num_visited = 0;
        int num_seen = 1;
        while (true) {
            auto [r_time, node] = pq.top();
            pq.pop();
            if (visited[node]) continue;
            visited[node] = true;
            ++num_visited;
            for (auto [target, time] : out_edges[node]) {
                if (visited[target]) continue;
                if (!seen[target]){
                    seen[target] = true;
                    ++num_seen;
                }
                pq.emplace(r_time+time, target);
            }
            if (num_visited == n) return r_time;
            if (pq.empty() || num_seen == num_visited) return -1;
        }
    }
};
