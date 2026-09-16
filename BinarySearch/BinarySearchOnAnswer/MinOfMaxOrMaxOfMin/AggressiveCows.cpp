#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& arr, int m, int minDist) {
    int count = 1;
    int last = arr[0];

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] - last >= minDist) {
            count++;
            last = arr[i];
        }
    }

    return count >= m;
}

int AggressiveCows(vector<int>& arr, int m) {
    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr.back()-arr.front();
    int ans = 0;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(canPlace(arr, m, mid)) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 7};
    int m = 3;

    cout << AggressiveCows(arr, m) << '\n';
}