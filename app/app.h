#pragma once
#include <string>

namespace vsite::oop::v3 
{
	struct student
	{
		std::string name;
		int grade;
	};

	class results
	{
	public:
		results(const int length);
		~results() = default;
		void add(const student& new_student);
		unsigned int has_grade(const int grade) const;
		unsigned int starts_with_letter(const char letter) const;
	private:
		int start = 0;
		int length;
		student* results_arr;
	};

	class array
	{
	public:
		array() = default;
		array(const uint32_t size, const double value);
		array(const array& other);
		array(array&& other);
		~array() = default;
		double at(const uint32_t index) const;
		unsigned int size() const;
		void push_back(const double value);
	private:
		unsigned int size_ = 0;
		double* arr_ = nullptr;
	};

}