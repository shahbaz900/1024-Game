#include<iostream>
#include<time.h>
#include <cstdlib>
#include <ctime> 
using namespace std;
void Board(int arr[4][4])//building box
{

	cout << "	" << "_________________________________________________________________" << endl << endl << endl;
	for (int i = 0; i < 4; i++) {
		cout << "	|	";
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << "	|	";


		}
		if (i != 3)
		{
			cout << endl;
		}
		cout << endl << endl;
	}
	cout << "	" << "_________________________________________________________________" << endl;
}
void randam(int arr[4][4], int counter)//generating two random no on first time
{
	int k, l;

	while (counter < 2) {
		k = rand() % 4;
		l = rand() % 4;

		arr[k][l] = (rand() % 2 + 1);
		counter++;
	}


}
void ran(int arr[4][4])//generating 1 random no after every move
{
	bool flag4 = 0;
	int k, l = 0;
	for (int z = 0; z < 4; z++)//this loop is checking is box is fully filled
	{
		for (int o = 0; o < 4; o++)
		{
			if (arr[z][o] == 0)
			{
				flag4 = 1;
				break;
			}
		}
	}
	if (flag4 == 1)//if not fully filled then it generate random no
	{
		k = rand() % 4;
		l = rand() % 4;
		while (arr[k][l] != 0) {
			k = rand() % 4;
			l = rand() % 4;
		}
		arr[k][l] = (rand() % 2 + 1);
	}

}
void MoveL(int arr[4][4])//moving left
{
	int space = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (arr[i][j] != space)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (arr[i][k] != space)
					{
						if (arr[i][j] == arr[i][k])
						{
							arr[i][k] = arr[i][j] + arr[i][k];
							arr[i][j] = 0;
							break;
						}
						else
							break;
					}
					if (arr[i][k] == space)
					{
						if (k == 0)
						{
							arr[i][k] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else {
							for (int u = k; u >= 1; u--)
							{
								if (arr[i][u - 1] != space)
								{
									if (arr[i][u - 1] == arr[i][j]) {
										arr[i][u - 1] = arr[i][j] + arr[i][u - 1];
										arr[i][j] = 0;
										break;

									}
									else {
										arr[i][u] = arr[i][j];
										arr[i][j] = 0;
										break;

									}
								}

							}
						}
					}
				}
			}
		}
	}
	ran(arr);//calling ran function to generate 1 random no
}

void MoveR(int arr[4][4])//moving right
{
	int space = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (arr[i][j] != space)
			{
				for (int k = j + 1; k <= 3; k++)
				{
					if (arr[i][k] != space)
					{
						if (arr[i][j] == arr[i][k])
						{
							arr[i][k] = arr[i][j] + arr[i][k];
							arr[i][j] = 0;
							break;
						}
						else
							break;
					}
					if (arr[i][k] == space)
					{
						if (k == 3)
						{
							arr[i][k] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else {
							for (int u = k; u <= 2; u++)
							{
								if (arr[i][u + 1] != space)
								{
									if (arr[i][u + 1] == arr[i][j]) {
										arr[i][u + 1] = arr[i][j] + arr[i][u + 1];
										arr[i][j] = 0;
										break;

									}
									else {
										arr[i][u] = arr[i][j];
										arr[i][j] = 0;
										break;

									}
								}

							}
						}

					}
				}

			}
		}

	}

	ran(arr);

}
void MoveD(int arr[4][4])//moving down
{

	int space = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (arr[i][j] != space)
			{
				for (int k = i + 1; k <= 3; k++)
				{
					if (arr[k][j] != space)
					{
						if (arr[i][j] == arr[k][j])
						{
							arr[k][j] = arr[i][j] + arr[k][j];
							arr[i][j] = 0;
							break;
						}
						else
							break;
					}
					if (arr[k][j] == space)
					{
						if (k == 3)
						{
							arr[k][j] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else {
							for (int u = k; u <= 2; u++)
							{
								if (arr[u + 1][j] != space)
								{
									if (arr[u + 1][j] == arr[i][j]) {
										arr[u + 1][j] = arr[i][j] + arr[u + 1][j];
										arr[i][j] = 0;
										break;

									}
									else {
										arr[u][j] = arr[i][j];
										arr[i][j] = 0;
										break;

									}
								}

							}
						}

					}
				}

			}
		}

	}

	ran(arr);
}
void MoveU(int arr[4][4])//moving up
{
	int space = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i <= 3; i++)
		{
			if (arr[i][j] != space)
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (arr[k][j] != space)
					{
						if (arr[i][j] == arr[k][j])
						{
							arr[k][j] = arr[i][j] + arr[k][j];
							arr[i][j] = 0;
							break;
						}
						else
							break;
					}
					if (arr[k][j] == space)
					{
						if (k == 0)
						{
							arr[k][j] = arr[i][j];
							arr[i][j] = 0;
							break;
						}
						else {
							for (int u = k; u >= 1; u--)
							{
								if (arr[u - 1][j] != space)
								{
									if (arr[u - 1][j] == arr[i][j]) {
										arr[u - 1][j] = arr[i][j] + arr[u - 1][j];
										arr[i][j] = 0;
										break;

									}
									else {
										arr[u][j] = arr[i][j];
										arr[i][j] = 0;
										break;

									}
								}

							}
						}
					}
				}
			}
		}
	}
	ran(arr);
}
void Win(int arr[4][4], bool& check)//checking if any index has 1024 no it if have then return check=1
{
	for (int c = 0; c < 4; c++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (arr[c][y] == 1024)
			{
				check = 1;
				break;
			}
		}
	}

}
void Gover(int arr[4][4], bool& a)//checking game over condition if it is then return a=1
{
	bool flag = 0, flag1 = 0, flag2 = 0;
	for (int r = 0; r < 4; r++)
	{
		for (int q = 0; q < 4; q++)
		{
			if (arr[r][q] == 0)
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		for (int d = 0; d < 4; d++) {
			for (int g = 0; g < 4; g++) {

				if (arr[d][g] == arr[d][g + 1])
				{
					flag1 = 1;
					break;
				}

			}
		}
		for (int g = 0; g < 4; g++) {
			for (int d = 0; d < 4; d++) {

				if (arr[d][g] == arr[d + 1][g])
				{
					flag2 = 1;
					break;
				}

			}
		}

	}
	if (flag == 0 && flag1 == 0 && flag2 == 0)
	{
		a = 1;
	}

}
int main() {
	int  arr[4][4] = { 0 };
	char input;
	bool check = 0, a = 0;
	int counter = 0;
	system("color f4");
	srand(time(0));

	randam(arr, counter);
	Board(arr);
	Gover(arr, a);
	Win(arr, check);
	if (check == 1)
		cout << "YOU WIN!";
	else if (a == 1)
	{
		cout << "GAME OVER!";
	}
	else
	{
		cout << "Press L  or R or U or D: ";
		cin >> input;

		do {

			if (input == 'l')
			{
				MoveL(arr);
			}
			else if (input == 'r')
			{
				MoveR(arr);
			}
			else if (input == 'd')
			{
				MoveD(arr);
			}
			else if (input == 'u')
			{
				MoveU(arr);
			}

			system("CLS");
			Board(arr);
			Win(arr, check);
			Gover(arr, a);
			if (!check && !a) {
				cout << "Press L or R or U or D: ";
				cin >> input;
			}
			else if (check == 1)
				cout << "YOU  WIN!";
			else
				cout << "GAME OVER!";

		} while (!check && !a);
	}
	system("pause>0");
}
