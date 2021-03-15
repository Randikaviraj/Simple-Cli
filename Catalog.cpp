#include "Catalog.h"

void Catalog::add_course(Course course)
{
    bool class_found = false;
    for(Course c : courses)
    {
        if(c == course)
        {
            class_found = true;
            break;
        }
        if(!(c < course))
        {
            break;
        }
    }
    
    if(!class_found)
    {
        courses.push_back(course);
        std::sort(courses.begin(), courses.end());
    }
}

void Catalog::remove_course(Course course)
{
    for(auto it = courses.begin(); it < courses.end(); it++)
    {
        if(*it == course)
        {
            courses.erase(it);
            break;
        }
    }
}


std::vector<Course> Catalog::get_courses(){
    return courses;
}



void Catalog::change_instructor(Course course, std::string instructor)
{
    for(Course c : courses)
    {
        if(c == course)
        {
            c.set_instructor(instructor);
        }
    }
}

bool Catalog::add_student(Course course, int student_id)
{
    for(auto it = courses.begin(); it != courses.end(); it++)
    {
        if(*it == course)
        {
            it->add_student(student_id);
        }
    }
}

bool Catalog::remove_student(Course course, int student_id)
{
    for(auto it = courses.begin(); it != courses.end(); it++)
    {
        if(*it == course)
        {
            return it->remove_student(student_id);
        }
    }
}


