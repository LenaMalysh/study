//Задание №3.
//Сортировка
//Написать программу «успеваемость». Пользователь вводит 10 оценок студента. Реализовать
//меню для пользователя
//* Вывод оценок (вывод содержимого массива)
//* Пересдача экзамена (пользователь вводит номер элемента массива и новую оценку)
//* Выходит ли стипендия (стипендия выходит, если средний бал не ниже 10.7)*/


#include <iostream>
#include <windows.h>
using namespace std;

void setGrades(int arGrades[], int size);  //прототип функции для выставления каждой оценки

void setAllTwelwe(int arGrades[], int size); //прототип функции для оценок суперотличника

void showGrades(int arGrades[], int size);  //прототип функции для показа массива

template<typename T> T averGrade(T arGrades[], T size);  //шаблон функции для расчета среднего балла

void changeGrade(int arGrades[], int size);  //прототип функции для пересдачи

void menu()  //функция меню      (пробовала, чтобы возвращала выбор пользователя и его свитчить, но не все получалось(
{
	system("cls");
	cout << "\tПрограмма \n \"УСПЕВАЕМОСТЬ СТУДЕНТА\" \t\tИванов Петр Сидорович" << endl;
	Sleep(1000);
	cout << "\nВыберите пункт из меню: \n\n";
	cout << "12 - Поставить 12 за все уроки\n";
	cout << " 1 - Выставить оценки за уроки\n";
	cout << " 2 - Показать все оценки\n";
	cout << " 3 - Показать средний балл\n";
	cout << " 4 - Поставить оценки за пересдачу экзамена\n";
	cout << " 0 - Выйти из программы\n\n";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	const int size = 10;
	int arGrades[size];
	float sumGrades = 0;  //сумма, для подсчета среднего балла
	menu();
	int choice;  //переменная для вариантов меню
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 12:
		{
			setAllTwelwe(arGrades, size);  //вызов функции, ставящей все 12
			menu();
			cin >> choice;  //не получилось сделать частью функции menu
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
			cout << "Средний балл ученика: " << averGrade(arGrades, size) << endl;
			if (averGrade(arGrades, size) >= 10.7) cout << "Студент получит стипендию\n";
			else if (averGrade(arGrades, size) < 10.7) cout << "Студент не получит стипендию, средний балл слишком низок\n";
			else cout << "Ошибка! Выставьте оценки заново\n";
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
	cout << "Поставьте оценки за урок, по 12-балльной системе: \n\n";
	int i = 0;
	for (i = 0; i < size; i++)
	{
		cout << "Введите оценку за урок № " << i + 1 << "  ";
		cin >> arGrades[i];
		if ((arGrades[i] > 12) || (arGrades[i] <= 0))
		{
			cout << "\nОшибка! Введите верную оценку за урок " << i + 1 << " (от 1 до 12): ";
			do
			{
				cin >> arGrades[i];
			} while ((arGrades[i] > 12) || (arGrades[i] <= 0));
		}
	}
}
void showGrades(int arGrades[], int size)
{
	cout << "Все оценки ученика:\n";
	cout << ".-----------------------.\n";
	for (int i = 0; i < size; i++)
	{
		cout << "| Урок " << i + 1 << "\t| " << arGrades[i] << "\t|" << endl;
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
	cout << "Пересдача\n";
	cout << "Выберите номер урока для изменения оценки: " << endl;
	int i;
	cin >> i;
	cout << "Введите новую оценку за урок № " << i << "  ";
	cin >> arGrades[i - 1];
	if ((arGrades[i] > 12) || (arGrades[i] < 0))
	{
		do
		{
			cout << "\nОшибка! Введите верную оценку за урок " << i + 1 << " (от 1 до 12)";
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
	cout << "Выставлены по 12 баллов за все уроки.\n\n";
	Sleep(2000);
}