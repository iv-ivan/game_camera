//
//  classes.h
//  ProtestGame
//
//  Created by Ivan Ivashkovskii on 06/04/2020.
//  Copyright © 2020 Ivan Ivashkovskii. All rights reserved.
//

#ifndef classes_h
#define classes_h

#include <vector>

struct TCoordinate {
    size_t X;
    size_t Y;
};

struct TConsoleShape {
    std::vector<std::vector<char>> Shape;
    TCoordinate Position;
};

class TObject {
public:
    virtual TConsoleShape GetConsoleShape(const size_t resolution) const = 0;
};

class TBuilding : public TObject {
public:
    TConsoleShape GetConsoleShape(const size_t resolution) const override {
        TConsoleShape shape;
        shape.Position = {1, 2};
        shape.Shape = {{'@', '@', '@', '@'}, {'@', 'x', 'x', '@'}, {'@', '@', '@', '@'}};
        return shape;
    }
};

class TMovingObject : public TObject {
    
};

class THuman : public TMovingObject {
    
};

class TPlayer : public THuman {
    
};

class TPoliceman : public TMovingObject {
    
};

class TAutozak : public TMovingObject {
};

#endif /* classes_h */
