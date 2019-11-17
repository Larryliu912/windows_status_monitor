#ifndef INFO_H
#define INFO_H
#include<string>

class Info
{
public:
    Info();
    virtual void updateInfo() = 0;
    virtual ~Info() = 0;
private:
    std::string name;
    std::string info;
};

#endif // INFO_H
