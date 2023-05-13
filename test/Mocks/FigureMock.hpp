#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Figure.hpp"

using namespace chess;

class FigureMock : public Figure
{   
public:

    FigureMock(const Color & color, const std::shared_ptr<std::pair<int, int>> & pos):
    Figure::Figure(color, Type::KING, pos){}

    MOCK_METHOD((std::vector<std::shared_ptr<std::pair<int,int>>>),   getPossibleMovements,   
    (const std::vector<std::shared_ptr<Figure>> &),  (override)  );

    MOCK_METHOD(std::shared_ptr<Figure>,                            clone,                  
    (),                                                             (const, override)  );

    MOCK_METHOD(void,                                               updatePosition,         
    (int,int)                                                                  );

    MOCK_METHOD((const std::shared_ptr<const std::pair<int, int>>),   getPosition,            
    (),                                                             (const)     );

    MOCK_METHOD(Type,                                               getType,                
    (),                                                             (const)     );
    
    MOCK_METHOD(Color,                                              getColor,               
    (),                                                             (const)     );
};