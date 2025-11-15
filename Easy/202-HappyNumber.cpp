class Solution {
public:
    bool isHappy(int n) {
      unordered_set<int> container;

      while(true){
        int temp = n;
        int sum = 0;
        while(temp != 0){
            int digit = temp % 10;
            sum += digit * digit;
            temp = temp / 10;
        }

        if(sum == 1) return true;

        if(container.count(sum)) return false;

        container.insert(sum);

        n = sum;
      }  
    }
};