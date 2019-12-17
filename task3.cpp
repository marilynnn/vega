#include <iostream>

using namespace std;

typedef struct {
    char name [21];
    int age;
    char region [30];
    double result;
    bool WinnerOrNot;

}Participant;

typedef struct {
    double result;
    int age;
    bool WinnerOrNot;
    char region [30];
    char name [21];

}Participant_2;

#pragma pack(push,1)
typedef struct {
    char name [21];
    int age;
    char region [30];
    double result;
    bool WinnerOrNot;

}Participant_3;
#pragma pack(pop)


int main()
{   setlocale (LC_ALL, "Russian");

    Participant Ivan;
    size_t IvanSize = sizeof(Ivan.name)+sizeof(Ivan.age)+sizeof(Ivan.region)+sizeof(Ivan.result)+sizeof(Ivan.WinnerOrNot);
    cout<<"������ �������� ���������: "<<endl;

    cout<< &Ivan.name<< endl
    << &Ivan.age<< endl
    << &Ivan.region<< endl
    << &Ivan.result<< endl
    << &Ivan.WinnerOrNot<< endl;
    cout<<"����� �������� �������� ���������: "<< IvanSize<<endl;
    cout<<"������ ���������: "<<sizeof(Ivan)<<endl;

    Participant_2 Alexey;
    size_t AlexeySize = sizeof(Alexey.name)+sizeof(Alexey.age)+sizeof(Alexey.region)+sizeof(Alexey.result)+sizeof(Alexey.WinnerOrNot);

    cout<<"������ �������� ���������: "<<endl;
    cout << &Alexey.result<< endl
    << &Alexey.WinnerOrNot<< endl
    << &Alexey.region<< endl
    << &Alexey.age<< endl
    << &Alexey.name<< endl;
    cout<<"����� �������� �������� ���������: "<< AlexeySize<<endl;
    cout<<"������ ���������: "<<sizeof(Alexey)<<endl;

    Participant_3 Maria;
    size_t MariaSize = sizeof(Maria.name)+sizeof(Maria.age)+sizeof(Maria.region)+sizeof(Maria.result)+sizeof(Maria.WinnerOrNot);

    cout<<"������ �������� ���������: "<<endl;
    cout<< &Maria.name<< endl
    << &Maria.age<< endl
    << &Maria.region<< endl
    << &Maria.result<< endl
    << &Maria.WinnerOrNot<< endl;
    cout<<"����� �������� �������� ���������: "<< MariaSize<< endl;
    cout<<"������ ���������: "<<sizeof(Maria)<<endl;

return 0;
}
