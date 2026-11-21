//Last Solved on: 21 Nov, 2026, Saturday
//Last Solved in: 1 hour

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        priority_queue<int> pq;

        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i] - 'A']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (mp[i])
                pq.push(mp[i]);
        }

        int time = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> remaining;

            while (cycle != 0 && !pq.empty()) {
                int task = pq.top();
                pq.pop();
                if (task > 1) {
                    remaining.push_back(task - 1);
                }
                time++;
                cycle--;
            }
            
            for (int i = 0; i < remaining.size(); i++) {
                pq.push(remaining[i]);
            }
            if (pq.empty())
                break;
            time += cycle;
        }
        return time;
    }
};

//Trick: Pq to find the most occurring task so we can execute it first
//Pattern: Finish the most occurring task and then the one next to it
//If n != tasks performed, then interval += remaining n