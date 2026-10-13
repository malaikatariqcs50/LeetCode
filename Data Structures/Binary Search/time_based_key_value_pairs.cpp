//Last Solved on: 13 Oct 2026, Tuesday
//Last Solved in: 1 hour
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp) {
        int low = 0;
        int high = mp[key].size()-1;
        int midTimestamp = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int midStamp = mp[key][mid].first;
            if(midStamp == timestamp){
                return mp[key][mid].second;
            }
            
            if(timestamp > midStamp){
                low = mid+1;
                midTimestamp=mid;
            }
            else{
                high = mid - 1;               
        }        
    }
    if(midTimestamp == -1) return "";
    return mp[key][midTimestamp].second;
    }
};

//Pattern: Binary Search
//Find the greatest number which is less than the requested number
//Use all possible numbers and perform Binary Search 