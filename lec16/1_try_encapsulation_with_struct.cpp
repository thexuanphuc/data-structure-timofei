#include<iostream>
#include<string>
struct Student
{
private:
    std::string name;
    std::string group;
    int age;
    double* memory;
public:
    Student(std::string name_, std::string group_, int age_)// constructor to initialize vulue for struct
    {
        name = name_;
        group = group_;
        age = age_;
        memory = new double[100];
    }
    Student()
    {
        name = "phuc";
        group = "lop 1";
        age = 18;
        memory = new double[100];
    }
    //this destructor is automatically runned after program is done, delete allocated memory used by struct!
    ~Student()// destructor, only 1 destructor, must not have parametr
    {
        std::cout<<"i am expeled from course!!!\n";
        delete [] memory;
    }
    void ageing()
    {
        std::cout<< "today is my birthday, im older yesterday!\n" ;
        age+=1;
        this->print();
    }
    void print() const
    {
        std::cout << "my name is "<< name <<" from "<< group <<" im " << age <<" years old!\n"; 
    }
};
int main()
{
    Student a;
    a.print();
    a.ageing();
    Student b {"ngu", "lop 2", 20};
    b.print();
    a.print();
    return 0;
}