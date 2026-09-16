#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& bloomDay,int day, int m, int k){
    int count = 0, numOfBouquets = 0;
    for (int bloom : bloomDay){
        if(bloom<=day){
            count++;
            if(count == k){
                numOfBouquets++;
                count=0;
                if (numOfBouquets == m) return true;
            }
        }
        else {
            count=0;
        }
    }
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if(1LL*m*k > n) return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while(low<=high){
        int day = low+(high-low)/2;
        if(isPossible(bloomDay, day, m, k)){
            high = day-1;
        }
        else {
            low = day+1;
        }
    }
    return low;
}

int main() {
    vector<int> bloomDay ={1,10,3,10,2};
    cout << minDays(bloomDay, 3, 1) << '\n';
    return 0;
}