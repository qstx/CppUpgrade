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

template <typename T>
class ISingleton
{
private:
	static T* instance;
public:
	static T* GetInstance()
	{
		return instance;
	}
	friend T;
};

