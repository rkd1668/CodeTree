#include <iostream>
using namespace std;

int N, T, Answer;
int Map[99][99];
int DX[4] = {0, 1, 0, -1}, DY[4] = {1, 0, -1, 1};
int DirNum = 3;
char Directions[100000];

bool InRange(int X, int Y)
{
    return (X >= 0 && X < N && Y >= 0 && Y < N);
}

int main() 
{
    // Please write your code here.
    cin >> N >> T;

    for (int i = 0; i < T; i++)
    {
        char Direction;
        cin >> Direction;
        Directions[i] = Direction;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int Num;
            cin >> Num;
            Map[i][j] = Num;
        }
    }
    
    int X = N / 2;
    int Y = N / 2;

    Answer = Map[X][Y];

    for(int i = 0; i < T; i++)
    {
        if(Directions[i] == 'L')
        {
            DirNum = (DirNum + 3) % 4;
        }
        else if(Directions[i] == 'R')
        {
            DirNum = (DirNum + 1) % 4;
        }
        else
        {
            int NextX = X + DX[DirNum];
            int NextY = Y + DY[DirNum];

            if(InRange(NextX, NextY))
            {
                X += DX[DirNum];
                Y += DY[DirNum];
                Answer += Map[X][Y];
            }
        }
    }

    cout << Answer;
    return 0;
}