// 09_01.cpp : Сравнения в дробях

#include <iostream>

class Fraction
{
private:
	int numerator_ = 0;
	int denominator_ = 0;
	int prodNumeratorDenominator12_ = 0;
	int prodNumeratorDenominator21_ = 0;

	void saveCrossProducts(const Fraction& other)
	{
		prodNumeratorDenominator12_ = this->numerator_ * other.denominator_;
		prodNumeratorDenominator21_ = other.numerator_ * this->denominator_;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator == (const Fraction &other)
	{
		saveCrossProducts(other);
		return prodNumeratorDenominator12_ == Fraction::prodNumeratorDenominator21_;
	}

	bool operator != (const Fraction& other)
	{
		return prodNumeratorDenominator12_ != prodNumeratorDenominator21_;
	}

	bool operator < (const Fraction& other)
	{
		return prodNumeratorDenominator12_ < prodNumeratorDenominator21_;
	}

	bool operator > (const Fraction& other)
	{
		return prodNumeratorDenominator12_ > prodNumeratorDenominator21_;
	}

	bool operator <= (const Fraction& other)
	{
		return prodNumeratorDenominator12_ <= prodNumeratorDenominator21_;
	}

	bool operator >= (const Fraction& other)
	{
		return prodNumeratorDenominator12_ >= prodNumeratorDenominator21_;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");
	std::cout << std::endl;
	 
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return 0;
}