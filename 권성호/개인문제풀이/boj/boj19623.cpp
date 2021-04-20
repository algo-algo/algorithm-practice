#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Info {
public: 
	int start, end, score;
};

vector<Info> infoVec;
int DP[100000];			//DP[i]: i번째 까지 확인 했을 때 최대 수용 인원
						//DP[i] = max(DP[i-1], scores[i] + DP[x]) where x: lower_bound(endPoses+0, endPoses+i, startPoses[i]) - 1 (값이 같으면 -1은 생략)
						//즉 (이번 것을 포기하는 경우, 포기 하지 않는 경우)의 맥스 값이 이번 턴의 최댓값이다.

int N;
int start_, end_, score_;

bool CmpByEnd(const Info& info1, const Info& info2) {
	return info1.end < info2.end;
}

int Max_(const int& n1, const int& n2) {
	return n1 > n2 ? n1 : n2;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start_ >> end_ >> score_;
		infoVec.push_back({ start_,end_,score_ });
	}
	
	sort(infoVec.begin(), infoVec.end(), CmpByEnd);

	DP[0] = infoVec[0].score;
	int arr[100000];
	for (int i = 0; i < N; i++)
		arr[i] = (infoVec[i].end);

	for (int i = 1; i < N; i++)
	{
		auto iter = lower_bound(arr, arr + i, infoVec[i].start);
		int idx = iter - arr;

		if (arr[idx] == infoVec[i].start)
			DP[i] = Max_(DP[i - 1], infoVec[i].score + DP[idx]);
		else
		{
			if(idx !=0)
				DP[i] = Max_(DP[i - 1], infoVec[i].score + DP[idx - 1]);
			else
				DP[i] = Max_(DP[i - 1], infoVec[i].score);
		}
	}

	cout << DP[N - 1] << '\n';

	return 0;
}