#include "Singleton.h"
#include <iostream>
#include <assert.h>

static Singleton* s_instance = nullptr;

Singleton::Singleton()
{
	std::cout << "constructor" << std::endl;
}

Singleton::~Singleton()
{
	std::cout << "destructor" << std::endl;
}

void Singleton::Init()
{
	assert(!s_instance);
	s_instance = new Singleton();
}

void Singleton::Shutdown()
{
	assert(s_instance);
	delete s_instance;
	s_instance = nullptr;
}

Singleton* Singleton::GetInstance()
{
	assert(s_instance);
	return s_instance;
}

void Singleton::PrintSomething()
{
	std::cout << "print something" << std::endl;
}
