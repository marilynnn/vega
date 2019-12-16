#include <iostream>

using namespace std;

void PrintArr(int* arr, size_t arrSize){
    for (int i=0; i<arrSize; ++i){
        cout<<&arr[i]<<endl;
    }
}

void PrintArr2D(int** arr, size_t arrRows, size_t arrCols){
    for (int i=0; i<arrRows; ++i){
        for (int j=0; j<arrCols; ++j){
            cout<<&arr[i][j]<<endl;
        }
    }
}

int main() {
    setlocale (LC_ALL, "Russian");
    int size = 6;

    int StaticArr [size];
    int* a = StaticArr;
    cout<<"Адреса элементов статического одномерного массива: "<<endl;
    PrintArr(a,size);
    cout<<endl;


    int* DynamicArr = new int [size];
    cout<<"Адреса элементов динамического одномерного массива: "<<endl;
    PrintArr(DynamicArr,size);
    cout<<endl;

    int rows = 2;
    int cols = 3;

    int StaticArr2D [rows][cols];
    cout<<"Адреса элементов статического двумерного массива: "<<endl;
    for (int i=0; i<rows; ++i){
       PrintArr(StaticArr2D[i], cols);
    }
    cout<<endl;

    int **DynamicArr2D = new int * [rows];
    for (int i=0; i<rows; ++i){
        DynamicArr2D[i] = new int [cols];
    }
    cout<<"Адреса элементов динамического двумерного массива: "<<endl;
    PrintArr2D(DynamicArr2D, rows, cols);
    cout<<endl;

return 0;
}
