//1. Создайте игру «Морской бой».
//Правила игры : поле 10х10 клеток, корабли однопалубные 10 шт., не соприкасаются друг с другом.
//Игра заканчивается при полном уничтожении кораблей противника.
//Главные особенности реализации игры :
//? Режимы игры :
//? Человек – компьютер;
//? Компьютер – компьютер.
//? Расстановка кораблей :
//? Игрок расставляет вручную;
//? Компьютер расставляет за игрока.
//? Компьютер может играть в двух режимах :
//? Случайный выстрел;
//? Интеллектуальная игра.Компьютер строит стратегию игры, а не стреляет случайно.
//? Отображать текущее состояние игрового поля игрока и компьютера.
//? Возможность остановки, приостановки, повторного запуска игры. 
// (выгрузка - загрузка состояния игры в файл)
//Бонус:
//Многопалубные корабли, Разные варианты выстрелов, Размещение на поле не только кораблей 
// (сундуки, мины, острова и пр.), - русалка, кракен, 
//Интересная история для пользователя.Например, перенос истории в космос.

// ЧТО ЕЩЕ НАДО СДЕЛАТЬ:
// 
// функции и хэдеры в отдельные файлы
// 
// над визуалом поработать
// свои корабли отображать не так
// 
//счет в пиастрах?
//русалки, сундуки, бомбы? бонусы на карте
// разные выстрелы?
// 
// шторм!
// 
// сирены
//
//прописать заголовок,
//записать правила
//
//режимы: комп против компа !!!
//
// умная игра бота - хотя бить по раненым и не повторяться
// 
// остановка, приостановка, запись!!??
// 
//расстановка кораблей: вручную 

//
//Для того, чтобы в C++ работать с файлами необходимо подключить заголовочный файл fstream :
//
//После этого можно объявлять объекты, привязанные к файлам : для чтения данных из файла используются объекты типа ifstream(аббревиатура от input file stream, для записи данных в файл используются объекты типа ofstream(output file stream).Например
//
//	Чтобы привязать тот или иной поток к файлу(открыть файл для чтения или для записи) используется метод open, которому необходимо передать параметр – текстовую строку, содержащую имя открываемого файла.
//
//	После открытия файлов и привязки их к файловым потокам, работать с файлами можно так же, как со стандартными потоками ввода - вывода cin и cout.Например, чтобы вывести значение переменной x в поток fout используются следующая операция
//
//	А чтобы считать значение переменной из потока fin
//
//	Для закрытия ранее открытого файла используется метод close() без аргументов :
//
//Закрытый файловый поток можно переоткрыть заново при помощи метода open, привязав его к тому же или другому файлу.

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

void showMap(int map[][mSIZE], int fog[][mSIZE], bool useFog);      //показ поля на экран
int shipChecks(int map[][mSIZE], int shipSize, int shipCount);     //проверки для установки кораблей
int shipSet(int map[][mSIZE]);   //установки кораблей
int shooting(int map[][mSIZE], int fog[][mSIZE], int x, int y);  //стрельба
int shipsID = 1;        //Глобальные переменные... //для сквозного нумерования всех кораблей
int ships[SHIPSNUM] = { 0 };   //массив, в котором будет храниться палубность кораблей

