// LUPConsole.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include "LUP.h"

using namespace std;
using namespace MyMath;

int main()
{
    const int n = 10;
    const int m = n;

    cout << " LU Factorization with Partial Pivoting ";
    cout << " (n = " << to_string(n) << ") : " << endl;

    cout << "===========================================================" << endl;

    //double** matrix = new double* [m];
    //double* x = new double[m];

    Fraction** matrix = new Fraction * [m];
    Fraction* x = new Fraction[m];

    //Taylor series of exp(x)
    long long coefficients[m + n + 1];
    coefficients[0] = 1;
    for (int i = 1; i < m + n + 1; i++)
        coefficients[i] = coefficients[i - 1] * i;

    //try to calculate the rational function of Pade approximant of exp(x)
    for (int i = 0; i < m; i++) {
        x[i] = Fraction(-1, coefficients[n + 1 + i]);
        //matrix[i] = new double[n];
        matrix[i] = new Fraction[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = Fraction(1, coefficients[n + i - j]);
        }
    }

    cout << " A : " << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << " | " << to_string(matrix[i][j].numerator) << "/" << to_string(matrix[i][j].denominator);
        }
        cout << " |\n";
    }

    cout << endl;

    cout << " b : " << endl;

    for (int i = 0; i < m; i++) {
        if (x[i].denominator == 1)
            cout << " |  " << to_string(x[i].numerator) << " ";
        else
            cout << " | " << to_string(x[i].numerator) << "/" << to_string(x[i].denominator);
        cout << " |\n";
    }

    LUP::SolvingLinearEquations(n, matrix, x);

    cout << "===========================================================" << endl;

    cout << " L : " << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << " |  1 ";
            else if (i < j)
                cout << " |  0 ";
            else if (matrix[i][j].denominator == 1)
                cout << " |  " << to_string(matrix[i][j].numerator) << " ";
            else
                cout << " | " << to_string(matrix[i][j].numerator) << "/" << to_string(matrix[i][j].denominator);
        }
        cout << " |\n";
    }

    cout << endl;

    cout << " U : " << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j)
                cout << " |  0 ";
            else if (matrix[i][j].denominator == 1)
                cout << " |  " << to_string(matrix[i][j].numerator) << " ";
            else
                cout << " | " << to_string(matrix[i][j].numerator) << "/" << to_string(matrix[i][j].denominator);
        }
        cout << " |\n";
    }

    cout << endl;

    cout << " x : " << endl;

    for (int i = 0; i < m; i++) {
        if (x[i].denominator == 1)
            cout << " |  " << to_string(x[i].numerator) << " ";
        else
            cout << " | " << to_string(x[i].numerator) << "/" << to_string(x[i].denominator);
        cout << " |\n";
    }


    for (int i = 0; i < m; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] x;

    cout << endl;

    system("pause");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
