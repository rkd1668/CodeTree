#include <iostream>

using namespace std;

int N, M;
int DX[4] = { 0, 1, 0, -1 }, DY[4] = { 1, 0, -1, 0 };
int DirNum = 0;
int X = 0, Y = 0;
char Answer[100][100];

bool InRange(int X, int Y)
{
	return (X >= 0 && X < N && Y >= 0 && Y < M);
}
int main()
{
	char Alphabet = 'A';
	Answer[X][Y] = Alphabet;

	cin >> N >> M;
	for (int i = 2; i <= N * M; i++)
	{
		int NextX = X + DX[DirNum], NextY = Y + DY[DirNum];

		if (!InRange(NextX, NextY) || Answer[NextX][NextY] != 0)
		{
			DirNum = (DirNum + 1) % 4;
		}

		X += DX[DirNum];
		Y += DY[DirNum];
		Alphabet = Alphabet + 1;
		if (Alphabet > 90)
		{
			Alphabet = 'A';
		}
		Answer[X][Y] = Alphabet;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << Answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}