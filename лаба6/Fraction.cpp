#include "Fraction.h"
#include <numeric>
#include <stdexcept>

Fraction::Fraction(int num, int den)
    : numerator(num), denominator(den)
{
    if (den == 0)
        throw std::invalid_argument("Знаменатель не может быть равен нулю");

    reduce();
}

Fraction::Fraction(const Fraction& other)
    : numerator(other.numerator)
    , denominator(other.denominator)
{
}

int Fraction::getNumerator() const
{
    return numerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}

Fraction Fraction::add(const Fraction& other) const
{
    const int num = numerator * other.denominator
                  + other.numerator * denominator;
    const int den = denominator * other.denominator;

    return Fraction(num, den);
}

Fraction Fraction::multiply(const Fraction& other) const
{
    const int num = numerator * other.numerator;
    const int den = denominator * other.denominator;

    return Fraction(num, den);
}

Fraction Fraction::divide(const Fraction& other) const
{
    if (other.numerator == 0)
        throw std::domain_error("Деление на нулевую дробь");

    const int num = numerator * other.denominator;
    const int den = denominator * other.numerator;

    return Fraction(num, den);
}

void Fraction::print(std::ostream& out) const
{
    out << numerator << '/' << denominator;
}

void Fraction::reduce()
{
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    const int divisor = std::gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}
