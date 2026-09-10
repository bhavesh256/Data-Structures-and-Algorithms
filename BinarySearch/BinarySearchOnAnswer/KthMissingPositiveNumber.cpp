#include <bits/stdc++.h>
using namespace std;

// Hashing
int findKthPositive(vector<int>& arr, int k) {
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