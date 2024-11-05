#include "app.h"
#include <algorithm>

namespace vsite::oop::v3
{
	results::results(const int length): length(length), results_arr(new student[length])
	{}

	results::~results() {
		delete[] results_arr;
	}

	void results::add(const student& new_student)
	{
		results_arr[start++] = new_student;
	}

	unsigned int results::has_grade(const int grade) const
	{
		unsigned int count = 0;
		for (int i = 0; i < length; ++i)
		{
			if (results_arr[i].grade == grade) {
				count++;
			}
		}
		return count;
	}

	unsigned int results::starts_with_letter(const char letter) const
	{
		unsigned int count = 0;
		for (int i = 0; i < length; ++i)
		{
			if (std::tolower(results_arr[i].name[0]) == std::tolower(letter)) {
				count++;
			}
		}
		return count;
	}
	//--------------------------------------------------------------------------------------------
	array::array(const uint32_t size, const double value): size_(size), arr_(new double[size])
	{
		for (uint32_t i=0; i<size; ++i)
		{
			arr_[i] = value;
		}
	}

	array::array(const array& other): size_(other.size_), arr_(new double[other.size_])
	{
		for (int i = 0; i < other.size_; i++) {
			arr_[i] = other.arr_[i];
		}
	}

	array::array(array&& other) : size_(other.size_), arr_(other.arr_)
	{
		other.size_ = 0;
		other.arr_ = nullptr;
	}

	array::~array() {
		delete[] arr_;
	}

	double array::at(const uint32_t index) const
	{
		if (index < 0 || index >= size_)
		{
			return 0.;
		}
		return arr_[index];
	}

	unsigned int array::size() const
	{
		return size_;
	}

	void array::push_back(const double value)
	{
		size_++;

		double* new_arr = new double[size_];
		for (unsigned int i = 0; i < size_ - 1; ++i)
		{
			new_arr[i] = arr_[i];
		}

		delete[] arr_;

		new_arr[size_ - 1] = value;

		arr_ = new_arr;
	}
	
}