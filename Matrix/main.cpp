#include <iostream>
#include <conio.h>
#include "Matrix.h"
#include "windows.h"

using namespace std;


int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Matrix<int> arr(3,3);
	arr.addDataByRandom();
	cout << arr;
	arr.Max();
	cout << endl;
	cout << arr / 3;
	
}