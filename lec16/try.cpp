#include <iostream>
#include <string>
#include <vector>

struct car
{
    std::string name;
    int wheel;
    car(std::string name_, int wheel_)
        : name(name_), wheel(wheel_) {}

    car() : name("this is new list"), wheel(0) {}
};

class My_colection : private car
{
private:
    std::vector<car> list_of_my_car;

public:
    using car::car; // Inherit constructors

    void operator+=(car CAR_)
    {
        list_of_my_car.push_back(CAR_);
    }

    void add_car(car CAR_)
    {
        operator+=(CAR_);
    }

    std::vector<car>::iterator begin()
    {
        return list_of_my_car.begin();
    }

    std::vector<car>::iterator end()
    {
        return list_of_my_car.end();
    }
};

void operator<<(std::ostream &COUT, const car &CAR)
{
    COUT << "name : " << CAR.name << " number of wheels: " << CAR.wheel << '\n';
}

int main()
{
    car car1{"phuc", 4};
    car car2{"xuan", 6};
    car car3{"nguyen", 10};
    
    My_colection my_collect;
    my_collect.add_car(car1);
    my_collect.add_car(car2);
    my_collect.add_car(car3);
    my_collect.add_car({});


    for (auto p = my_collect.begin(); p != my_collect.end(); p++)
    {
        operator<<(std::cout, *p);
        std::cout << '\n';
    }

    return 0;
}
