#include "Catalog.h"

class View{
    public:
        View(Catalog& c):catalog(c){}
        void show_menu();
        void view_all_courses();
        void view_all_courses_of_prefix(std::string prefix);
        void view_all_sections_of_course(std::string prefix, int number);
        void view_students_in_course(Course course);
        void prompt_for_input(std::string question);
        void show_message(std::string message);

    private:
        Catalog& catalog;

};


