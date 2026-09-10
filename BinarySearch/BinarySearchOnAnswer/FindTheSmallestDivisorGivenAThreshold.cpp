#include <bits/stdc++.h>
using namespace std;

bool isBelowThreshold(vector<int>& nums, int threshold, int mid){
    int sum = 0;
    for(int num : nums){
        sum+=((num+mid-1)/mid);
        if(sum>threshold){
            return false;
        }
    }
    return true;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());

    while(low<=high){
        int mid = low+(high-low)/2;

        if(isBelowThreshold(nums, threshold, mid)){
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout << smallestDivisor(nums, threshold) << '\n';
}