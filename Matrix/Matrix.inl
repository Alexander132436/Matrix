#pragma once
#include "Matrix.h"

template <class T>
void Matrix<T>::clear()
{
	if (arr != nullptr)
	{
		for (int j = 0; j < height; j++)
		{
			delete[] arr[j];
		}
		delete[] arr;
	}
	arr = nullptr;
}

template <class T>
void Matrix<T>::copyTo(T** from)
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			arr[j][i] = from[j][i];
		}
	}
}

template <class T>
Matrix<T>::Matrix(int height, int width)
{
	std::cout << "Вызвался конструктор" << this << std::endl;
	if (height <= 0 || width <= 0)
	{
		stopProgram("Wrong sizes!");
	}
	if (!allocate(height, width))
	{
		stopProgram("Wrong sizes!");
	}
}

template <class T>
Matrix<T>::Matrix()
{
	int height{}, width{};
	std::cout << "Введите количество строк матрицы: ";
	std::cin >> height;
	std::cout << "Введите количество столбцов матрицы: ";
	std::cin >> width;
	this->height = height;
	this->width = width;
	if (height <= 0 || width <= 0)
	{
		stopProgram("Wrong sizes!");
	}
	if (!allocate(height, width))
	{
		stopProgram("Wrong sizes!");
	}
}

template <class T>
void Matrix<T>::addDataByHand()
{
	std::cout << "Заполните матрицу: ";
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			std::cin >> arr[j][i];
		}
	}
}

template <class T>
void Matrix<T>::addDataByRandom()
{
	srand(time(NULL));

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			arr[j][i] = rand() % 100 + 1;
		}
	}
}

template <class T>
void Matrix<T>::Max()
{
	T max = arr[0][0];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; ++j)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	std::cout << max;
}
