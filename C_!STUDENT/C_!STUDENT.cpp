#include <iostream>
#include <fstream>

class Student 
{
private:
    std::string name;
    int age;
    double avg_mark;

public:

    void set(std::string name, int age, double avg) 
    {
        this->name = name;
        this->age = age;
        this->avg_mark = avg;
    }

    void print() 
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Average mark: " << avg_mark << "\n";
    }

    void save(std::ofstream& data)
    {
        data << name << std::endl;
        data << age << std::endl;
        data << avg_mark << std::endl;
    }

    void load(std::ifstream& data)
    {
        data >> name;
        data >> age;
        data >> avg_mark;
    }
};

int main()
{
    Student student1;
    student1.set("Ross", 35, 11.9);

    std::ofstream file1("data.txt");
    student1.save(file1);
    file1.close();

    Student student2;

    std::ifstream file2("data.txt");
    student2.load(file2);
    file2.close();

    student2.print();
}