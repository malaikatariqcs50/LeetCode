//Last Solved on: 6 Oct, 2026, Tuesday
//Last Solved in: 1 hour 30 minutes
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> rectangles;
        int area = 0;
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            int start = i;
            while(!rectangles.empty() && heights[i] < rectangles.top().second){
                int topHeight = rectangles.top().second;
                int index = rectangles.top().first;
                area = topHeight * (i - index);
                maxArea = max(maxArea, area);
                rectangles.pop();
                start = index;
            }
            rectangles.push({start, heights[i]}); 
        }
        int start = heights.size();
        while(!rectangles.empty()){
            int topHeight = rectangles.top().second;
            int index = rectangles.top().first;
            rectangles.pop();
            area = topHeight * (start - index);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

//Pattern:
//Increasing monotonic stack -> Shorter bar means taller rectangles can't continue anymore. Calculate their area (against the current index, no need for continuous adding using loops) and pop and use that start for the next pop in the loop. Otherwise keep pushing. Empty the stack at the end.