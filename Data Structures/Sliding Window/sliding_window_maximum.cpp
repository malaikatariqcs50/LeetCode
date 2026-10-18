//Last Solved on: 18 Oct, 2026, Sunday
//Last Solved in: 45 mins
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //1,3,-1,-3,5,3,6,7  k=3
        
        vector<int> maximum;
        deque<int> dq;
        for(int i=0; i < nums.size(); i++){
       if(!dq.empty() && dq.front() <= i - k){
           dq.pop_front();
       }
                     
       while(!dq.empty() && nums[i] > nums[dq.back()]){
           dq.pop_back();
       }      
        
        dq.push_back(i);
              
       if(i >= k-1){
           maximum.push_back(nums[dq.front()]);
       }
    }
    return maximum;
    }
};

//Pattern: Sliding window + decreasing deque
//Max needed = monotonic deque
//Store indices so you know when an element leaves the window
//add smaller elements to the queue so the largest is always at the front
//Whenever a window is complete, the max is the value at the front
//Whenever a value larger than the value at back appears, remove those values and add the larger one
//When a window moves, remove relevant elements from the front