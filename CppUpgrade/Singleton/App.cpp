#include "App.h"
#include <iostream>
#include <assert.h>

App* ISingleton<App>::instance = nullptr;

App::App()
{
	std::cout << "constructor" << std::endl;
}

App::~App()
{
	std::cout << "destructor" << std::endl;
}

void App::Init()
{
	assert(!ISingleton<App>::instance);
	ISingleton<App>::instance = new App();
}

void App::Shutdown()
{
	assert(ISingleton<App>::instance);
	delete ISingleton<App>::instance;
	ISingleton<App>::instance = nullptr;
}

void App::PrintSomething()
{
	std::cout << "print something" << std::endl;
}

App* App::GetInstance()
{
	assert(ISingleton<App>::instance);
	return ISingleton<App>::instance;
}
