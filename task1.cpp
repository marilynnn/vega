#include <iostream>

using namespace std;

int GlobalVar;

int main (){
        setlocale (LC_ALL, "Russian");
        int LocalVar;
        int* DynamicLocal = new int;

        cout << "Адрес глобальной переменной: " << &GlobalVar << endl;
        cout << "Адрес автоматической переменной: " << &LocalVar << endl;
        cout << "Адрес динамической  переменной: " << DynamicLocal << endl;

return 0;
}
