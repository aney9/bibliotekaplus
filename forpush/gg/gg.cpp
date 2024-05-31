#include "Header.h"
#include <corecrt_memory.h>

extern "C" __declspec(dllexport)bool Poisk(const char* stroka, const char* symbols) {
    for (int i = 0; symbols[i] != '\0'; ++i) {
        if (strchr(stroka, symbols[i]) == NULL) {
            return false;
        }
    }

    return true;
}