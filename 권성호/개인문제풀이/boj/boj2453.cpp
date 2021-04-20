#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <utility>
#include <queue>

using namespace std;

bool						isConflict;
int							N, M, ans;
bool						isFinishedPerson[10001];
bool						setA[10001], setB[10001];
vector <int>				plusRelation[10001], minusRelation[10001];

vector<pair<int,int>>		resultDiffVec;

bool DT[2][10001];

void InputAndInit()
{
	memset(DT, 0, sizeof(DT));

	int t1, t2, t3;
	isConflict = false;
	cin >> N >> M;
	ans = numeric_limits<int>::max();
	resultDiffVec.clear();
	for (int i = 1; i <= N; i++)
	{
		setA[i] = false;
		setB[i] = false;
		isFinishedPerson[i] = false;
		plusRelation[i].clear();
		minusRelation[i].clear();
	}

	for (int i = 0; i < M; i++)
	{
		cin >> t1 >> t2 >> t3;
		if (t1 == 1)
		{
			plusRelation[t2].push_back(t3);
			plusRelation[t3].push_back(t2);
		}
		else
		{
			minusRelation[t2].push_back(t3);
			minusRelation[t3].push_back(t2);
		}
	}
}

int absolute(const int& x)
{
	return x > 0 ? x : -1 * x;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int test_case = 0; test_case < 5; test_case++)
	{
		InputAndInit();
		for (int i = 1; i <= N; i++)
		{
			if (isFinishedPerson[i] == false)
			{
				queue<pair<int, char>> q;
				q.push({ i,'A' });
				setA[i] = true;
				while (q.size() != 0) {
					pair<int, char> current = q.front(); q.pop();
					int currentPerson = current.first;
					char currentSet = current.second;
					if (isFinishedPerson[currentPerson] == true)
						continue;

					isFinishedPerson[currentPerson] = true;
					if (currentSet == 'A') {
						//1) +처리
						for (int plus = 0; plus < plusRelation[currentPerson].size(); plus++)
						{
							int nextPerson = plusRelation[currentPerson][plus];
							setA[nextPerson] = true;
							q.push({ nextPerson, 'A' });
						}
						//2) -처리
						for (int minus = 0; minus < minusRelation[currentPerson].size(); minus++)
						{
							int nextPerson = minusRelation[currentPerson][minus];
							setB[nextPerson] = true;
							q.push({ nextPerson, 'B' });
						}
					}
					else
					{
						//1) +처리
						for (int plus = 0; plus < plusRelation[currentPerson].size(); plus++)
						{
							int nextPerson = plusRelation[currentPerson][plus];
							setB[nextPerson] = true;
							q.push({ nextPerson, 'B' });
						}
						//2) -처리
						for (int minus = 0; minus < minusRelation[currentPerson].size(); minus++)
						{
							int nextPerson = minusRelation[currentPerson][minus];
							setA[nextPerson] = true;
							q.push({ nextPerson, 'A' });
						}
					}
				}
				int cntA = 0, cntB = 0;
				for (int i = 1; i <= N; i++)
				{
					if (setA[i] && setB[i])
					{
						isConflict = true;
						break;
					}
					if (setA[i]) {
						cntA++;
						setA[i] = false;
					}
					if (setB[i]) {
						cntB++;
						setB[i] = false;
					}
				}
				if (isConflict)
					break;

				resultDiffVec.push_back({ cntA , cntB });
			}
		}
		if (isConflict)
			cout << -1 << '\n';
		else {

			// 배치 방법 => https://howtoliveworldnice.tistory.com/40 참고
			DT[0][0] = 1; int i = 0, ans = -1;
			for (auto& p : resultDiffVec) {
				i++;
				int diff = abs(p.first - p.second);
				for (int j = 0; j <= 10000; j++)
					DT[i % 2][j] = DT[(i + 1) % 2][abs(j - diff)] || DT[(i + 1) % 2][abs(j + diff)];
			}
			for (int i = 0; i <= 10000; i++) {
				if (DT[(resultDiffVec.size()) % 2][i] != 0) {
					ans = i;
					break;
				}
			}
			cout << ans << '\n';
		}
		
	}

}