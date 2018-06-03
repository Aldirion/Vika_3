#include <iostream>
#include <iomanip>
#include "TBoolMatrix.h"

using namespace std;

int MSize(0);

TBoolMatrix::TBoolMatrix()
{
	size = MSize;
	M = new bool*[size];
	for (int i = 0; i < size; i++)
	{
		M[i] = new bool[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			M[i][j] = rand()%2;
	}
}

TBoolMatrix::TBoolMatrix(const TBoolMatrix &cpy)//Конструктор копирования
{
	size = cpy.size;
	M = new bool*[size];
	for (int i = 0; i < size; i++)
		M[i] = new bool[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			M[i][j] = cpy.M[i][j];
}

const TBoolMatrix & TBoolMatrix::operator=(const TBoolMatrix & t)
{
	size = t.size;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			M[i][j] = t.M[i][j];
	return *this;
}

TBoolMatrix TBoolMatrix::operator+(const TBoolMatrix & t) const
{
	TBoolMatrix tmp(*this);//копируем текущий объект во временный объект.
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			tmp.M[i][j] += t.M[i][j];
	return tmp;
}

TBoolMatrix TBoolMatrix::operator*(const TBoolMatrix & t) const
{
	TBoolMatrix tmp(*this);//копируем текущий объект во временный объект.
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			tmp.M[i][j] &= t.M[i][j];
	return tmp;
}

TBoolMatrix  &TBoolMatrix::operator!()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			M[i][j] = !M[i][j];
	return *this;
}

void TBoolMatrix::Set()
{
	cin >> *this;//надо же где-то использовать перегруженный оператор ввода¯\_(ツ)_/¯
}
void TBoolMatrix::ShowData()
{
	cout << *this << "\n\n\n";//с операторам вывода такая же ситуация)))0)
}
int TBoolMatrix::QuantityOfTrues()
{
	int T(0);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (M[i][j])
				T++;
	return T;
}

int TBoolMatrix::QuantityOfFalses()
{
	int T(0);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (!M[i][j])
				T++;
	return T;
}

TBoolMatrix::~TBoolMatrix()
{
	if (M)
	{
		for (int i = 0; i < size; i++)
			delete[] M[i];
		delete[] M;
		M = NULL;
	}
}

std::istream & operator>>(std::istream & _in, TBoolMatrix & obj)
{
	for (int i = 0; i < obj.size; i++)
		for (int j = 0; j < obj.size; j++)
			_in >> obj.M[i][j];
	return _in;
}

std::ostream & operator<<(std::ostream & _out, const TBoolMatrix & obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		for (int j = 0; j < obj.size; j++)
			_out << setw(3) << obj.M[i][j];
		_out << "\n";
	}
	return _out;
}

TBoolMatrixAnalizer::TBoolMatrixAnalizer()
{
	cout << "Введите количество матриц.\n\n>>>";
	cin >> size;
	cout << "Введите размер матриц (MxM)\n\n";
	cin >> MSize;
	arr = new TBoolMatrix[size];
}

int TBoolMatrixAnalizer::SearchMaxTrue()//поиск объекта с максимальным количеством "1"
{
	int max(0), ind(0);
	for (int i = 0; i < size; i++)
		if (arr[i].QuantityOfTrues() > max)
		{
			max = arr[i].QuantityOfTrues();
			ind = i;
		}
	return ind+1;
}

void TBoolMatrixAnalizer::Show(int ind)
{
	arr[ind].ShowData();
}

void TBoolMatrixAnalizer::ShowAll()
{
	TBoolMatrix tmp;
	for (int i = 0; i < size; i++)
	{
		cout <<i<< ".\n";
		arr[i].ShowData();
	}
	cout << "Конъюнкция матриц 1 и 2: \n\n";
	tmp = arr[0] * arr[1];
	cout << tmp << "\n\n";
	cout << "Дизъюнкция матриц 1 и 2: \n\n";
	tmp = arr[0] + arr[1];
	cout << tmp << "\n\n";
	cout << "Матрица 1 и её отрицание: \n\n"<<arr[0];
	cout << "\n" <<!arr[0]<< "\n\n";
}

TBoolMatrixAnalizer::~TBoolMatrixAnalizer()
{
}
