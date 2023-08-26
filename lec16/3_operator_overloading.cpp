#include<iostream>
#include<string>
#include<vector>
struct My_colection;
struct car// by deafault struct is public, class is private(used for inheritence)
{
    std::string name;
    int wheel;
    car(std::string name_, int wheel_){
        this->name = name_;
        wheel = wheel_;
    }
    car(My_colection& my_collection_ptr);
};

struct My_colection: private car
{
private:
    std::vector<car> list_of_my_car;
public:
    using car::car;
    void operator+=(car CAR_)
    {
        this->list_of_my_car.push_back(CAR_);
    }
    void add_car(car CAR_)
    {
        operator+=(CAR_);
    }
    std::vector<car>::iterator begin(){
        return list_of_my_car.begin();
    };
    std::vector<car>::iterator end(){
        return list_of_my_car.end();
    };
};
void operator<<(std::ostream& COUT,const car& CAR)
{
    COUT << "name : " << CAR.name<<" number of wheels: "<< CAR.wheel << '\n';
}
//dehault initialize struct outside
car::car(My_colection& my_collection_ptr){
    this->name = "this is new list";
    this->wheel = 0;
    if(&my_collection_ptr){
        my_collection_ptr.add_car(*this);
    }
}
int main()
{
    car car1 {"phuc", 4};
    car car2 {"xuan", 6};
    car car3 {"nguyen", 10};
    My_colection my_collect(&my_collect);
    my_collect.add_car(car1);
    my_collect.add_car(car2);
    my_collect.add_car(car3);
    for(auto  p = my_collect.begin(); p != my_collect.end(); p++){
        operator<<(std::cout,*p);
        std::cout<< '\n';
    }
    return 0;
}