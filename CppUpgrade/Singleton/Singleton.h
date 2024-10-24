#pragma once
class Singleton
{
private:
	Singleton();
	~Singleton();
public:
	static void Init();
	static void Shutdown();
	static Singleton* GetInstance();
public:
	void PrintSomething();
};

