class Solution {
    typedef pair<int, int> P;
    vector<vector<P>> adjList;

    int dijkstra(int n, int src)
    {
        vector<int> minimumTime(n, INT_MAX);
        minimumTime[src] = 0;

        priority_queue<P, vector<P>, greater<P>> minHeap;
        minHeap.push({0, src});

        while (!minHeap.empty())
        {
            auto [time, node] = minHeap.top();
            minHeap.pop();

            for (auto& [neighbor, w] : adjList[node])
            {
                int newTime = time + w;
                if (minimumTime[neighbor] > newTime)
                {
                    minimumTime[neighbor] = newTime;
                    minHeap.push({newTime, neighbor});
                }
            }
        }

        int result = *max_element (begin(minimumTime), end(minimumTime));
        return (result == INT_MAX) ? -1 : result;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        adjList.resize(n);

        for (auto& time : times)
        {
            int u = time[0] - 1;
            int v = time[1] - 1;
            int w = time[2];
            adjList[u].push_back({v, w});
        }

        return dijkstra(n, k-1);    
    }
};