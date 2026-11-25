// problem 1) 3934. Smallest Unique Subarray

class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    const ll base = 100003;
    vector<ll> hash, power;
    void build(vector<int>& nums) {
        int n = nums.size();
        hash.assign(n + 1, 0);
        power.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * base + nums[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }

    ll getHash(int l, int r) {
        return (hash[r + 1] - hash[l] * power[r - l + 1] % mod + mod) % mod;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        build(nums);
        int l = 1, r = n;
        int ans = n;
        while (l <= r) {
            int mid=l+(r-l)/2;
            unordered_map<ll, int> mp;

            for (int i = 0; i + mid <= n; i++) {
                ll h = getHash(i, i + mid - 1);
                mp[h]++;
            }
            bool found = false;
            for (auto& [key, val] : mp) {
                if (val == 1) {
                    found = true;
                    break;
                }
            }

            if (found) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
