//1. �������� ���� �������� ���.
//������� ���� : ���� 10�10 ������, ������� ������������ 10 ��., �� ������������� ���� � ������.
//���� ������������� ��� ������ ����������� �������� ����������.
//������� ����������� ���������� ���� :
//? ������ ���� :
//? ������� � ���������;
//? ��������� � ���������.
//? ����������� �������� :
//? ����� ����������� �������;
//? ��������� ����������� �� ������.
//? ��������� ����� ������ � ���� ������� :
//? ��������� �������;
//? ���������������� ����.��������� ������ ��������� ����, � �� �������� ��������.
//? ���������� ������� ��������� �������� ���� ������ � ����������.
//? ����������� ���������, ������������, ���������� ������� ����. 
// (�������� - �������� ��������� ���� � ����)
//�����:
//������������� �������, ������ �������� ���������, ���������� �� ���� �� ������ �������� 
// (�������, ����, ������� � ��.), - �������, ������, 
//���������� ������� ��� ������������.��������, ������� ������� � ������.

// ��� ��� ���� �������:
// 
// ������� � ������ � ��������� �����
// 
// ��� �������� ����������
// ���� ������� ���������� �� ���
// 
//���� � ��������?
//�������, �������, �����? ������ �� �����
// ������ ��������?
// 
// �����!
// 
// ������
//
//��������� ���������,
//�������� �������
//
//������: ���� ������ ����� !!!
//
// ����� ���� ���� - ���� ���� �� ������� � �� �����������
// 
// ���������, ������������, ������!!??
// 
//����������� ��������: ������� 

//
//��� ����, ����� � C++ �������� � ������� ���������� ���������� ������������ ���� fstream :
//
//����� ����� ����� ��������� �������, ����������� � ������ : ��� ������ ������ �� ����� ������������ ������� ���� ifstream(������������ �� input file stream, ��� ������ ������ � ���� ������������ ������� ���� ofstream(output file stream).��������
//
//	����� ��������� ��� ��� ���� ����� � �����(������� ���� ��� ������ ��� ��� ������) ������������ ����� open, �������� ���������� �������� �������� � ��������� ������, ���������� ��� ������������ �����.
//
//	����� �������� ������ � �������� �� � �������� �������, �������� � ������� ����� ��� ��, ��� �� ������������ �������� ����� - ������ cin � cout.��������, ����� ������� �������� ���������� x � ����� fout ������������ ��������� ��������
//
//	� ����� ������� �������� ���������� �� ������ fin
//
//	��� �������� ����� ��������� ����� ������������ ����� close() ��� ���������� :
//
//�������� �������� ����� ����� ����������� ������ ��� ������ ������ open, �������� ��� � ���� �� ��� ������� �����.

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;
const int mSIZE = 10;
const int SHIPSNUM = 10;

void showMap(int map[][mSIZE], int fog[][mSIZE], bool useFog);      //����� ���� �� �����
int shipChecks(int map[][mSIZE], int shipSize, int shipCount);     //�������� ��� ��������� ��������
int shipSet(int map[][mSIZE]);   //��������� ��������
int shooting(int map[][mSIZE], int fog[][mSIZE], int x, int y);  //��������
int shipsID = 1;        //���������� ����������... //��� ��������� ����������� ���� ��������
int ships[SHIPSNUM] = { 0 };   //������, � ������� ����� ��������� ���������� ��������

