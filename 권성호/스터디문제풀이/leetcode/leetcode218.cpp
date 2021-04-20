#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp1(vector<int>& v1, vector<int>& v2) {
	return v1[0] < v2[0];
}

bool cmp2(vector<int>& v1, vector<int>& v2) {
	return v1[1] > v2[1];
}


class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//1) left 보기
		vector<vector<int>> leftAnsVec;
		leftAnsVec.push_back({ buildings[0][0], buildings[0][2] });
		for (int i = 1; i < buildings.size(); i++)
		{
			if (leftAnsVec[leftAnsVec.size() - 1][0] == buildings[i][0] &&
				leftAnsVec[leftAnsVec.size() - 1][1] < buildings[i][2]) {
				leftAnsVec[leftAnsVec.size() - 1][1] = buildings[i][2];
				continue;
			}

			int maxHeight = 0;
			for (int j = i - 1; j >= 0; j--)
				if (buildings[j][1] >= buildings[i][0]) 
					maxHeight = maxHeight > buildings[j][2] ? maxHeight : buildings[j][2];
			
			if (maxHeight < buildings[i][2])
				leftAnsVec.push_back({ buildings[i][0], buildings[i][2] });
		}

		//2) right 보기
		sort(buildings.begin(), buildings.end(), cmp2);
		vector<vector<int>> rightAnsVec;
		rightAnsVec.push_back({ buildings[0][1], 0 });
		for (int i = 1; i < buildings.size(); i++)
		{
			if (buildings[i][1] == rightAnsVec[rightAnsVec.size() - 1][0])
				continue;

			int maxHeight = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				if (buildings[i][1] >= buildings[j][0]) {
					maxHeight = maxHeight > buildings[j][2] ? maxHeight : buildings[j][2];
				}
			}

			if (maxHeight < buildings[i][2])
				rightAnsVec.push_back({ buildings[i][1], maxHeight });
		}

		//3) 합쳐서 정렬하기
		for (int i = 0; i < rightAnsVec.size(); i++)
			leftAnsVec.push_back(rightAnsVec[i]);

		sort(leftAnsVec.begin(), leftAnsVec.end(), cmp1);

		return leftAnsVec;
	}

	
};