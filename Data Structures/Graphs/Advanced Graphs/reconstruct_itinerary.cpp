//Last Solved on: 27 Nov, 2026, Friday
//Last Solved in: 40 mins

class Solution {
private:
    void dfs(const string& node, vector<string>& itinerary, unordered_map<string, vector<string>>& graph){
        while(!graph[node].empty()){
            string next = graph[node].back();
            graph[node].pop_back();
            dfs(next, itinerary, graph);
        }

        itinerary.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;

        for (auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }

        for(auto& [_, dest] : graph){
            sort(dest.rbegin(), dest.rend());
        }

        vector<string> itinerary;

        dfs("JFK", itinerary, graph);
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};

//Save all the destinations to the source in a map
//Sort the destinations in descending order
//Take the smallest dest (from the back) and pop it, to not visit it again
//When all the dests are empty, add the last one to answer (greatest)
//Keep adding and reverse the ans, because the greatest was added first