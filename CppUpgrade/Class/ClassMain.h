#pragma once

#include <iostream>
#include "Int.h"
#include "String.h"

void Class_Main()
{
	//Èý·¨Ôò
	{
		qstx::String s1("string1");
		std::cout << "String value: " << s1.str << " String length: " << s1.Length() << " String capacity: " << s1.capacity << std::endl;

		qstx::String s2(s1);
		s2.str[0] = '2';
		std::cout << "String value: " << s2.str << " String length: " << s2.Length() << " String capacity: " << s2.capacity << std::endl;

		qstx::String s3(s2);
		std::cout << "String value: " << s3.str << " String length: " << s3.Length() << " String capacity: " << s3.capacity << std::endl;

		qstx::String s4 = s1;
		std::cout << "String value: " << s4.str << " String length: " << s4.Length() << " String capacity: " << s4.capacity << std::endl;

		qstx::String s5("str5");
		s5 = s1;
		std::cout << "String value: " << s5.str << " String length: " << s5.Length() << " String capacity: " << s5.capacity << std::endl;
	}

	{
		qstx::String s6 = std::move(qstx::String("str6"));
		std::cout << "String value: " << s6.str << " String length: " << s6.Length() << " String capacity: " << s6.capacity << std::endl;
		s6.Reserve(9);
		std::cout << "String value: " << s6.str << " String length: " << s6.Length() << " String capacity: " << s6.capacity << std::endl;
	}

	{
		qstx::String s7("");
		s7 = std::move(qstx::String("str7"));
		std::cout << "String value: " << s7.str << " String length: " << s7.Length() << " String capacity: " << s7.capacity << std::endl;
	}
}