#include <iostream>

using namespace std;

int GlobalVar;

int main (){
        setlocale (LC_ALL, "Russian");
        int LocalVar;
        int* DynamicLocal = new int;

        cout << "����� ���������� ����������: " << &GlobalVar << endl;
        cout << "����� �������������� ����������: " << &LocalVar << endl;
        cout << "����� ������������  ����������: " << DynamicLocal << endl;

return 0;
}
