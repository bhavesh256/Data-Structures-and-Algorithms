#include <bits/stdc++.h>
using namespace std;

// Hashing
int findKthPositiveA(vector<int>& arr, int k) {
    int limit = arr.back() + k;
    vector<int> missingNum(limit + 1, 0);
    for(int num : arr) {
        missingNum[num]++;
    }
    int count = 0;
    for(int i = 1; i <= limit; i++) {
        if(missingNum[i] == 0) {
            count++;
            if(count == k) {
                return i;
            }
        }
    }
    return -1;
}

/*
    Imagine you want the $k$-th empty parking spot.
    If the lot is totally empty,
    you just go to spot $k$. But every time you see a parked car (a number in
    the array) in your way, you have to walk one spot further down ($k++$) 
    to make up for it.


    Assume the k-th missing number is simply k.
    If an element in the array is <=k, it means a number you originally thought
    was missing is actually present. To make up for this "stolen" missing 
    number, you shift your target k up by 1. Once array elements are greater 
    than k, they don't affect your missing count anymore.
*/

int findKthPositiveB(vector<int>& arr, int k) {
    int n = arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]<=k){
            k++;
        }
        else {
            break;
        }
    }
    return k;
}

int findKthPositiveC(vector<int>& arr, int k) {
    int low = 0, high = arr.size()-1;

    while(low<=high){
        int mid = low+(high-low)/2;
        int missing = arr[mid] - (mid+1);

        if(missing < k){
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return k + high + 1;
}

int main(){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout << findKthPositiveC(arr, k) << '\n';
}