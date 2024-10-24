#pragma once
#include <iostream>
#include <assert.h>

namespace qstx
{
	class String
	{
	public:
		String(const char* cstr)
		{
			std::size_t n = strlen(cstr) + 1;
			Reserve(n);
			memcpy(str, cstr, n);
		}
		String(const String& other)
		{
			DeepCopy(other);
		}
		String& operator=(const String& other)
		{
			if (this != &other)
				DeepCopy(other);
			return *this;
		}
		String(String&& other) noexcept :str(std::exchange(other.str,nullptr))
		{
			capacity = strlen(str) + 1;
		}
		String& operator=(String&& other) noexcept
		{
			std::swap(other.str, str);
			capacity = strlen(str) + 1;
			return *this;
		}
		~String()
		{
			if (str)
				delete[] str;
		}
		bool IsNullOrEmpty()
		{
			return !str || !Length();
		}
		inline std::size_t Length()
		{
			return strlen(str);
		}
		//只扩容，不减容
		void Reserve(std::size_t capacity)
		{
			if (this->capacity < capacity)
			{
				char* old_str = str;
				str = new char[capacity];
				this->capacity = capacity;
				if (old_str)
				{
					memcpy(str, old_str, strlen(old_str) + 1);
					delete[] old_str;
				}
			}
		}
		void DeepCopy(const String& other)
		{
			if (other.str)
			{
				std::size_t n = strlen(other.str) + 1;
				Reserve(n);
				memcpy(str, other.str, n);
			}
			else
			{
				if (str)
					delete[] str;
				str = nullptr;
				capacity = 0;
			}
		}
	public:
		char* str = nullptr;//存放字符串的数据
		std::size_t capacity = 0;//str数组的真实长度，计入'\0'
	};
}