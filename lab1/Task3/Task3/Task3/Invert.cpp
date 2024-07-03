#include "Invert.h"

using namespace std;

const int MATRIX_SIZE = 3;

//дать именна переменным, чтобы была понятна позиции (m11)
double Determinant2x2(double a, double b, double c  , double d) 
{
    return a * d - b * c;
}

//для матрицы std::array
double Determinant3x3(double matrix[MATRIX_SIZE][MATRIX_SIZE]) 
{
    double det = 0;
    for (int i = 0; i < MATRIX_SIZE; ++i) 
    {
        double minor[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
        for (int j = 1; j < MATRIX_SIZE; ++j) 
        {
            for (int k = 0, l = 0; k < MATRIX_SIZE; ++k) 
            {
                if (k == i) continue;
                minor[j - 1][l++] = matrix[j][k];
            }
        }
        double sign = (i % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][i] * Determinant2x2(minor[0][0], minor[0][1], minor[1][0], minor[1][1]);
    }
    return det;
}

//исходная матрица должна быть неизменяемой
void InvertMatrix(double matrix[MATRIX_SIZE][MATRIX_SIZE], double result[MATRIX_SIZE][MATRIX_SIZE]) {
    double det = Determinant3x3(matrix);
    if (det == 0)
    {
        //не понятно, успешно или не успешно
        cerr << "Матрица вырождена, обратной матрицы не существует.\n";
        return;
    }

    for (int i = 0; i < MATRIX_SIZE; ++i) 
    {
        for (int j = 0; j < MATRIX_SIZE; ++j) 
        {
            double minor[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
            for (int k = 0, r = 0; k < MATRIX_SIZE; ++k) 
            {
                if (k == i) continue;
                for (int l = 0, c = 0; l < MATRIX_SIZE; ++l) 
                {
                    if (l == j) continue;
                    minor[r][c++] = matrix[k][l];
                }
                ++r;
            }
            double sign = ((i + j) % 2 == 0) ? 1 : -1;
            result[j][i] = sign * Determinant2x2(minor[0][0], minor[0][1], minor[1][0], minor[1][1]) / det;
        }
    }

}

//не нужна, вместо нее просто вывод матрицы
string DoubleToString(double invertedMatrix[MATRIX_SIZE][MATRIX_SIZE])
{
    string result = "";
    for (int i = 0; i < MATRIX_SIZE; ++i) 
    {
        for (int j = 0; j < MATRIX_SIZE; ++j) 
        {
            {
                result += to_string(invertedMatrix[i][j]) + " ";
            }
        }
        result += "\n";
    }
    return result;
}

string Invert(string inputFileName)
{
    ifstream inputFile(inputFileName);
    if (!inputFile) 
    {
        cerr << "Не удалось открыть файл" + inputFileName + "\n";
        return "";
    }

    //чтение матрицы в отдельную функцию
    double matrix[MATRIX_SIZE][MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; ++i) 
    {
        for (int j = 0; j < MATRIX_SIZE; ++j) 
        {
            if (!(inputFile >> matrix[i][j])) 
            {
                cerr << "Не удалось считать матрицу из файла.\n";
                return "";
            }
        }
    }

    string result;

    double invertedMatrix[MATRIX_SIZE][MATRIX_SIZE];
    InvertMatrix(matrix, invertedMatrix);

    return DoubleToString(invertedMatrix);
}