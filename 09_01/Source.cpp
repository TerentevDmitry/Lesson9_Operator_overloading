//// 09_01.cpp : 
//
//#include <iostream>
//
//class Fraction
//{
//public:
//	int numerator_;
//	int denominator_;
//
//public:
//	Fraction(int numerator, int denominator)
//	{
//		numerator_ = numerator;
//		denominator_ = denominator;
//	}
//
//	bool operator == (const Fraction& other)
//	{
//		std::cout << "Оператор " << this << std::endl;
//
//		numerator_;
//
//
//		return this;
//	}
//
//
//};
//
//
//
//
//
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
//	system("chcp 1251");
//	std::cout << std::endl;
//
//	Fraction f1(4, 3);
//	Fraction f2(6, 11);
//
//
//
//	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
//	//std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
//	//std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
//	//std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
//	//std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
//	//std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
//	return 0;
//}