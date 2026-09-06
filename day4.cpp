// problem 1) 4044. Count Good Cyclic Rotations
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int siz=n/2;
        nums.reserve(nums.size()*2);
        nums.insert(nums.end(),nums.begin(),nums.end());
        long long left=0,right=0;
        for(int i=0;i<siz;i++){
            left+=nums[i];
        }
        for(int i=siz;i<n;i++){
            right+=nums[i];
        }
        int i=0;
        int j=siz;
        int jl=n-1;
        int cnt=0;
        while(i<n){
            if(left>right){
                cnt++;
            }
            left-=nums[i];
            left+=nums[j];
            right-=nums[j];
            right+=nums[jl+1];
            jl++;
            i++;
            j++;
        }
        return cnt;
    }
};

// problem 2) 4043. Count Rotations With Exactly K Equal Adjacent Pairs

class Solution {
public:
    int countRotations(string s, int k) {
        int cnt=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]) cnt++;
        }
        if(s[0]==s[s.size()-1]) cnt++;
        if(k==cnt) return s.size()-cnt;
        return k==cnt-1?cnt:0;
    }
};

// problem 3) 115. Distinct Subsequences
class Solution {
public:
    int dp[1001][1001];
    int solve(string& s , string& t,int m,int n){
        if(n==0) return  dp[m][n]=1;
        if(m==0) return dp[m][n]=0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m-1]==t[n-1]){
            return dp[m][n]= solve(s,t,m-1,n-1)+solve(s,t,m-1,n);
        }else{
            return dp[m][n]= solve(s,t,m-1,n);
        }
        return -1;
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,m,n);
    }
};