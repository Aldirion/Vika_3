#pragma once
class TBoolMatrix
{
	int size;
	bool ** M;
public:
	TBoolMatrix();
	TBoolMatrix(const TBoolMatrix &cpy);
	const TBoolMatrix &operator =(const TBoolMatrix &t);
	TBoolMatrix operator +(const TBoolMatrix &t)const;
	TBoolMatrix operator *(const TBoolMatrix &t)const;
	TBoolMatrix &operator !();
	void Set();
	void ShowData();
	int QuantityOfTrues();
	int QuantityOfFalses();
	friend std::istream &operator >>(std::istream &_in, TBoolMatrix &obj);
	friend std::ostream &operator <<(std::ostream &_out, const TBoolMatrix &obj);
	~TBoolMatrix();
};

class TBoolMatrixAnalizer
{
	int size;
	TBoolMatrix* arr;
public:
	TBoolMatrixAnalizer();
	int SearchMaxTrue();
	void Show(int ind);
	void ShowAll();
	~TBoolMatrixAnalizer();
};
