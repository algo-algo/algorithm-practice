// 각각의 M에 대해 가능한 모든 case를 가지고 DFS
// 모순이 발생하는 경우 backTracking

//만약 가능한 방법이 여러 가지일 경우, 햄스터 수가 가장 많은 것을 출력한다.
//
//그래도 가능한 방법이 여러 가지일 경우, 사전순으로 가장 앞선 것을 출력한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, X, M;
int inputArr[10][3];
int maxS = -1;

int				targetArr[6];
int				result[6];

void InputAndInit()
{
	maxS = -1;
	cin >> N >> X >> M;
	for (int i = 0; i < M; i++)
		cin >> inputArr[i][0] >> inputArr[i][1] >> inputArr[i][2];
}

void DFS(int currentNumber, int depth) {

	if (depth == N)
	{	//종료조건
		//int flag = true;
		/*vector<int> tempArr;
		vector<int> sumArr;

		for (int i = 0; i < N; i++) {
			tempArr.push_back(targetArr[i]);
			sumArr.push_back(targetArr[i]);
		}
		for (int i = 1; i < N; i++)
			sumArr[i] = sumArr[i - 1] + sumArr[i];

		for (int s = 0; s < M; s++)
		{
			if (inputArr[s][0] - 2 >= 0 && sumArr[inputArr[s][1] - 1] - sumArr[inputArr[s][0] - 2] == inputArr[s][2])
				continue;
			else if (inputArr[s][0] - 2 == -1 && sumArr[inputArr[s][1] - 1] == inputArr[s][2])
				continue;
			else {
				flag = false;
				break;
			}
		}*/

		bool flag = true;
		for (int i = 0; i < M; i++) {
			int tSum = 0;
			for (int j = inputArr[i][0] - 1; j < inputArr[i][1]; j++)
				tSum += targetArr[j];

			if (tSum != inputArr[i][2]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			if (maxS == -1)
			{
				maxS = currentNumber;
				for (int i = 0; i < N; i++)
					result[i] = targetArr[i];
				return;
			}
			if (maxS < currentNumber) {
				maxS = currentNumber;
				for (int i = 0; i < N; i++)
					result[i] = targetArr[i];
				return;
			}
			else if (maxS == currentNumber)
			{
				maxS = currentNumber;
				for (int i = 0; i < N; i++)
				{
					if (targetArr[i] == result[i]) continue;
					else if (targetArr[i] < result[i])
					{
						for (int i = 0; i < N; i++)
							result[i] = targetArr[i];
						return;
					}
					else
						return;
				}
			}
		}
		return;
	}
	for (int i = 0; i <= X; i++) {
		targetArr[depth] = i;
		DFS(currentNumber + i, depth + 1);
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		InputAndInit();
		DFS(0, 0);

		if (maxS == -1)
			cout << "#" << test_case << " " << -1 << "\n";
		else {
			cout << "#" << test_case;
			for (int i = 0; i < N; i++)
				cout << " " << result[i];
			cout << "\n";
		}
	}
	return 0;
}