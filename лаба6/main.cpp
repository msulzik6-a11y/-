#include "Fraction.h"
#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    try
    {
        Fraction a(6, 8);
        Fraction b(-5, 6);

        std::cout << "a = ";
        a.print();
        std::cout << '\n';

        std::cout << "b = ";
        b.print();
        std::cout << '\n';

        Fraction c(5, -10);
        std::cout << "c = ";
        c.print();
        std::cout << "\n\n";

        std::cout << "get-методы: a = "
                  << a.getNumerator()
                  << '/'
                  << a.getDenominator()
                  << "\n\n";

        std::cout << "a + b = ";
        a.add(b).print();
        std::cout << '\n';

        std::cout << "a * b = ";
        a.multiply(b).print();
        std::cout << '\n';

        std::cout << "a / b = ";
        a.divide(b).print();
        std::cout << "\n\n";

        Fraction copy(a);
        std::cout << "copy(a) = ";
        copy.print();
        std::cout << "\n\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }

    try
    {
        std::cout << "Проверка нулевого знаменателя:\n";
        Fraction bad(1, 0);
        std::cout << "Эта строка не выполнится\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}
