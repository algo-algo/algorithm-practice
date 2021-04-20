#include <iostream>

using namespace std;

long long			N;	// FN을 빨리 구하는게 목표

int main()
{
	int i, j, k;
	int ans = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	/*
	입력 완료
	*/
	int len;	//주기
	int F[2] = {0,1};
	//for (i = 0; i < N % 1500000; i++)
	//{
	//	F[i % 2] = (F[0] + F[1]) % 1000000;
	//}
	//ans = F[i % 2];
	//cout << ans;
	for (i = 0; i < N; i++)
	{
		F[i % 2] = (F[0] + F[1]) % 1000000;
		if (F[0] + F[1] == 1)
		{
			len = i + 2;
			break;
		}
	}
	if(i == N)
	{
		ans = F[i % 2];
		cout << ans;
		return 0;
	}
	else 
	{
		F[0] = 0, F[1] = 1;
		for (j = 0; j < N%len; j++)
		{
			F[j % 2] = (F[0] + F[1]) % 1000000;
		}
		ans = F[j % 2];

		cout << ans;
	}
}

//
//#include <iostream>
//using namespace std;
//const int mod = 1000000;
//const int p = mod / 10 * 15;
//int fibo[p] = { 0,1 };
//int main() {
//	long long n;
//	cin >> n;
//	for (int i = 2; i < p; i++) {
//		fibo[i] = fibo[i - 1] + fibo[i - 2];
//		fibo[i] %= mod;
//	}
//	cout << fibo[n%p] << '\n';
//	return 0;
//}