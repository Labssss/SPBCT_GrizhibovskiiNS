// memory3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>
#define ONE_K (1024)
int main() {
	char* some_memory;
	int size_to_allocate = ONE_K;
	int megs_obtained = 0;
	int ks_obtained = 0;
	while (1) {
		for (ks_obtained = 0; ks_obtained < 1024; ks_obtained++) {
			some_memory = (char*)malloc(size_to_allocate);
			if (some_memory == NULL) exit(EXIT_FAILURE);
			sprintf(some_memory, "Hello World");
		}
		megs_obtained++;
		printf("Now allocated %d Megabytesn", megs_obtained);
	}
	exit(EXIT_SUCCESS);
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
