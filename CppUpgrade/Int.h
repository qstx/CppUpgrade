#pragma once
#include "Allocator.h"

class Int {
public:
	DEFINE_CLASS_MEMORY_ALLOCATOR(Int)
		int value;
	Int() :value(0) {}
	Int(int i) :value(i) {}
};