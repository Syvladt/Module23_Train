// Train.cpp: определяет точку входа для приложения.
// Девятвый вагон - это тот, что сразу после восьмого,
// а не тот, что перед десятым.
// Особо комментировать нечего.

#include "Train.h"
#include <iostream>
#define TRAIN(action) action ## _train
#define LENGHT_OF_TRAIN 10
#define LIMIT_PASS_WAGON 20

void filling_train(int train[])
{
	for (int i = 0; i < LENGHT_OF_TRAIN; ++i)
	{
		std::cout << "Enter the number of passengers in the wagon " << i + 1 << ": ";
		std::cin >> train[i];
		while (train[i] < 0 || train[i] > LIMIT_PASS_WAGON)
		{
			std::cout << "Incorrect input. Repeate please: ";
			std::cin >> train[i];
		}
	}
}

void sort_train(int train[])
{
	for (int i = 0; i < LENGHT_OF_TRAIN; ++i)
	{
		for (int j = 0; j < LENGHT_OF_TRAIN; ++j)
		{
			if (train[i] > train[j])
				std::swap(train[i], train[j]);
		}
	}
}

void show_train(int train[])
{
	int summ = 0;
	sort_train(train);
	for (int i = 0; i < LENGHT_OF_TRAIN; ++i)
	{
		std::cout << train[i] << '\n';
		summ += train[i];
	}
	std::cout << std::string(25, '=') << '\n' << "Total passengers: " << summ;
}

int main()
{
	int train[10] = {};
	TRAIN(filling)(train);
	TRAIN(show)(train);
	return 0;
}
