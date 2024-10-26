#pragma once
#include "Singleton.h"

//extern Singleton* s_instance;

void Singleton_Main()
{
	Singleton::Init();
	//s_instance = nullptr;
	Singleton::GetInstance()->PrintSomething();
	Singleton::Shutdown();
}

#include "App.h"

void Singleton_Main1()
{
	App::Init();
	App::GetInstance()->PrintSomething();
	App::Shutdown();
}