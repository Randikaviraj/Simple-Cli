#include <iostream>
#include <vector>
#include <algorithm>

class Course {
    public:
        Course();
        Course(std::string, int, int, std::string, std::string);
        //Course(std::string cp = "", int cn = 0, int sn = 0, std::string n = ""; std::string i = "");
        std::string get_course_prefix();
        int get_course_number();
        int get_section_number();
        std::string get_name();
        std::string get_instructor();
        std::vector<int> get_student_ids();
        void set_course_prefix(std::string);
        void set_course_number(int);
        void set_section_number(int);
        void set_name(std::string);
        void set_instructor(std::string);
        bool add_student(int);
        bool remove_student(int);
        std::string to_string();
        friend std::ostream& operator<<(std::ostream&, const Course&);
        bool operator<(const Course& rhs) const;
        bool operator==(const Course& rhs) const;
    private:
        std::string course_prefix;
        int course_number;
        int section_number;
        std::string name;
        std::string instructor;
        std::vector<int> student_ids;
};

