typedef struct Student{
    char name[20];
    int Age;
    int ID;
    char phone[12];

}std_info;



void add_Student(std_info *s);
void find_StudentbyID(std_info *s);
void delete_StudentbyID(std_info *s);
void Edit_Student(std_info *s);
void print_School(std_info *s);
void total_Student();
void call_Student(std_info *s);


