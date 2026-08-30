class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> receive_time (n+1, -1);
        vector<bool> visited (n+1, false);
        vector<bool> seen (n+1, false);
        receive_time[k] = 0;
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
                if (receive_time[target] == -1) receive_time[target] = r_time+time;
                else receive_time[target] = min(receive_time[target], r_time+time);
                pq.emplace(receive_time[target], target);
            }
            if (num_visited == n) return r_time;
            if (pq.empty() || num_seen == num_visited) return -1;
        }
    }
};
