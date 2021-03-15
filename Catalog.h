#include "Course.h"


class Catalog
{
    public:
        Catalog() {};
        void add_course(Course);
        void remove_course(Course);
        void change_instructor(Course, std::string);
        bool add_student(Course, int);
        bool remove_student(Course, int);
        std::vector<Course> get_courses();
    private:
        std::vector<Course> courses;
};

