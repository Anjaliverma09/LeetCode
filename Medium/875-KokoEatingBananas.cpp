class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end());

        while(minSpeed < maxSpeed){
            int mid = minSpeed + (maxSpeed - minSpeed) / 2;

            if(eatTime(piles, h, mid)) maxSpeed = mid;

            else minSpeed = mid + 1;
         }
         return minSpeed;
    }

private:
    bool eatTime(vector<int>& piles, int h, int speed){
        long long hours = 0;

        for(int p: piles)
            hours += (p + speed - 1) / speed;

        return hours <= h;
    }
};