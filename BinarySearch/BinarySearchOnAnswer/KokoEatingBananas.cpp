#include<iostream>
#include<vector>
#include<algorithm>

bool canEat(int speed, std::vector<int>& piles, int duration){
    int time = 0;
    for(int banana : piles){
        time+=((banana+speed-1)/speed);
        if(time>duration){
            return false;
        }
    }
    return true;
}

int minEatingSpeed(std::vector<int>& piles, int duration){
    // defining search space
    int high = *max_element(piles.begin(), piles.end());
    int low = 1;
    int minimumTime = high;

    // binary search
    while(low<=high){
        int mid = low+(high-low)/2;

        if(canEat(mid, piles, duration)){
            if(mid <= minimumTime){
                minimumTime = mid;
                high = mid-1;
            }
        }
        else {
            low = mid+1;
        }
    }
    return minimumTime;
}

int main(){
    std::vector<int> piles = {30,11,23,4,20};
    int duration = 5;
    std::cout << minEatingSpeed(piles, duration) << '\n';
}
