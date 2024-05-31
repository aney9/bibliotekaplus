#include <iostream>
#include <windows.h>
#include "trash.h"
#include <Windows.h>
#include <string>
#pragma execution_character_set("utf-8")
using namespace std;

bool Poisk(const char* stroka, const char* symbols);

int main() {
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF-8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF-8
    string stroka;
    cout << "Введите что-то: ";
    getline(cin, stroka);

    string symbols;
    cout << "Введите символы для нахождения: ";
    getline(cin, symbols);


    HMODULE hDll = LoadLibrary(L"gg.dll");
    if (!hDll) {
        cout << "Ошыбка загрузки DLL" << endl;
        return 1;
    }

    
    FARPROC poisk = GetProcAddress(hDll, "Poisk");
    if (!poisk) {
        cout << "Ошыбка получения адреса функции" << endl;
        FreeLibrary(hDll);
        return 1;
    }


    bool result = ((bool (*)(const char*, const char*))poisk)(stroka.c_str(), symbols.c_str());


    FreeLibrary(hDll);


    if (result) {
        cout << "Символы: " << symbols << " найдены в строке: " << stroka << " TRUUUUUUUUUUUUUEEEEE ИУУУУУУУУУУУ" << endl;
    }
    else {
        cout << "анлак, не то" << endl;
    }

    return 0;
}
