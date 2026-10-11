//problem 1) 2778. Sum of Squares of Special Elements
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(n%(i+1)==0){
                ans+=nums[i]*nums[i];
            }
        }
        return ans;
    }
};
//problem 2) 633. Sum of Square Numbers
class Solution {
public:
    bool judgeSquareSum(int c) {
        int t=c/2;
        long long C=c;
        int i=0;
        while(i<=t){
            long long num=c-1ll*i*i;
            if(num<0){
                return false;
            }
            int n=sqrt(num);
            if(n*n==num){
                return true;
            }
            i++;

        }
        return false;
    }
};
// problem 3) 367. Valid Perfect Square
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int h=2147483647/2;
        while(l<=h){
            int mid=l+(h-l)/2;
            long long ans=1ll*mid*mid;
            if(ans==num){
                return true;
            }else if(ans>num){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};
//problem 4) 69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int l=0;
        int h=x/2;
        long long ans=1;
        long long pre=0;
        while(l<=h){
            ans=1ll*l*l;
            if(ans<x){
                pre=l;
                l++;
            }else if(ans==x){
                return l;
            }else{
                return pre;
            }
        }
        return pre;
        
    }
};