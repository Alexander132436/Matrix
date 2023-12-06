#pragma once
#include <iostream>
void stopProgram(std::string message)
{
	std::cout << message << std::endl;
	std::cout << "Press any key to exit program" << std::endl;
	exit(1);
}
template <class T>
class Matrix
{
private:
	int height;
	int width;
	T** arr;
	bool allocate(int height, int width)
	{
		if (height <= 0 && width <= 0)
		{
			return false;
		}
		this->height = height;
		this->width = width;
		arr = new T * [height];
		for (int j = 0; j < height; j++)
		{
			arr[j] = new T[width];
			for (int i = 0; i < width; i++)
			{
				arr[j][i] = T();
			}
		}
		return true;
	}

	void clear();
	
	void copyTo(T** from);
	
public:
	
	//Конструктор создания матрицы с нулевыми значениями
	Matrix(int height, int width);
	
	//Конструктор строк и столбцов вручную 
	Matrix();

	//Заполнение матрицы руками
	void addDataByHand();
	
	//Заполнение матрицы случайными числами
	void addDataByRandom();
	
	//Функция нахождения максимального элемента
	void Max();
	
	//Перегрузка оператора +
	template<class TT>
	Matrix<T>& operator+(const TT& z)
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; j++)
			{
				this->arr[i][j] += z;
			}
		}
		return *this;
	}

	//Перегрузка оператора -
	template<class TT>
	Matrix<T>& operator-(const TT& z)
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; j++)
			{
				this->arr[i][j] -= z;
			}
		}
		return *this;
	}

	//Перегрузка оператора *
	template<class TT>
	Matrix<T>& operator*(const TT& z)
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; j++)
			{
				this->arr[i][j] *= z;
			}
		}
		return *this;
	}

	//Перегрузка оператора /
	template<class TT>
	Matrix<T>& operator/(const TT& z)
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; j++)
			{
				this->arr[i][j] /= z;
			}
		}
		return *this;
	}

	//перегрузка оператора вывода на экран
	friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix) 
	{
		if (matrix.arr == nullptr)
		{
			output << "Empty matrix" << std::endl;
		}
		for (int j = 0; j < matrix.height; j++)
		{
			for (int i = 0; i < matrix.width; i++)
			{
				output << matrix.arr[j][i] << " ";
			}
			output << std::endl;
		}
		return output;
	}
	
	~Matrix() 
	{
		std::cout << "Вызвался диструктор" << this << std::endl;
		clear();
	}

};
#include "Matrix.inl"
