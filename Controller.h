#include "View.h"


class Controller
{
    private:
        View& view;
        Catalog& catalog;
        void execute_cmd(int cmd);
        void courseController(int selection);
        void viewCoursesByPrefix();
        void viewSectionsOfCourse();
        void changeInstructor();
        void viewStudentsInCourse();

    public:
        Controller(View& v,Catalog& c) : view(v),catalog(c){};
        ~Controller();
        void start_cli();
        
};



