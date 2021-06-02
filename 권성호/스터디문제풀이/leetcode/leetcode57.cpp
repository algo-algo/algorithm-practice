#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (intervals.size() == 0)
			return { newInterval };

		vector<int> firstVec, secondVec;
		for (int i = 0; i < intervals.size(); i++) {
			firstVec.push_back(intervals[i][0]);
			secondVec.push_back(intervals[i][1]);
		}

		auto iter_first = lower_bound(secondVec.begin(), secondVec.end(), newInterval[0]);
		auto iter_second = upper_bound(firstVec.begin(), firstVec.end(), newInterval[1]);
		if (iter_first == secondVec.end()) {
			intervals.push_back(newInterval);
			return intervals;
		}
		if (iter_second == firstVec.begin()) {
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}

		int first = iter_first - secondVec.begin();
		int second = iter_second - firstVec.begin();
		
		vector<vector<int>> ans;
		for (int i = 0; i < first; i++)
			ans.push_back(intervals[i]);

		ans.push_back({ intervals[first][0] < newInterval[0] ? intervals[first][0] : newInterval[0] 
			, intervals[second - 1][1] > newInterval[1] ? intervals[second - 1][1] : newInterval[1] });

		for (int i = second; i < intervals.size(); i++)
			ans.push_back(intervals[i]);

		return ans;
	}
};
