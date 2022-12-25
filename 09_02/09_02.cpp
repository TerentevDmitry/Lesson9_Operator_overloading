// 09_01.cpp : 

#include <iostream>

class Fraction
{
private:
	int numerator_ = 0;
	int denominator_ = 0;
	int newNumerator1_ = 0;
	int newNumerator2_ = 0;

	void foo(const Fraction& other)
	{
		newNumerator1_ = this->numerator_ * other.denominator_;
		newNumerator2_ = other.numerator_ * this->denominator_;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator == (const Fraction& other)
	{
		foo(other);
		return newNumerator1_ == Fraction::newNumerator2_;
	}

	bool operator != (const Fraction& other)
	{
		return newNumerator1_ != newNumerator2_;
	}

	bool operator < (const Fraction& other)
	{
		return newNumerator1_ < newNumerator2_;
	}

	bool operator > (const Fraction& other)
	{
		return newNumerator1_ > newNumerator2_;
	}

	bool operator <= (const Fraction& other)
	{
		return newNumerator1_ <= newNumerator2_;
	}

	bool operator >= (const Fraction& other)
	{
		return newNumerator1_ >= newNumerator2_;
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