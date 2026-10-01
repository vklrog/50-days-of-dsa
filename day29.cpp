//problem 1) 56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> help(2);
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int fin=intervals[0][1];
        int str=intervals[0][0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=fin){
                fin=max(fin,intervals[i][1]);
            }else{
                help[0]=str;
                help[1]=fin;
                str=intervals[i][0];
                fin=intervals[i][1];
                ans.push_back(help);
            }
        }
        help[0]=str;
        help[1]=fin;
        ans.push_back(help);
        return ans;

    }
};