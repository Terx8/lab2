#include <iostream>
#include "classQueue.h"

void cin(int* _x)
{
	while (true)
	{
		std::cin >> *_x;
		if (std::cin.good())
		{
			break;
		}
		std::cout << "invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}


int main()
{
	int size1, size2;
	std::cout << "enter size for q1: ";
	std::cin >> size1;
	std::cout << "enter size for q2: ";
	std::cin >> size2;

	Queue* q[2];
	q[0] = new Queue(size1);
	q[1] = new Queue(size2);

	int command = 0;
	while (command == 0)
	{

		std::cout << "\n0 exit; \n1 push one element; \n2 pop el: enter how many; \n3 push till this queue is full; \n4 multiply all by a value; \n5 see all; \n6 make q1 equal to q2 " << std::endl;
		std::cout << "COMPARISON:  10 q1 != q2;  11 q1 == q2;  12 q1 < q2;  13 q1 <= q2;  14 q1 > q2;  15 q1 >= q2\n" << std::endl;
		cin(&command);
		switch (command)
		{
		case 0:
			return 0;
		case 1: // добавить один элемент
		{
			int choice = 0;
			std::cout << "choose 1st or 2nd queue (enter 1 or 2): ";
			while (choice <= 0 || choice > 2) cin(&choice);
			choice -= 1;

			int val; std::cout << "push: ";
			cin(&val);

			(*q[choice]) + val;


		} break;

		case 2: // удалить элементы: введите сколько
		{
			int choice = 0;
			std::cout << "choose 1st or 2nd queue (enter 1 or 2): ";
			while (choice <= 0 || choice > 2) cin(&choice);
			choice -= 1;

			int val = 0; std::cout << "how many pop: ";
			while (val <= 0) cin(&val);

			(*q[choice]) - val;
		} break;

		case 3: // ввести элементы до конца очереди
		{
			int choice = 0;
			std::cout << "choose 1st or 2nd queue (enter 1 or 2): ";
			while (choice <= 0 || choice > 2) cin(&choice);
			choice -= 1;

			std::cin >> (*q[choice]);
		} break;

		case 4: // умножить все элементы на значение
		{
			int choice = 0;
			std::cout << "choose 1st or 2nd queue (enter 1 or 2): ";
			while (choice <= 0 || choice > 2) cin(&choice);
			choice -= 1;
			int val; std::cout << "value: ";
			cin(&val);

			(*q[choice]) * val;
		} break;

		case 5: // посмотреть все
		{
			int choice = 0;
			std::cout << "choose 1st or 2nd queue (enter 1 or 2): ";
			while (choice <= 0 || choice > 2) cin(&choice);
			choice -= 1;

			std::cout << (*q[choice]);
		} break;

		case 6: // сделать очереди равными
		{
			int choice = 0;
			std::cout << "enter 1 for q1 = q2, enter 2 for q2 = q1: ";
			while (choice <= 0 || choice > 2) cin(&choice);
			choice -= 1;
			if (choice == 0)
				(*q[0]) = (*q[1]);
			else
				if (choice == 1)
					(*q[1]) = (*q[0]);
		}break;

		case 10: // сравнение
		{
			(*q[0]) != (*q[1]);
		}break;

		case 11: // сравнение
		{
			(*q[0]) == (*q[1]);
		}break;

		case 12: // сравнение
		{
			(*q[0]) < (*q[1]);
		}break;

		case 13: // сравнение
		{
			(*q[0]) <= (*q[1]);
		}break;

		case 14: // сравнение
		{
			(*q[0]) > (*q[1]);
		}break;

		case 15: // сравнение
		{
			(*q[0]) >= (*q[1]);
		}break;

		default:
			break;
		}
		command = 0;
	}
	return 0;
}