//다익스트라 => 처음으로 방문한 놈이 최소
//			=> 2번째로 방문한 놈이 2번째로 최소
//....

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

int									N, M, K;
int									graph[1001][1001];

void InputAndInit()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			graph[i][j] = 0;
	}
	int t1, t2, t3;
	for (int i = 0; i < M; i++)
	{
		cin >> t1 >> t2 >> t3;
		graph[t1][t2] = t3;
	}
}

int main()
{
	InputAndInit();

	priority_queue < pair<long long, int>, vector< pair<long long, int>>, greater< pair<long long, int>> > pq;	//{가중치|노드}
	priority_queue<long long>				dist[1001];	//dist[i] == K가 되는 시점부터 들어가지 않도록 하자

	pq.push({ 0,1 });
	dist[1].push(0);
	while (pq.size() != 0) {
		pair<int, int> current = pq.top(); pq.pop();
		int currentWeight = current.first;
		int currentNode = current.second;

		for (int next = 1; next <= N; next++) {
			if (graph[currentNode][next] == 0)
				continue;

			if (dist[next].size() < K) {
				dist[next].push(currentWeight + graph[currentNode][next]);
				pq.push({ currentWeight + graph[currentNode][next] ,next });
			}
			else if (dist[next].top() > currentWeight + graph[currentNode][next]) {	//이게 종료조건도 되는군
				dist[next].pop();
				dist[next].push(currentWeight + graph[currentNode][next]);
				pq.push({ currentWeight + graph[currentNode][next] ,next });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() != K) cout << "-1\n";
		else cout << dist[i].top() << "\n";
	}
}