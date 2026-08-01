class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(), 0);

        queue<int> q;
        for (int i = 0; i < rooms[0].size(); i++) 
        {
            q.push(rooms[0][i]);
        }
        visited[0] = true;

        while(!q.empty())
        {
            int nextroom = q.front();
            q.pop();

            if (visited[nextroom] == true) continue;
            visited[nextroom] = true;

            for (int i = 0; i < rooms[nextroom].size(); i++)
            {
                q.push(rooms[nextroom][i]);
            }
        }

        for (int i = 0; i < rooms.size(); i++)
        {
            if (visited[i] == false)
            {
                return false;
            }
        }

        return true;
    }
};