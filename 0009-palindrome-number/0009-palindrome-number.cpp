class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
            int temp=x;
            long int sum=0;
            while(temp>0){
                int r=temp%10;
                sum = sum*10 + r;
                temp/=10;
            }
            if(sum==x){
                return true;
            }
            return false;
        }
    }
};