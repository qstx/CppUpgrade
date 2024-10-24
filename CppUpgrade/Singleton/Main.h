#pragma once
#include "Singleton.h"

//extern Singleton* s_instance;

int singleton_main()
{
	Singleton::Init();
	//s_instance = nullptr;
	Singleton::GetInstance()->PrintSomething();
	Singleton::Shutdown();
	return 0;
}