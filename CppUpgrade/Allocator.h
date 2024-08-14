#pragma once
#include <memory>
#include <atomic>

namespace qstx {
	static std::atomic<size_t> total_memory = 0;
	struct header
	{
		size_t size = 0;
		const char* type = nullptr;
	};
	void* m_malloc(size_t size, const char* type) {
		void* header_ptr = malloc(sizeof(header) + size);
		header* tmp_header = static_cast<header*>(header_ptr);
		tmp_header->size = size;
		tmp_header->type = type;
		total_memory += size;
		return (unsigned char*)header_ptr + sizeof(header);
	}
	void m_free(void* ptr) {
		void* header_ptr = (unsigned char*)ptr - sizeof(header);
		total_memory -= static_cast<header*>(header_ptr)->size;
		free(header_ptr);
	}
#define	DEFINE_CLASS_MEMORY_ALLOCATOR(type)               \
	static void* operator new(size_t size) {              \
		return qstx::m_malloc(size, typeid(type).name()); \
	}                                                     \
	static void* operator new[](size_t size) {            \
		return qstx::m_malloc(size, typeid(type).name()); \
	}                                                     \
	static void operator delete(void* ptr) {              \
		qstx::m_free(ptr);                                \
	}                                                     \
	static void operator delete[](void* ptr) {            \
		qstx::m_free(ptr);                                \
	}
}