#include <iostream>
#include "Int.h"

int main()
{
	{
		Int* p = new Int();
		std::cout << "Int value: " << p->value << std::endl;
		std::cout << "Memory Used: " << qstx::total_memory << "Bytes" << std::endl;
		delete p;
	}
	std::cout << "Memory Used: " << qstx::total_memory << "Bytes" << std::endl;

	std::cout << std::endl;

	{
		Int* p_array = new Int[3];
		for (int i = 0; i < 3; ++i) {
			p_array[i].value = i;
			std::cout << "Int value: " << p_array[i].value << std::endl;
			std::cout << "Memory Used: " << qstx::total_memory << "Bytes" << std::endl;
		}
		delete[] p_array;
	}
	std::cout << "Memory Used: " << qstx::total_memory << "Bytes" << std::endl;
}