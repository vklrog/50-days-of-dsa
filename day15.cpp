//problem 1) 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = INT_MAX;
        vector<int> prefix(n + 1, INF);
        vector<int> suffix(n + 1, INF);
        int left = 0;
        int sum = 0;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                prefix[right + 1] = right - left + 1;
            }
            prefix[right + 1] = min(prefix[right + 1],prefix[right]);
        }
        int right = n - 1;
        sum = 0;
        for (int left = n - 1; left >= 0; left--) {
            sum += arr[left];
            while (sum > target) {
                sum -= arr[right];
                right--;
            }
            if (sum == target) {
                suffix[left] = right - left + 1;
            }
            suffix[left] = min(suffix[left],suffix[left + 1]);
        }
        int ans = INF;
        for (int i = 0; i <= n; i++) {
            if (prefix[i] != INF &&
                suffix[i] != INF) {
                ans = min(ans, prefix[i] + suffix[i]);
            }
        }
        return ans == INF ? -1 : ans;
    }
};
