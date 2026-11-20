//Last Solved on: 20 Nov, 2026, Friday
//Last Solved in: 10 minutes

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int heavy = pq.top();
            pq.pop();
            int light = pq.top();
            pq.pop();
            int newWeight = heavy - light;
            if(newWeight != 0){
                pq.push(newWeight);
            }
        }
        if(pq.size() == 0){
            return 0;
        }
        return pq.top();
    }
};

//Pattern: Priority Queue
//Trick: Use PQ when smallest or largest are repeatedly being used