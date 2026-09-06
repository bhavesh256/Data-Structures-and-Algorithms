#include <bits/stdc++.h>
using namespace std;

int SearchInARotatedSortedArray(vector<int>& nums, int target) {
    int n = nums.size();

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low+(high-low)/2;

        if (nums[mid] == target) {
            return mid;
    
        }

        // left half sorted
        if(nums[low]<=nums[mid]){
            if(target >= nums[low] && target < nums[mid]){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        else {
            if(target <= nums[high] && target > nums[mid]){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,1,2,3};

    cout << SearchInARotatedSortedArray(nums, 4) << '\n';
    cout << SearchInARotatedSortedArray(nums, 5) << '\n';
    cout << SearchInARotatedSortedArray(nums, 6) << '\n';
    cout << SearchInARotatedSortedArray(nums, 7) << '\n';
    cout << SearchInARotatedSortedArray(nums, 1) << '\n';
    cout << SearchInARotatedSortedArray(nums, 2) << '\n';
    cout << SearchInARotatedSortedArray(nums, 3) << '\n';
}





























