int main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL));
	bool useFog = 0;  //���������� ��� "������ �����"
	int map[mSIZE][mSIZE] = { 0 };   //������ �������� ������ ���� (1��)
	int map2[mSIZE][mSIZE] = { 0 }; //������ ������� ���������� (������ 2)

	int fog[mSIZE][mSIZE] = { 0 }; //"����� �����", ��� �������� �������� ����������
	int fog2[mSIZE][mSIZE] = { 0 };

	shipSet(map);    //������ ������� �� ���� ���� (���� ������ ���������)
	shipsID = 1;    //����� ���������� �������� ������������ ������ ��� ������� ����
	shipSet(map2); //������ ������� ���������



	int x = 0, y = 0;     //���������� ���������
	int happyHitX = 0, happyHitY = 0;   //������ ���������� �������� ���������, � � �, ��� "���������"
	int smartMode = 0;   //������ �����(�������) ����
	int xBot = 0; int yBot = 0;  //��������� ��� ����
	int dir = 0;  //�����������

	vector <int> dirs;//����������������� �������� ������ (������)
	dirs.push_back(3); dirs.push_back(2); dirs.push_back(1); dirs.push_back(0);

	//���������� ������
	bool youWin = 0, botWin = 0;
	bool turn = 1;    //�����������: 1 - ����� �������, 0 - ����




	while (youWin == false && botWin == false)  //���� �� ������ ������ ������
	{
		int shootResult = 0;
		do //���� ���� �������� �� �������� ������ �� �������, ���� �� ����� ������
		{
			cout << "\n\t���� ����:\n";  showMap(map, fog, 0);  //���������� ��� ����� �� �����
			cout << "     ���� ����������:\n"; showMap(map2, fog2, 0);
			if (turn == 1)
			{
				cout << "\t��� ���!" << endl;
				do
				{

					//����� ������� ������� - ��� �1, �8...  ��� ���������, ��� � ��� ���������
					cout << "������� ���������� ����:\n";
					cin >> x; cin >> y;

				} while (((x < 0) || x > 10) && ((y < 0) || (y > 10)));  //������, ��� ����������� �����
				x--; y--; //����� �� 0� �������, ������

				shootResult = shooting(map2, fog2, x, y);   //����� �������� �� 2�� ���� (����������)

				if (shootResult == 1) cout << "\a�����!" << endl;
				else if (shootResult == 2) cout << "\a����!" << endl;
				else  cout << "����!" << endl;
			}
			else
			{
				cout << "��� ����������:\n";
				Sleep(1000);
				if (smartMode == 0)
				{
					do
					{
						xBot = rand() % mSIZE;    //���������� ����������
						yBot = rand() % mSIZE;   //���������� ����� ����
						cout << xBot + 1 << endl;
						cout << yBot + 1 << endl;
						shootResult = shooting(map, fog, xBot, yBot);  //��������
					} while (shootResult == 3);

					if (shootResult == 1)
					{
						smartMode = 1;
						happyHitX = xBot;
						happyHitY = yBot;
						if (!dirs.empty())     //empty - ���������, ������ ������ ��� ���
						{
							dir = dirs[dirs.size() - 1];    //������ � ���������� ��������
							dirs.pop_back();    //�������� �� �������
						}
						cout << "\a�����!" << endl;
					}
					else if (shootResult == 2)
					{
						bool died = 1;
						for (int i = 1; i <= SHIPSNUM; i++)
						{
							if (ships[i] != 0)
							{
								died = 0;
								break;
							}
						}
						if (died == 1)
						{
							botWin = 1;
							break;
						}
						cout << "\a����!" << endl;
					}
					else cout << "������!" << endl;
				}
				else if (smartMode == 1)
				{
					bool changeDir = 0;    //����������, ������� ������ �� ��� ����� �� ������ ����������� ��� ���
					if (dir == 0)         //�������� �����
					{
						if (xBot > 0)
							xBot--;
						else
						{
							changeDir = 1;
						}
					}
					else if (dir == 1)    //�������� ������
					{
						if (xBot < mSIZE - 1)
							xBot++;
						else
						{
							changeDir = 1;
						}
					}
					else if (dir == 2)    //�������� �����
					{
						if (yBot > 0)
							yBot--;
						else
						{
							changeDir = 1;
						}
					}
					else if (dir == 3)    //�������� ����
					{
						if (yBot < mSIZE - 1)
							yBot++;
						else
						{
							changeDir = 1;
						}
					}
					if (changeDir == 1)
					{
						if (!dirs.empty())
						{
							dir = dirs[dirs.size() - 1];
							dirs.pop_back();
						}
						xBot = happyHitX;
						yBot = happyHitY;
						continue;
					}
					shootResult = shooting(map, fog, xBot, yBot);

					if (shootResult == 1)    //���� ������
					{
						smartMode = 1;  //��� ����� �����
						happyHitX = xBot;
						happyHitY = yBot;

						if (!dirs.empty())//empty - ���������, ������ ������ ��� ���
						{
							dir = dirs[dirs.size() - 1];//������ � ���������� ��������
							dirs.pop_back();  //��������
						}

						cout << "\a�����!" << endl;
					}
					else if (shootResult == 2)
					{
						smartMode = 0;
						dirs.clear();
						dirs.push_back(3);
						dirs.push_back(2);
						dirs.push_back(1);
						dirs.push_back(0);
						bool died = 1;
						for (int i = 1; i <= SHIPSNUM; i++) //����������� ��� ��������
						{
							if (ships[i] != 0)
							{
								died = 0;
								break;
							}
						}
						if (died == 1)
						{
							youWin = 1;
							break;
						}
						cout << "\a����!" << endl;
					}
					else
					{
						if (!dirs.empty())
						{
							dir = dirs[dirs.size() - 1];
							dirs.pop_back();
						}
						xBot = happyHitX;
						yBot = happyHitY;
						cout << "������!" << endl;
					}
				}
			}

			Sleep(1500);
			system("cls");
		} while (shootResult != 0); //���� �� ����� �������, �������� ���� �����
		turn = !turn; //���� ���� - ����� ����
	}
	if (youWin == 1)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "~~~~~�� ��������!~~~~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;

	}
	else if (botWin == 1)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "~~~~~�� ���������~~~~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	system("pause");
	return 0;
}

