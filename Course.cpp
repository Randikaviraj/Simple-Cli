#include "Course.h"

Course::Course()
{
    course_prefix = "";
    course_number = 0;
    section_number = 0;
    name = "";
    instructor = "";
}

Course::Course(std::string cp, int cn, int sn, std::string n, std::string i)
{
    course_prefix = cp;
    course_number = cn;
    section_number = sn;
    name = n;
    instructor = i;
}

std::string Course::get_course_prefix()
{
    return course_prefix;
}

int Course::get_course_number()
{
    return course_number;
}

int Course::get_section_number()
{
    return section_number;
}

std::string Course::get_name()
{
    return name;
}

std::string Course::get_instructor()
{
    return instructor;
}

std::vector<int> Course::get_student_ids()
{
    return student_ids;
}

void Course::set_course_prefix(std::string cp)
{
    course_prefix = cp;
}

void Course::set_course_number(int cn)
{   
    course_number = cn;
}

void Course::set_section_number(int sn)
{
    section_number = sn;
}

void Course::set_name(std::string n)
{
    name = n;
}

void Course::set_instructor(std::string i)
{
    instructor = i;
}

bool Course::add_student(int id)
{
    for(int i : student_ids)
    {
        if(i == id)
        {

            return false;
        }
    }
    student_ids.push_back(id);
    std::sort(student_ids.begin(), student_ids.end()); 
    return true;
}

bool Course::remove_student(int id)
{
    for(auto it = student_ids.begin(); it != student_ids.end(); it++)
    {
        if(id == *it)
        {
            student_ids.erase(it);
            return true;
        }
    }

    return false;
}

std::string Course::to_string()
{
    std::string return_string =  course_prefix + "," + std::to_string(course_number) + "," + std::to_string(section_number) + "," + name + "," + instructor;
    for(int id : student_ids)
    {
        return_string += "," + std::to_string(id);
    }
    return return_string;
}

std::ostream& operator<<(std::ostream& ost, const Course& course)
{
    ost << course.course_prefix << " " << course.course_number << " - " << course.section_number << std::endl;
    ost << course.name << std::endl;
    ost << "Instructor: " << course.instructor << std::endl;
    ost << "Number of Students Enrolled: " << course.student_ids.size() << std::endl;
    if(course.student_ids.size() > 0)
    {
        ost << "Students enrolled: " << std::endl;
        for(int i : course.student_ids)
        {
            ost << i << std::endl;
        }
    }   
    return ost; 
}

bool Course::operator<(const Course& rhs) const
{
    // CSE < PHYS
    if(course_prefix < rhs.course_prefix)
        return true;
    // PHYS < CSE
    else if(course_prefix > rhs.course_prefix)
        return false;
    //CSE < CSE -> go to CN
    //1310 < 1320
    else if(course_number < rhs.course_number)
        return true;
    //1320 < 1310
    else if(course_number > rhs.course_number)
        return false;
    //1310 == 1310 -> to go section number
    //001 < 002
    else if(section_number < rhs.section_number)
        return true;    
    //002 < 001 and 001 == 001
    return false;
}

bool Course::operator==(const Course& rhs) const
{
    if(course_prefix == rhs.course_prefix && course_number == rhs.course_number && section_number == rhs.section_number)
        return true;
    else
        return false;    
}

