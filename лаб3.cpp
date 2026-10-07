#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int getStorageIndex(int i, int j, int n) {
    int r = i;
    int c = j;

    if (r + c > n - 1) {
        r = n - 1 - j;
        c = n - 1 - i;
    }

    int offset = r * n - (r * (r - 1)) / 2;
    return offset + (c - r);
}


int getElement(const int* data, int n, int i, int j) {
    return data[getStorageIndex(i, j, n)];
}

void setElement(int* data, int n, int i, int j, int val) {
    data[getStorageIndex(i, j, n)] = val;
}



bool isLocalMinimum(const int* data, int n, int i, int j) {
    int val = getElement(data, n, i, j);
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) continue;
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                if (getElement(data, n, ni, nj) <= val) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isValidSize(int n) {
    return n > 0 && n <= 10;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размерность квадратной матрицы (1 <= n <= 10): ";
    cin >> n;

    if (!isValidSize(n)) {
        cout << "Ошибка: размерность должна быть от 1 до 10." << endl;
        return 1;
    }


    int totalElements = n * (n + 1) / 2;
    int* data = new int[totalElements];

    cout << "Введите уникальные элементы матрицы (побочная диагональ и выше неё):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << "a[" << i << "][" << j << "] = ";
            int val;
            cin >> val;
            setElement(data, n, i, j, val);
        }
    }

    cout << "\nВведённая матрица (с восстановленной симметрией):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << getElement(data, n, i, j) << "\t";
        }
        cout << endl;
    }


    int localMinCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isLocalMinimum(data, n, i, j)) {
                localMinCount++;
            }
        }
    }

 
    long long sumAboveMainDiag = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sumAboveMainDiag += abs(getElement(data, n, i, j));
        }
    }

    cout << "\nЧисло локальных минимумов: " << localMinCount << endl;
    cout << "Сумма модулей элементов выше главной диагонали (не включая диагональ): " 
         << sumAboveMainDiag << endl;

    delete[] data;

    return 0;
}
