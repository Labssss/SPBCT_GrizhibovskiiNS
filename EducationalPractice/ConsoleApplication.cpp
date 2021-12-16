// ConsoleApplication.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include "DLL.h" // подключение созданной DLL-библиотеки
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#pragma warning(disable : 4996)
using namespace std;

int main(int argc, TCHAR* argv[])
{
    setlocale(LC_CTYPE, "rus");
    Vector<char> v;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    cout << "Грижибовский Н.С. г.503 " << ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1900 + ltm->tm_year << " ";
    cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "\n\n";

    cout << "Создание дочернего процесса...\n";
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    // Start the child process. 
    TCHAR szCmdline[] = TEXT(".//ChildProcess.exe");
    if (!CreateProcess(NULL,   // No module name (use command line)
        szCmdline,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);


    string line;
    string vectrors[10];
    ifstream in(".\\text.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << "\nПолучена строка длиной " << line.length() << " символов:\n" << line << "\n";
        }
    }
    cout << "\n";

    in.close();// закрываем файл

    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = k; j < k + 10; j++)
        {
            vectrors[i] += line[j];
        }
        sort(vectrors[i].begin(), vectrors[i].end()); // сортировка вектора
        vectrors[i][i] = '*'; // замена символа по диагонали
        k += 10;
    }


    for (int i = 0; i < 10; i++)
    {
        cout << vectrors[i] << endl;
    }
    // Анонимный канал
    
    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    system("pause");

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
