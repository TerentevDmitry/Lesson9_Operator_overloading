// 09_02.cpp : Остальные операции с дробями

#include <iostream>
#include <cmath>

class Fraction
{
private:
	int numerator_ = 0;
	int denominator_ = 0;

	int NOD(int numerator, int denominator) //Наименьший общий делитель
	{
		numerator = abs(numerator);
		denominator = abs(denominator);

		while (numerator > 0 && denominator > 0)

			if (numerator > denominator)
				numerator %= denominator;

			else
				denominator %= numerator;

		return numerator + denominator;
	}

public:
	Fraction() = default;
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator + (const Fraction& other) //Сложение и сокращение дробей
	{
		Fraction temp;
		
		temp.numerator_ = ((this->numerator_ * other.denominator_) + (other.numerator_ * this->denominator_));
		temp.denominator_ = (this->denominator_ * other.denominator_);
	
		int nod = NOD(temp.numerator_, temp.denominator_);
		
		temp.numerator_ = temp.numerator_ / nod;
		temp.denominator_ = temp.denominator_ / nod;

		return temp;
	}

	Fraction operator - (const Fraction& other) //Вычитание и сокращение дробей
	{
		Fraction temp;

		temp.numerator_ = ((this->numerator_ * other.denominator_) - (other.numerator_ * this->denominator_));
		temp.denominator_ = (this->denominator_ * other.denominator_);

		int nod = NOD(temp.numerator_, temp.denominator_);

		temp.numerator_ = temp.numerator_ / nod;
		temp.denominator_ = temp.denominator_ / nod;

		return temp;
	}

	Fraction operator * (const Fraction& other) //Умножение и сокращение дробей
	{
		Fraction temp;

		temp.numerator_ = this->numerator_ * other.numerator_;
		temp.denominator_ = this->denominator_ * other.denominator_;

		int nod = NOD(temp.numerator_, temp.denominator_);

		temp.numerator_ = temp.numerator_ / nod;
		temp.denominator_ = temp.denominator_ / nod;

		return temp;
	}

	Fraction operator / (const Fraction& other) //Деление и сокращение дробей
	{
		Fraction temp;

		temp.numerator_ = this->numerator_ * other.denominator_;
		temp.denominator_ = this->denominator_ * other.numerator_;

		int nod = NOD(temp.numerator_, temp.denominator_);

		temp.numerator_ = temp.numerator_ / nod;
		temp.denominator_ = temp.denominator_ / nod;

		return temp;
	}

	Fraction& operator++ () //Инкремент префиксный 
	{
		this->numerator_ = this->numerator_ + this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / nod;
		this->denominator_ = this->denominator_ / nod;

		return *this;
	}
	
	Fraction operator++ (int) //Инкремент постфиксный 
	{
		Fraction temp = *this;

		this->numerator_ = this->numerator_ + this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / nod;
		this->denominator_ = this->denominator_ / nod;

		return temp;
	}

	Fraction& operator-- () //Декремент префиксный 
	{
		this->numerator_ = this->numerator_ - this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / nod;
		this->denominator_ = this->denominator_ / nod;

		return *this;
	}

	Fraction operator-- (int) //Декремент постфиксный 
	{
		Fraction temp = *this;

		//++(*this);
		this->numerator_ = this->numerator_ - this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / nod;
		this->denominator_ = this->denominator_ / nod;

		return temp;
	}

	friend std::ostream& operator << (std::ostream& os, const Fraction& fra);
};

std::ostream& operator << (std::ostream& os, const Fraction& fra)
{
	if (fra.denominator_ == 1)
		os << fra.numerator_ /*<< std::endl*/;
	else
		os << fra.numerator_ << "/" << fra.denominator_ /*<< std::endl*/;
	
	return os;
}
	
int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");
	std::cout << std::endl;

	int numerator1 = 3;
	int denominator1 = 4;
	int numerator2 = 4;
	int denominator2 = 5;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator1;

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator2;

	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);
	
	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
	std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "++f1 = " << ++f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << "--f1 = "<< --f1  << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << "f1 = " << f1 << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "f2++ = " << f1 << " * " << ++f2 << " = " << f1 * f2 << std::endl;
	std::cout << "f2-- = " << f1 << " * " << f2-- << " = " << f1 * f2 << std::endl;
	std::cout << "f2-- = " << f1 << " * " << f2-- << " = " << f1 * f2 << std::endl;
	std::cout << "f2 = " << f2 << std::endl;
	std::cout << "----------------------------" << std::endl;

	return 0;
}