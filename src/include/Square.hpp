#pragma once
#include <string>

namespace chess
{

class Square
{
public:

    Square(int ix, int iy);
    Square(char cx, char cy);
    Square(const std::string & post);

    bool operator==(const Square & square ) const;

private:
    void setPosition(char cx, char cy);
    int x;
    int y;

};

}