#include <iostream>
#include <ostream>
#include <istream>

class elem
{
public:
	int value;
	elem* next;
};

class Queue
{
	elem* first;
	elem* last;
	int reserveSize;
	int commitSize;

public:

	Queue(int _size)
	{
		first = new elem;
		first->value = 0;
		first->next = nullptr;
		last = first;
		reserveSize = _size;
		commitSize = 0;
	}

	Queue& operator = (Queue& Q2)
	{
		this - commitSize;
		last = first;
		commitSize = Q2.commitSize;
		reserveSize = Q2.reserveSize;

		elem* current = Q2.first->next;
		while (current != nullptr)
		{
			elem* add = new elem;
			add->value = current->value;
			add->next = nullptr;
			last->next = add;
			last = add;
			commitSize++;
			current = current->next;
		}

		return *this;
	}

	
	Queue& operator + (int _val) // добавить элементы
	{
		if (commitSize == reserveSize)
			std::cout << "cannot push, this queue is full" << std::endl;
		else {
			elem* add = new elem;
			add->value = _val;
			add->next = nullptr;
			last->next = add;
			last = add;
			commitSize++;
		}

		return *this;
	}


	Queue& operator - (int _val) // удалить элементы + сколько
	{
		elem* current = first->next;
		elem* keep;
		if (_val > commitSize)
			_val = commitSize;

		for (int i = 0; i < _val; i++)
		{
			current = first->next;
			keep = current;

			first->next = first->next->next;
			delete keep;

			commitSize--;
		}
		if (commitSize == 0)
			last = first;

		std::cout << "poped" << std::endl;
		return *this;
	}

	friend int operator *(Queue& Q, int _val) // умножение
	{
		elem* current = Q.first->next;
		while (current != nullptr)
		{
			current->value *= _val;
			current = current->next;
		}
		return 0;
	}

	
	friend std::ostream& operator<<(std::ostream& os, Queue& Q) // показать все элемены в очереди
	{
		std::cout << "THIS QUEUE IS: " << std::endl;
		elem* current = Q.first->next;
		while (current != nullptr)
		{
			os << current->value << " ";
			current = current->next;
		}
		return os << std::endl;
	}

	
	friend std::istream& operator>>(std::istream& is, Queue& Q) // добавить элементы, пока очередь не закончится
	{
		if (Q.commitSize == Q.reserveSize)
			std::cout << "cannot push, this queue is full" << std::endl;
		else
		{
			while (Q.commitSize < Q.reserveSize)
			{
				elem* current = Q.first->next;
				elem* add = new elem;
				std::cout << "enter new value: ";
				int val;

				while (true)
				{
					is >> val;
					if (std::cin.good())
					{
						break;
					}
					std::cout << "invalid input" << std::endl;
					is.clear();
					is.ignore();
				}


				add->value = val;
				add->next = nullptr;
				Q.last->next = add;
				Q.last = add;
				Q.commitSize++;
			}
		}
		return is;
	}


	friend void operator ==(Queue& Q1, Queue& Q2) // сравнения
	{
		elem* current1 = Q1.first->next;
		elem* current2 = Q2.first->next;
		while (current1 != nullptr)
		{
			std::cout << current1->value;
			std::cout << " == ";
			std::cout << current2->value;
			if (current1->value == current2->value)
				std::cout << " true" << std::endl;
			else
				std::cout << " false " << std::endl;

			current1 = current1->next;
			current2 = current2->next;

		}
	};

	friend void operator <(Queue& Q1, Queue& Q2)
	{
		elem* current1 = Q1.first->next;
		elem* current2 = Q2.first->next;
		while (current1 != nullptr)
		{
			std::cout << current1->value;
			std::cout << " < ";
			std::cout << current2->value;
			if (current1->value < current2->value)
				std::cout << " true" << std::endl;
			else
				std::cout << " false " << std::endl;

			current1 = current1->next;
			current2 = current2->next;
		}
	};

	friend void operator <=(Queue& Q1, Queue& Q2)
	{
		elem* current1 = Q1.first->next;
		elem* current2 = Q2.first->next;
		while (current1 != nullptr)
		{
			std::cout << current1->value;
			std::cout << " <= ";
			std::cout << current2->value;
			if (current1->value <= current2->value)
				std::cout << " true" << std::endl;
			else
				std::cout << " false " << std::endl;

			current1 = current1->next;
			current2 = current2->next;
		}
	};

	friend void operator >(Queue& Q1, Queue& Q2)
	{
		elem* current1 = Q1.first->next;
		elem* current2 = Q2.first->next;
		while (current1 != nullptr)
		{
			std::cout << current1->value;
			std::cout << " > ";
			std::cout << current2->value;
			if (current1->value > current2->value)
				std::cout << " true" << std::endl;
			else
				std::cout << " false " << std::endl;

			current1 = current1->next;
			current2 = current2->next;
		}
	};

	friend void operator >=(Queue& Q1, Queue& Q2)
	{
		elem* current1 = Q1.first->next;
		elem* current2 = Q2.first->next;
		while (current1 != nullptr)
		{
			std::cout << current1->value;
			std::cout << " >= ";
			std::cout << current2->value;
			if (current1->value >= current2->value)
				std::cout << " true" << std::endl;
			else
				std::cout << " false " << std::endl;

			current1 = current1->next;
			current2 = current2->next;
		}
	};

	friend void operator !=(Queue& Q1, Queue& Q2)
	{
		elem* current1 = Q1.first->next;
		elem* current2 = Q2.first->next;
		while (current1 != nullptr)
		{
			std::cout << current1->value;
			std::cout << " != ";
			std::cout << current2->value;
			if (current1->value != current2->value)
				std::cout << " true" << std::endl;
			else
				std::cout << " false " << std::endl;

			current1 = current1->next;
			current2 = current2->next;
		}
	};
};