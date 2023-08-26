#include<iostream>

class beer
{
public:
    int x;
};
class derived : public beer
{
    int y;
};

int main()
{
    derived sampler;
    sampler.x = 10;
    std::cout<< sampler.x<< '\n';
    std::getchar();
    return 0;
}