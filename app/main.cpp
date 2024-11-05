#include <iostream>

#include "app.h"
using namespace vsite::oop::v3;

// read number of results
// read all student data
// read grade and output grade statistics
// read letter and output letter statistics
int main()
{
	int num_of_results;

	std::cout << "Enter number of students: ";
	std::cin >> num_of_results;

	results student_results(num_of_results);

	student current_student;
	for (int i = 0; i < num_of_results; i++) {
		std::cout << "Enter student " << i + 1 << " name and grade: ";
		std::cin >> current_student.name >> current_student.grade;
		student_results.add(current_student);
	}

	int grade_to_find;
	char letter_to_find;

	std::cout << "Enter grade you want statistics for: ";
	std::cin >> grade_to_find;

	std::cout << "Enter letter you want statistics for: ";
	std::cin >> letter_to_find;

	int num_of_grades = student_results.has_grade(grade_to_find);
	int num_of_letters = student_results.starts_with_letter(letter_to_find);

	std::cout << "Number of grades -> " << grade_to_find << " in student results is -> " << num_of_grades << std::endl;
	std::cout << "Number of letters -> " << letter_to_find << " as first letter in student name is -> " << num_of_letters << std::endl;

}
