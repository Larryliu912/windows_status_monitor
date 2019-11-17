#ifndef SPEED_H
#define SPEED_H
#include "info.h"

class Speed: public Info
{
public:
    Speed();
    void updateInfo();
    void getDevs();
    ~Speed();
};

#endif // SPEED_H
