class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> mirror = {
            {0, 0}, 
            {1, 1},
            {6, 9},
            {8, 8},
            {9, 6}
        };

        int p = pow(10, (int)log10(n));
        int originalNum = n, reversedNum = 0;

        while(n){
            if(mirror.find(n%10) == mirror.end())
                return false;
            
            reversedNum += p * mirror[n%10];
            n /= 10;
            p /= 10;
        }

        return reversedNum != originalNum;
    }
};
