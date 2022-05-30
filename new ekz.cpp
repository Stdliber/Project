#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

void ex(char** mas, int& str, int& stolb)
{
        for (int i = 0; i < str; i++) {
            for (int j = 0; j < stolb; j++) {
                mas[i][j] = 88;           // вводим двумерный дин.массив из символов Х, соответствующий количеству строк и столбцов.
            }
        }
}

void simb(char** mas1, int &str, int &stolb, int &size1)
{
    char simb = 1;
    int num = 1;
    bool up = true;
    for (int i = 0; i < str; i++)
    {
       for (int j = 0; j < stolb; j++) {  //второй половине значений массива присваиваем значения из первой половины массива.
            if (simb == 6) simb = 14;
            if (num > (size1 / 2) && up == true) {
                simb = 1;
                up = false;
            }
            mas1[i][j] = simb;   
            simb++;
            num++;
       }
    }
}

void show(char** arr, int &str, int &stolb)
{
    cout << setiosflags(ios::left);
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
           cout << setw(5) << arr[i][j];           // выводим двумерный дин.массив из символов, соответствующий количеству строк и столбцов на экран.
        }
        cout << endl;
    }
}

void svvap(char** arr1, int &str, int &stolb)
{
    srand(time(NULL));
            for (int i = 0; i < str; i++) {
            
                for (int j = 0; j < stolb; j++) {
                swap(arr1[i][j], arr1[rand() % str][rand() % stolb]);   // перемешиваем массив
                }
            }
}

void replace1(char** arr2, char** arr3, int& S1, int& s1, int& str, int& stolb, char& A, int& CARD) // функция, которая меняет символ Х на другой символ в двух клетках.
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < stolb; j++) {
            if (i == S1 && j == s1) {
                swap(arr2[S1][s1], arr3[i][j]);
                A = arr2[S1][s1];
                CARD++;
            }
            else continue;
        }
    }
}

void replace2(char** arr2, char** arr3, int& S2, int& s2, int& str, int& stolb, char& B, int& CARD)
{
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < stolb; j++) {
            if (i == S2 && j == s2) {
                swap(arr2[S2][s2], arr3[i][j]);
                B = arr2[S2][s2];
                CARD++;
            }
            else continue;
        }
    }
}

void compare(char& I, char& J, char** arr2, char** arr3, int& S1, int& S2, int& s1, int& s2) // функция, которая сравнивает значения массива
{
    if (I == J)
    {
        Beep(247, 500);
        arr2[S1][s1] = 32; // выдаёт ошибку, когда присваиваешь элементу массива значение " ".
        arr2[S2][s2] = 32;
    }
    else
    {
        Beep(440, 500);
        swap(arr2[S1][s1], arr3[S1][s1]);
        swap(arr2[S2][s2], arr3[S2][s2]);
    }
}

void ending (/*bool& temp*/int N,char** arr2, int& str, int& stolb, int& sizee)
{
    /*int N = 0;*/
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            if (arr2[i][j] == 32) ++N; // если N = stolb*str => return o; Записать в main.
       }
    } /*if (N == sizee) temp = true;*/
}

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    float time;
    int pole, x = 0, y = 0, g1 = 0, G1 = 0, G2 = 0, g2 = 0, card = 0, size = 0, K = 0;
    char C = 0, D = 0;
  /*  bool temp1 = false;*/

    cout << "Выберите размерность поля \n" << "1 - 3х2, 2 - 4х3, 3 - 6х4" << endl;
    cin >> pole;

    switch (pole) {
    case 1: x = 3;
            y = 2;
            size = 6;
            cout << "Вы выбрали поле 3х2";
            break;
    case 2: x = 4;
            y = 3;
            size = 12;
            cout << "Вы выбрали поле 4х3";
            break;
    case 3: x = 6;
            y = 4;
            size = 24;
            cout << "Вы выбрали поле 6х4";
            break;
    }
    Sleep(1000);
    system("cls");

    char** array = new char* [x];
    for (int i = 0; i < x; i++) {
        array[i] = new char[y];
    }
    char** array1 = new char* [x];
    for (int i = 0; i < x; i++) {
        array1[i] = new char[y];
    }

    ex(array, y, x);
    simb(array1, y, x, size);
    svvap(array1, y, x);
    show(array, y, x);
    cout << endl;
    
    while (/*!temp1*/K < size) {
        cout << "Введите координаты клетки, которую хотите перевернуть (сначала введите номер столбца, затем номер строки)" << endl;
        cin >> G1 >> g1;
        G1 = G1 - 1;
        g1 = g1 - 1;
        system("cls");
        replace1(array, array1, G1, g1, y, x, C, card);
        show(array, y, x);
        cout << "Введите координаты клетки, с которой хотите сравнить уже выбранную клетку (сначала введите номер столбца, затем номер строки)" << endl;
        cin >> G2 >> g2;
        G2 = G2 - 1;
        g2 = g2 - 1;
        system("cls");
        replace2(array, array1, G2, g2, y, x, D, card);
        show(array, y, x);
        compare(C, D, array, array1, G1, G2, g1, g2);
        ending(/*temp1*/K, array, y, x, size);
        system("cls");
        show(array, y, x);
    }

        time = clock();
        cout << time / CLOCKS_PER_SEC << " сек. затрачено на игру \n";
        cout << "Количество переворотов карт = " << card << endl; //в мэйне посчитать выполнение функций;
        system("pause");

    return 0;
}

