//Last Solved on: 15 Oct, 2026, Thursday
//Last Solved in: 1 hour

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int len = m + n;

        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = n;

        while(low <= high){
            int cut1 = low + (high - low)/2;
            int cut2 = (len+1)/2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int r1 = cut1 == n ? INT_MAX : nums1[cut1];
            int r2 = cut2 == m ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1){
                if(len % 2 == 0){
                    return ((double)max(l1, l2) + min(r1, r2))/2.0;
                }
                return max(l1, l2);
            }

            if(l1 > r2){
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

//Pattern: Binary Search
//Find the smaller array and perform binary search on its partition (find mid/cut1, low, high)
//Remaining elements will be from the larger array (find cut2/parttition2)
//If all elements on the left are smaller and right are greater, return it
//If left is greater, move to left
//Otherwise, move to right.