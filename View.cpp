#include "View.h"

void View::show_menu()
{
    //what you see is what you get
    std::string menu = R"( 
===================================
Course Catlog
===================================
1. Add a Course
2. Remove a Course
3. View all Courses
4. View Courses by prefix
5. View Section of one course
6. Change an instructor
7. Add a student to a Course
8. Remove a student from a course
9. View students in a course
0. Exit


==================================
)";

	std::cout << menu; 
}

void View::view_all_courses()
{
    for(Course c : catalog.get_courses())
    {
        std::cout << c.get_course_prefix() << " " << c.get_course_number() << "-" << c.get_section_number() << std::endl;
    }
}





void View::view_all_courses_of_prefix(std::string prefix)
{
    for(Course c : catalog.get_courses())
    {
        if(c.get_course_prefix() == prefix)
        {
            std::cout << c.get_course_prefix() << " " << c.get_course_number() << "-" << c.get_section_number() << std::endl;
        }
    }
}


void View::view_all_sections_of_course(std::string prefix, int number)
{
    for(Course c : catalog.get_courses())
    {
        if(c.get_course_prefix() == prefix && c.get_course_number() == number)
        {
            std::cout << c.get_course_prefix() << " " << c.get_course_number() << "-" << c.get_section_number() << std::endl;
        }
    }
}



void View::view_students_in_course(Course course)
{
    for(Course c : catalog.get_courses())
    {   
        if(c == course)
        {
            std::cout << c << std::endl;
        }
    }
}


void View::prompt_for_input(std::string question)
{
    std::cout << "Please enter " << question << std::endl;
}

void View::show_message(std::string message){
    std::cout << message<< std::endl;
}