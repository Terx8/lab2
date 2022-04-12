#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "stdio.h"


class DATA
{
private:

	int day;
	int mon;
	int yer;

	void incdec(int* _x, int addval) // инкремент/декремент (4, 5)
	{
		*_x += addval;
	}

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
	void resetDATA() // перерасчет даты
	{

		while (mon > 12)
		{
			mon -= 12;
			yer++;
		}

		while (mon <= 0)
		{
			if (!mon)
				mon = 12;

			if (mon < 0)
				mon += 13;

			yer--;
		}

		int monlen = 0;
		if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
			monlen = 31;
		if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			monlen = 30;
		if (mon == 2)
			monlen = 28;

		while (day > monlen)
		{
			day -= monlen;
			mon++;
			while (mon > 12)
			{
				mon -= 12;
				yer++;
			}
		}

		while (day <= 0)
		{
			mon--;
			if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
				monlen = 31;
			if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
				monlen = 30;
			if (mon == 2)
				monlen = 28;
			day = monlen + day;

			while (mon <= 0)
			{
				if (!mon)
					mon = 12;

				if (mon < 0)
					mon += 13;
				yer--;
			}
		}

	}

public:


	DATA() { day = mon = 1;  yer = 0; };

	void setDATA() // ввод даты
	{
		int d = 0, m = 0, y = 0;
		int enter = 0;

		while (d > 31 || d <= 0)
		{
			if (enter) std::cout << "invalid input" << std::endl;
			std::cout << "enter day: " << std::endl;
			enter++;
			cin(&d);
		}

		enter = 0;
		while (m > 12 || m <= 0)
		{
			if (enter) std::cout << "invalid input" << std::endl;
			std::cout << "enter month: " << std::endl;
			enter++;
			cin(&m);
		}

		enter = 0;
		while (y <= 0)
		{
			if (enter) std::cout << "invalid input" << std::endl;
			std::cout << "enter year: " << std::endl;
			enter++;
			cin(&y);
		}

		day = d; mon = m; yer = y; resetDATA();
	}


	
	DATA& operator ++ () // префикс инкремент 1
	{
		int choice = 0;
		std::cout << "enter 1 to increase day, 2 to inc month, 3 to inc year " << std::endl;
		while (choice <= 0 || choice > 3)
		{
			cin(&choice);
		}
		switch (choice)
		{
		case 1: incdec(&day, 1); break;
		case 2: incdec(&mon, 1); break;
		case 3: incdec(&yer, 1); break;
		}
		resetDATA();
		return *this;
	};

	
	DATA& operator -- () // префикс декремент 1
	{
		int choice = 0;
		std::cout << "enter 1 to decrease day, 2 to dec month, 3 to dec year " << std::endl;
		while (choice <= 0 || choice > 3)
		{
			cin(&choice);
		}
		switch (choice)
		{
		case 1: incdec(&day, -1); break;
		case 2: incdec(&mon, -1); break;
		case 3: incdec(&yer, -1); break;
		}
		resetDATA();
		return *this;
	};


	friend DATA& operator ++ (DATA& data, int) // постфикс инкремент введенное значение
	{
		int choice = 0;
		std::cout << "enter 1 to increase on value day, 2 to dec month, 3 to dec year " << std::endl;
		while (choice <= 0 || choice > 3)
		{
			data.cin(&choice);
		}

		int value = 0;
		std::cout << "enter value: " << std::endl;
		getchar();
		data.cin(&value);

		switch (choice)
		{
		case 1: data.incdec(&data.day, value); break;
		case 2: data.incdec(&data.mon, value); break;
		case 3: data.incdec(&data.yer, value); break;
		}
		data.resetDATA();
		return data;
	};

	
	friend int operator -- (DATA& data, int) // постфикс декремент введенное значение
	{

		int choice = 0;
		std::cout << "enter 1 to decrease on value day, 2 to dec month, 3 to dec year " << std::endl;
		while (choice <= 0 || choice > 3)
		{
			data.cin(&choice);
		}
		int value = 0;
		std::cout << "enter value: " << std::endl;
		getchar();
		data.cin(&value);
		switch (choice)
		{
		case 1: data.incdec(&data.day, -value); break;
		case 2: data.incdec(&data.mon, -value); break;
		case 3: data.incdec(&data.yer, -value); break;
		}

		data.resetDATA();
		return 0;
	};

	operator int() // оператор преобразования типа int
	{
		return day + mon * 100 + yer * 10000;
	}

};
