//������� �3.
//����������
//�������� ��������� ��������������. ������������ ������ 10 ������ ��������. �����������
//���� ��� ������������
//* ����� ������ (����� ����������� �������)
//* ��������� �������� (������������ ������ ����� �������� ������� � ����� ������)
//* ������� �� ��������� (��������� �������, ���� ������� ��� �� ���� 10.7)*/


#include <iostream>
#include <windows.h>
using namespace std;

void setGrades(int arGrades[], int size);  //�������� ������� ��� ����������� ������ ������

void setAllTwelwe(int arGrades[], int size); //�������� ������� ��� ������ ��������������

void showGrades(int arGrades[], int size);  //�������� ������� ��� ������ �������

template<typename T> T averGrade(T arGrades[], T size);  //������ ������� ��� ������� �������� �����

void changeGrade(int arGrades[], int size);  //�������� ������� ��� ���������

void menu()  //������� ����      (���������, ����� ���������� ����� ������������ � ��� ��������, �� �� ��� ����������(
{
	system("cls");
	cout << "\t��������� \n \"������������ ��������\" \t\t������ ���� ���������" << endl;
	Sleep(1000);
	cout << "\n�������� ����� �� ����: \n\n";
	cout << "12 - ��������� 12 �� ��� �����\n";
	cout << " 1 - ��������� ������ �� �����\n";
	cout << " 2 - �������� ��� ������\n";
	cout << " 3 - �������� ������� ����\n";
	cout << " 4 - ��������� ������ �� ��������� ��������\n";
	cout << " 0 - ����� �� ���������\n\n";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	const int size = 10;
	int arGrades[size];
	float sumGrades = 0;  //�����, ��� �������� �������� �����
	menu();
	int choice;  //���������� ��� ��������� ����
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 12:
		{
			setAllTwelwe(arGrades, size);  //����� �������, �������� ��� 12
			menu();
			cin >> choice;  //�� ���������� ������� ������ ������� menu
			break;
		}
		case 1:
		{
			setGrades(arGrades, size);
			menu();
			cin >> choice;
			break;
		}
		case 2:
		{
			showGrades(arGrades, size);
			menu();
			cin >> choice;
			break;
		}

		case 3:
		{
			cout << "������� ���� �������: " << averGrade(arGrades, size) << endl;
			if (averGrade(arGrades, size) >= 10.7) cout << "������� ������� ���������\n";
			else if (averGrade(arGrades, size) < 10.7) cout << "������� �� ������� ���������, ������� ���� ������� �����\n";
			else cout << "������! ��������� ������ ������\n";
			Sleep(2000);
			menu();
			cin >> choice;
			break;
		}
		case 4:
		{
			changeGrade(arGrades, size);
			menu();
			cin >> choice;
			break;
		}
		case 0:
			break;
		}
	} while (choice != 0);
	return 0;
}
void setGrades(int arGrades[], const int size)
{
	cout << "��������� ������ �� ����, �� 12-�������� �������: \n\n";
	int i = 0;
	for (i = 0; i < size; i++)
	{
		cout << "������� ������ �� ���� � " << i + 1 << "  ";
		cin >> arGrades[i];
		if ((arGrades[i] > 12) || (arGrades[i] <= 0))
		{
			cout << "\n������! ������� ������ ������ �� ���� " << i + 1 << " (�� 1 �� 12): ";
			do
			{
				cin >> arGrades[i];
			} while ((arGrades[i] > 12) || (arGrades[i] <= 0));
		}
	}
}
void showGrades(int arGrades[], int size)
{
	cout << "��� ������ �������:\n";
	cout << ".-----------------------.\n";
	for (int i = 0; i < size; i++)
	{
		cout << "| ���� " << i + 1 << "\t| " << arGrades[i] << "\t|" << endl;
	}
	cout << "|_______________________| \n";
	Sleep(5000);
}
template<typename T> T averGrade(T arGrades[], T size)
{
	T sumGrades = 0, averGrade = 0;
	for (int i = 0; i < size; i++)
	{
		sumGrades += arGrades[i];
	}
	averGrade = (double)sumGrades / (double)size;
	return averGrade;
	Sleep(3000);
}
void changeGrade(int arGrades[], int size)
{
	cout << "���������\n";
	cout << "�������� ����� ����� ��� ��������� ������: " << endl;
	int i;
	cin >> i;
	cout << "������� ����� ������ �� ���� � " << i << "  ";
	cin >> arGrades[i - 1];
	if ((arGrades[i] > 12) || (arGrades[i] < 0))
	{
		do
		{
			cout << "\n������! ������� ������ ������ �� ���� " << i + 1 << " (�� 1 �� 12)";
			cin >> arGrades[i];
		} while ((arGrades[i] > 12) || (arGrades[i] <= 0));
	}
}
void setAllTwelwe(int arGrades[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arGrades[i] = { 12 };
	}
	system("cls");
	cout << "���������� �� 12 ������ �� ��� �����.\n\n";
	Sleep(2000);
}