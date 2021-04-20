#include <iostream>

using namespace std;

int board[500][500];

int GetShapeOneVal(int i,int j)
{
	return board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
}

int GetShapeTwoVal(int i, int j)
{
	return board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
}

int GetShapeThreeVal(int i, int j)
{
	int tempMax = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1];
	tempMax = (board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1]) > tempMax ?
		(board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1]) : tempMax;
	
	tempMax = (board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 2][j]) > tempMax ?
		(board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 2][j]) : tempMax;

	tempMax = (board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 2][j]) > tempMax ?
		(board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 2][j]) : tempMax;

	tempMax = (board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]) > tempMax ?
		(board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]) : tempMax;

	tempMax = (board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j]) > tempMax ?
		(board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j]) : tempMax;

	tempMax = (board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1]) > tempMax ?
		(board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1]) : tempMax;

	tempMax = (board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]) > tempMax ?
		(board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]) : tempMax;
	return tempMax;
}

int GetShapeFour(int i, int j)
{
	int tempMax = board[i][j + 2] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2];

	tempMax = (board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j]) > tempMax ?
		(board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j]) : tempMax;

	tempMax = (board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2]) > tempMax ?
		(board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2]) : tempMax;

	tempMax = (board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]) > tempMax ?
		(board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]) : tempMax;

	tempMax = (board[i][j + 1] + board[i][j + 2] + board[i + 1][j] + board[i + 1][j + 1]) > tempMax ?
		(board[i][j + 1] + board[i][j + 2] + board[i + 1][j] + board[i + 1][j + 1]) : tempMax;

	tempMax = (board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2]) > tempMax ?
		(board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2]) : tempMax;

	tempMax = (board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1]) > tempMax ?
		(board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1]) : tempMax;

	tempMax = (board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]) > tempMax ?
		(board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]) : tempMax;

	return tempMax;
}

int GetShapeFive(int i, int j)
{
	return board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
}

int main()
{
	int i, j;
	int N, M; // 세로,가로 사이즈		<=500
	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> board[i][j];
	}
	/*
	* 입력 완료
	*/
	//1. shapeOne
	int maxVal = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= M - 4; j++)
			maxVal = GetShapeOneVal(i, j) > maxVal ? GetShapeOneVal(i, j) : maxVal;
	}
	//2. shapeTwo
	for (i = 0; i <= N - 4; i++)
	{
		for (j = 0; j < M; j++)
			maxVal = GetShapeTwoVal(i, j) > maxVal ? GetShapeTwoVal(i, j) : maxVal;
	}

	//3. shapeThree
	for (i = 0; i <= N - 3; i++)
	{
		for (j = 0; j <= M - 2; j++)
			maxVal = GetShapeThreeVal(i, j) > maxVal ? GetShapeThreeVal(i, j) : maxVal;
	}

	//4. shapeFour
	for (i = 0; i <= N - 2; i++)
	{
		for (j = 0; j <= M - 3; j++)
			maxVal = GetShapeFour(i, j) > maxVal ? GetShapeFour(i, j) : maxVal;
	}

	//5. shapeFive
	for (i = 0; i <= N - 2; i++)
	{
		for (j = 0; j <= M - 2; j++)
			maxVal = GetShapeFive(i, j) > maxVal ? GetShapeFive(i, j) : maxVal;
	}

	cout << maxVal << endl;
	return 0;
}