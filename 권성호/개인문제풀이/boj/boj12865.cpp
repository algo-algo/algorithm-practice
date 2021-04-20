// N개의 물건
// 각 물건은 무게 W와 가치 V를 가짐 => 해당 물건을 배낭에 넣어가면 V만큼 즐길 수 있다
// 최대 무게는 K
// 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력
// 즉 최대 무게 K를 넘지 않으면서 쌓을 수 있는 배낭의 최대 가치를 구하는 문제

// 물건을 중복으로 가져갈 수 있나? => 중복 불가

#include <iostream>

using namespace std;

int N;					//물품의 수 (1 <= N <= 100)
int K;					//최대 무게 (1 ≤ K ≤ 100,000)
int WS[101];			//각 물건의 무게 W(1 ≤ W ≤ 100,000)
int VS[101];			//해당 물건의 가치 V(0 ≤ V ≤ 1,000)

int DP[101][100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> WS[i] >> VS[i];
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int a = 0;
			if (WS[i] <= j)
			{
				if (j - WS[i] >= 1)
					a = VS[i] + DP[i - 1][j - WS[i]];
				else
					a = VS[i];
			}
			int b = DP[i - 1][j];

			DP[i][j] = a < b ? b : a;
		}
	}

	cout << DP[N][K] << '\n';
}