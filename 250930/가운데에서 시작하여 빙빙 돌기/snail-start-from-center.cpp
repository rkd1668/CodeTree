#include <iostream>

using namespace std;

int N;
int DX[4] = { 0, 1, 0, -1 }, DY[4] = { 1, 0, -1, 0 };
int Answer[100][100];
int DirNum = 1;


bool InRange(int X, int Y)
{
	return (X >= 0 && X < N && Y >= 0 && Y < N);
}

int main()
{
	cin >> N;
	int X = N / 2, Y = N / 2;
	Answer[X][Y] = 1;
	for (int i = 2; i <= N * N; i++)
	{
		int NextDirNum = (DirNum + 3) % 4;
		int NextX = X + DX[NextDirNum];
		int NextY = Y + DY[NextDirNum];
		if (Answer[NextX][NextY] == 0)
		{
			DirNum = (DirNum + 3) % 4;
		}
		X += DX[DirNum];
		Y += DY[DirNum];
		Answer[X][Y] = i;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Answer[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}