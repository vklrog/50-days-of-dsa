// problem 1) 2409. Count Days Spent Together
class Solution {
public:
    int dtod(string date, const vector<int>& pref) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        return pref[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> pref = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < pref.size(); i++) {
            pref[i] += pref[i - 1];
        }
        int startA = dtod(arriveAlice, pref);
        int endA = dtod(leaveAlice, pref);
        int startB = dtod(arriveBob, pref);
        int endB = dtod(leaveBob, pref);

        int latestStart = max(startA, startB);
        int earliestEnd = min(endA, endB);

        return max(0, earliestEnd - latestStart + 1);


    }
};