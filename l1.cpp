#include <iostream>
#include <cmath>     
#include <iomanip>
int main() {
    system("chcp 65001");
    double x;
    int k;
    std::cout << "Введите x (число от -1 до 1)";
    std::cin >> x;
    std::cout << "Введите k (количество цифр после запятой)";
    std::cin >> k;
    double e = std::pow(10.0, -k);
    double sum = 1.0;
    double a = 0.5 * x;
    int n = 1;
    while (std::abs(a) >= e) {
sum += a;
n++;
a = a * (-(2.0 * n - 3.0) / (2.0 * n) * x);
    }
    double y = std::sqrt(1.0 + x);
    std::cout << std::fixed << std::setprecision(k); //??
    std::cout << " результат через ряд: " << sum << std::endl;
    std::cout << "результат через стандартную функцию: " << y << std::endl;
    std::cout << "Количество шагов цикла:     " << n << std::endl;
}