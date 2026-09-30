#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int getElement(int** a, int n, int i, int j) {
    return a[i][j];
}

bool isLocalMinimum(int** a, int n, int i, int j) {
    int val = getElement(a, n, i, j);
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0) continue;
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                if (getElement(a, n, ni, nj) <= val) {
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

    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }

    cout << "Введите элементы матрицы." << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int si = n - j - 1;
            int sj = n - i - 1;
            if (si < i || (si == i && sj < j)) {
                continue;
            }
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
            if (si != i || sj != j) {
                a[si][sj] = a[i][j];
            }
        }
    }

    cout << "Введённая матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int localMinCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int si = n - j - 1;
            int sj = n - i - 1;
            if (si < i || (si == i && sj < j)) {
                continue;
            }
            if (isLocalMinimum(a, n, i, j)) {
                localMinCount++;
                if (si != i || sj != j) {
                    localMinCount++;
                }
            }
        }
    }

    long long sumAboveMainDiag = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sumAboveMainDiag += abs(a[i][j]);
        }
    }

    cout << "Число локальных минимумов: " << localMinCount << endl;
    cout << "Сумма модулей элементов выше главной диагонали (не включая диагональ): " 
         << sumAboveMainDiag << endl;

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}