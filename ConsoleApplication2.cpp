#include <iostream>
using namespace std;

int get_data_rows_mass(char name_mass) {
    int rows;
    cout << "Введите количество строк матрицы " << name_mass << ": ";
    cin >> rows;
    return rows;
}

int get_data_columns_mass(char name_mass) {
    int columns;
    cout << "Введите количество столбцов матрицы " << name_mass << ": ";
    cin >> columns;
    return columns;
}

double** create_mass(int columns, int rows) {
    cout << "Построчно введите все элементы матрицы: " << endl;
    double** Mass = new double* [columns];
    for (int count = 0; count < columns; count++)
        Mass[count] = new double[rows];
    for (int i = 0;i < rows;i++)
        for (int j = 0;j < columns;j++) {
            cin >> Mass[j][i];
        }
    return Mass;
}

double** create_final_mass(int columns_A, int rows_A, int columns_B, double** A, double** B) {
    double** C = new double* [columns_B] {};
    for (int count = 0; count < columns_B; count++)
        C[count] = new double [rows_A] {};
    for (int i = 0;i < rows_A;i++) {
        for (int j = 0;j < columns_B;j++) {
            for (int k = 0;k < columns_A;k++) {
                C[j][i] += A[k][i] * B[j][k];
            }
        }
        cout << endl;
    }
    return C;
}

void conclusion_final_mass(int rows_A, int columns_B, double** C) {
    for (int i = 0;i < rows_A;i++) {
        for (int j = 0;j < columns_B;j++) {
            cout << C[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int columns_A, rows_A, columns_B, rows_B;

    columns_A = get_data_columns_mass('A');
    rows_A = get_data_rows_mass('A');
    double** A = create_mass(columns_A, rows_A);

    columns_B = get_data_columns_mass('B');
    rows_B = get_data_rows_mass('B');
    double** B = create_mass(columns_B, rows_B);


    double** C = create_final_mass(columns_A, rows_A, columns_B, A, B);
    conclusion_final_mass(rows_A, columns_B, C);
    
    for (int count = 0; count < columns_A; count++)
        delete[]A[count];
    for (int count = 0; count < columns_B; count++)
        delete[]B[count];
    for (int count = 0; count < columns_B; count++)
        delete[]C[count];

    return 0;
}