//Last Solved on: 5 Oct 2026
//Last Solved in: 20 mins
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        stack<double> mono;
        for(int i=0; i<n; i++){
            double time = (double)(target - cars[i].first)/cars[i].second;
            while(!mono.empty() && time >= mono.top()){
                mono.pop();
            }
            mono.push(time);
        }
        return mono.size();
    }
};

//Pattern:
//When elements can merge based on their ordering and a comparison with the previous unresolved element, consider a monotonic stack.