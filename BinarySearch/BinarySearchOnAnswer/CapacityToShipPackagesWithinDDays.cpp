#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& weights, int days) {

    int n = weights.size();
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low<=high){
        int capacity = low+(high-low)/2;

        int daysReq = 1;
        int load = 0;

        for(int i=0; i<n; i++){
            if(weights[i]+load <= capacity){
                load += weights[i]; 
            }
            else {
                daysReq++;
                load = weights[i]; 
            }

            if (daysReq > days)
                break;
        }

        if(daysReq<=days){
            high = capacity-1;
        }
        else {
            low = capacity+1;
        }

    }
    return low;
}

int main(){
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << shipWithinDays(weights, days) << '\n';

    return 0;
}