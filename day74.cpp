// problem 1) 1524. Number of Sub-arrays With Odd Sum

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 1;
        long long odd = 0;
        long long ans = 0;
        int pre = 0;
        for(int x:arr){
            pre+= x;
            if(pre%2!=0) {
                ans=(ans+even)%MOD;
                odd++;
            }
            else{
                ans=(ans+odd)%MOD;
                even++;
            }
        }
        return ans;
    }
};
