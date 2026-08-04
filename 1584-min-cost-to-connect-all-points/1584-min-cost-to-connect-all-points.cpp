class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> allDistances (points.size(), INT_MAX);
        unordered_map<int, bool> visited;
        int currInd = 0;
        int result = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int x1 = points[currInd][0], y1 = points[currInd][1];
            visited[currInd] = true;
            allDistances[currInd] = INT_MAX;

            for (int j = 0; j < points.size(); j++)
            {
                if (visited.find(j) != visited.end()) continue;
                int x2 = points[j][0], y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);

                if (allDistances[j] > dist)
                {
                    allDistances[j] = dist;
                }
            }

            int best = INT_MAX;
            int bestInd = -1;
            for (int j = 0; j < allDistances.size(); j++)
            {
                if (allDistances[j] < best)
                {
                    best = allDistances[j];
                    bestInd = j;
                }
            }

            if (best != INT_MAX)
            {
                result += best;
                currInd = bestInd;
            }
        }

        return result;
    }
};