void showMap(int map[][mSIZE], int fog[][mSIZE], bool useFog)
{
	int k = 1;     //��� ����������� ������������ ��� ���������
	cout << "  .�_�_�_�_�_�_�_�_�_�." << endl; //��� ����������� �������������� ��� ���������//
	//cout << "   1_2_3_4_5_6_7_8_9_10" << endl; //��� ����������� �������������� ��� ���������
	for (int i = 0; i < mSIZE; ++i)
	{
		if (k == 10) cout << k << "|";
		else cout << k << " |"; k++;
		for (int j = 0; j < mSIZE; ++j)
		{
			if ((fog[i][j] == 1) || (useFog == 0))
			{
				if (map[i][j] == 0)
					cout << "  ";
				else if (map[i][j] == -1)
					cout << "~ ";
				else if (map[i][j] == -3) //����
					cout << "� ";
				else if (map[i][j] >= 1)
					cout << "# ";
				else if (map[i][j] >= -13)
					cout << "+ ";
				else
				{
					cout << map[i][j] << " ";
				}
			}
			else
				cout << "  ";
		}
		cout << "|" << endl;
	}
	cout << "  '--------------------' " << endl;
}

int shipChecks(int map[][mSIZE], int shipSize, int shipCount) {
	bool possibleToSet = 1;
	int x, y;
	int dir = 0;
	int temp_x, temp_y;
	int shipNum = 0;
	while (shipNum < shipCount)
	{
		do
		{
			x = rand() % mSIZE; y = rand() % mSIZE;
			temp_x = x; temp_y = y;
			dir = rand() % 4;
			possibleToSet = 1;
			for (int i = 0; i < shipSize; ++i) {
				if (x < 0 || y < 0 || x >= mSIZE || y >= mSIZE)
				{
					possibleToSet = 0;
					break;
				}
				//�������� ���������� ������
				if (map[x][y] >= 1 ||
					map[x][y + 1] >= 1 ||
					map[x][y - 1] >= 1 ||
					map[x + 1][y] >= 1 ||
					map[x + 1][y + 1] >= 1 ||
					map[x + 1][y - 1] >= 1 ||
					map[x - 1][y] >= 1 ||
					map[x - 1][y + 1] >= 1 ||
					map[x - 1][y - 1] >= 1)
				{
					possibleToSet = 0;
					break;
				}
				switch (dir) {
				case 0:
					x++;
					break;
				case 1:
					y++;
					break;
				case 2:
					x--;
					break;
				case 3:
					y--;
					break;
				}
			}
		} while (possibleToSet != 1);

		if (possibleToSet == 1) {
			x = temp_x;
			y = temp_y;
			for (int i = 0; i < shipSize; ++i) {
				map[x][y] = shipsID;
				switch (dir)
				{
				case 0:
					x++;
					break;
				case 1:
					y++;
					break;
				case 2:
					x--;
					break;
				case 3:
					y--;
					break;
				}
			}
		}
		ships[shipsID] = shipSize;
		shipsID++;
		shipNum++;
	}
	return map[mSIZE][mSIZE];
}

int shipSet(int map[][mSIZE]) {
	int shipSize = 4;
	int shipCount = 1;
	shipChecks(map, shipSize, shipCount);
	--shipSize;
	++shipCount;
	shipChecks(map, shipSize, shipCount);
	--shipSize;
	++shipCount;
	shipChecks(map, shipSize, shipCount);
	--shipSize;
	++shipCount;
	shipChecks(map, shipSize, shipCount);
	return map[mSIZE][mSIZE];
}

int shooting(int map[][mSIZE], int fog[][mSIZE], int x, int y)  //��������
{
	int result = 0;
	if (map[y][x] >= 1)
	{
		ships[map[y][x]]--;

		if (ships[map[y][x]] <= 0)
		{
			result = 2;
		}
		else
		{
			result = 1;
		}
		map[y][x] = -3;
	}
	else
	{
		map[y][x] = -1;
	}
	fog[y][x] = 1;

	return result;
}
