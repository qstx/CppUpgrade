#pragma once
#include "Singleton.h"
class App:ISingleton<App>
{
private:
	App();
	~App();
public:
	void PrintSomething();
	static void Init();
	static void Shutdown();
	static App* GetInstance();
};
