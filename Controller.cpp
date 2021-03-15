#include "Controller.h"

Controller::~Controller()
{
}


void Controller::start_cli(){
    int cmd = -1;
    while(cmd != 0) //while loop that runs till the user puts in a 0
    {
        view.show_menu(); //show user options available
        view.prompt_for_input("selection.?");
        std::cin >> cmd;
        execute_cmd(cmd);
    }
}


void Controller::execute_cmd(int cmd)
{
    switch(cmd) //switch to decide what function to call based on user input
    {
        case 1: //add course
            courseController(0);
            break;
        case 2:
            courseController(1);//remove course
            break;
        case 3:
            view.view_all_courses();//view all courses
            break;
        case 4:
            viewCoursesByPrefix(); //View courses on prefix
            break;
        case 5:
            viewSectionsOfCourse();//view all sections of course
            break;
        case 6:
            changeInstructor(); //change instructor
            break;
        case 7:
            courseController(2);// add new student id
            break;
        case 8:
            courseController(3);//remove student id
            break;    
        case 9:
            courseController(4); //view students of course
            break;    
        case 0:
            return;
        default:
            view.show_message("Please enter a correct command !");
            break;     
    }
}


void Controller::courseController(int selection){ //add or remove the course base on selection
    std::string course_prefix;
    int course_number;
    int section_number;
    std::string name;
    std::string instructor;
    int student_id;

    view.prompt_for_input("course prefix :");
    std::cin>>course_prefix;

    view.prompt_for_input("course number :");
    std::cin>>course_number;

    view.prompt_for_input("section number :");
    std::cin>>section_number;

    view.prompt_for_input("name :");
    std::cin>>name;

    view.prompt_for_input("instructor :");
    std::cin>>instructor;

    switch (selection)
    {
    case 0: //add course
        catalog.add_course(Course(course_prefix,course_number,section_number,name,instructor));
        view.show_message("Done !");
        break;
    case 1: // remove course
        catalog.remove_course(Course(course_prefix,course_number,section_number,name,instructor));
        view.show_message("Done !");
        break;
    case 2://add new student id
        
        view.prompt_for_input("student id :");
        std::cin>>student_id;
        if (catalog.add_student(Course(course_prefix,course_number,section_number,name,instructor),student_id))
        {
            view.show_message("Done !");
        }else{
            view.show_message("Student already enrolled in course!");
        }
        
        break;
    case 3://remove student id 
        
        view.prompt_for_input("student id :");
        std::cin>>student_id;
        if (catalog.remove_student(Course(course_prefix,course_number,section_number,name,instructor),student_id))
        {
            view.show_message("Done !");
        }else{
            view.show_message("Student was not enrolled !");
        }
        break;
    case 4:
        view.view_students_in_course(Course(course_prefix,course_number,section_number,name,instructor));

    }

}


void Controller::viewCoursesByPrefix(){//View courses on prefix
    std::string course_prefix;

    view.prompt_for_input("course prefix :");
    std::cin>>course_prefix;

    view.view_all_courses_of_prefix(course_prefix);
}



void  Controller::viewSectionsOfCourse(){ //view all sections of course
    std::string course_prefix;
    int course_number;

    view.prompt_for_input("course prefix :");
    std::cin>>course_prefix;

    view.prompt_for_input("course number :");
    std::cin>>course_number;

    view.view_all_sections_of_course(course_prefix, course_number);
}



void  Controller::changeInstructor(){
    std::string course_prefix;
    int course_number;
    int section_number;
    std::string name;
    std::string instructor;
    std::string new_instructor;

    view.prompt_for_input("course prefix :");
    std::cin>>course_prefix;

    view.prompt_for_input("course number :");
    std::cin>>course_number;

    view.prompt_for_input("section number :");
    std::cin>>section_number;

    view.prompt_for_input("name :");
    std::cin>>name;

    view.prompt_for_input("previous instructor :");
    std::cin>>instructor;

    view.prompt_for_input("new instructor :");
    std::cin>>new_instructor;

    catalog.change_instructor(Course(course_prefix,course_number,section_number,name,instructor),new_instructor);

}