int main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned)time(NULL));
	bool useFog = 0;  //переменная для "тумана войны"
	int map[mSIZE][mSIZE] = { 0 };   //массив кораблей нашего поля (1го)
	int map2[mSIZE][mSIZE] = { 0 }; //массив корабле противника (игрока 2)

	int fog[mSIZE][mSIZE] = { 0 }; //"туман войны", для сокрытия кораблей противника
	int fog2[mSIZE][mSIZE] = { 0 };

	shipSet(map);    //ставим корабли на наше поле (пока только автоматом)
	shipsID = 1;    //чтобы палубность кораблей записывалась заново для второго поля
	shipSet(map2); //ставим корабли соперника



	int x = 0, y = 0;     //переменные координат
	int happyHitX = 0, happyHitY = 0;   //хранят координаты удачного попадания, Х и У, для "добивания"
	int smartMode = 0;   //первый режим(нулевой) бота
	int xBot = 0; int yBot = 0;  //кооринаты для бота
	int dir = 0;  //направление

	vector <int> dirs;//автоматизирование процесса выбора (ВЕКТОР)
	dirs.push_back(3); dirs.push_back(2); dirs.push_back(1); dirs.push_back(0);

	//индикаторы победы
	bool youWin = 0, botWin = 0;
	bool turn = 1;    //очередность: 1 - ходит человек, 0 - комп




	while (youWin == false && botWin == false)  //цикл до победы одного игрока
	{
		int shootResult = 0;
		do //этот цикл отвечает за стрельбу одного из игроков, пока не будет промах
		{
			cout << "\n\tВАШЕ ПОЛЕ:\n";  showMap(map, fog, 0);  //отображаем обе карты на экран
			cout << "     ПОЛЕ ПРОТИВНИКА:\n"; showMap(map2, fog2, 0);
			if (turn == 1)
			{
				cout << "\tВАШ ХОД!" << endl;
				do
				{

					//ПОТОМ СДЕЛАТЬ УДОБНЕЕ - или А1, Б8...  или клавишами, как в том лабиринте
					cout << "Введите координаты цели:\n";
					cin >> x; cin >> y;

				} while (((x < 0) || x > 10) && ((y < 0) || (y > 10)));  //повтор, для корректного ввода
				x--; y--; //чтобы не 0й столбец, строка

				shootResult = shooting(map2, fog2, x, y);   //игрок стреляет по 2му полю (компьютера)

				if (shootResult == 1) cout << "\aРанен!" << endl;
				else if (shootResult == 2) cout << "\aУбит!" << endl;
				else  cout << "Мимо!" << endl;
			}
			else
			{
				cout << "Ход компьютера:\n";
				Sleep(1000);
				if (smartMode == 0)
				{
					do
					{
						xBot = rand() % mSIZE;    //генерируем координаты
						yBot = rand() % mSIZE;   //отображаем выбор бота
						cout << xBot + 1 << endl;
						cout << yBot + 1 << endl;
						shootResult = shooting(map, fog, xBot, yBot);  //стреляем
					} while (shootResult == 3);

					if (shootResult == 1)
					{
						smartMode = 1;
						happyHitX = xBot;
						happyHitY = yBot;
						if (!dirs.empty())     //empty - проверяет, пустой вектор или нет
						{
							dir = dirs[dirs.size() - 1];    //доступ к последнему элементу
							dirs.pop_back();    //удаление из вектора
						}
						cout << "\aРанен!" << endl;
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
						cout << "\aУбит!" << endl;
					}
					else cout << "Промах!" << endl;
				}
				else if (smartMode == 1)
				{
					bool changeDir = 0;    //переменная, которая следит за тем нужно ли менять направление или нет
					if (dir == 0)         //движение влево
					{
						if (xBot > 0)
							xBot--;
						else
						{
							changeDir = 1;
						}
					}
					else if (dir == 1)    //движение вправо
					{
						if (xBot < mSIZE - 1)
							xBot++;
						else
						{
							changeDir = 1;
						}
					}
					else if (dir == 2)    //движение вверх
					{
						if (yBot > 0)
							yBot--;
						else
						{
							changeDir = 1;
						}
					}
					else if (dir == 3)    //движение вниз
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

					if (shootResult == 1)    //если ранили
					{
						smartMode = 1;  //вкл умный режим
						happyHitX = xBot;
						happyHitY = yBot;

						if (!dirs.empty())//empty - проверяет, пустой вектор или нет
						{
							dir = dirs[dirs.size() - 1];//доступ к последнему элементу
							dirs.pop_back();  //удаление
						}

						cout << "\aРанен!" << endl;
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
						for (int i = 1; i <= SHIPSNUM; i++) //расстановка для человека
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
						cout << "\aУбит!" << endl;
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
						cout << "Промах!" << endl;
					}
				}
			}

			Sleep(1500);
			system("cls");
		} while (shootResult != 0); //пока не будет промаха, стреляет один игрок
		turn = !turn; //если мимо - смена хода
	}
	if (youWin == 1)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "~~~~~Вы победили!~~~~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;

	}
	else if (botWin == 1)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "~~~~~Вы проиграли~~~~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	system("pause");
	return 0;
}

void showMap(int map[][mSIZE], int fog[][mSIZE], bool useFog)
{
	int k = 1;     //для отображения вертикальной оси координат
	cout << "  .А_Б_В_Г_Д_Е_Ё_Ж_З_И." << endl; //для отображения горизонтальной оси координат//
	//cout << "   1_2_3_4_5_6_7_8_9_10" << endl; //для отображения горизонтальной оси координат
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
				else if (map[i][j] == -3) //убит
					cout << "Х ";
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
				//проверка граничащих клеток
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

int shooting(int map[][mSIZE], int fog[][mSIZE], int x, int y)  //стрельба
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
