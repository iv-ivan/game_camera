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
#include <cmath>

struct TCoordinate {
    size_t X;
    size_t Y;
};

struct TRectangle {
    size_t X;
    size_t Y;
    size_t W;
    size_t H;
};

struct TConsoleShape {
    std::vector<std::vector<char>> Shape;
    TCoordinate Position;
};

struct TCamera : public TRectangle {

    TCamera ApplyResolution(const size_t resolution) const {
        TCamera newCamera;
        newCamera.X = std::round(X * 1.0 / resolution);
        newCamera.Y = std::round(Y * 1.0 / resolution);
        newCamera.W = std::round(W * 1.0 / resolution);
        newCamera.H = std::round(H * 1.0 / resolution);
        return newCamera;
    }
    
    bool IsVisible(const TCoordinate& coordinate) const {
        return
            coordinate.X >= X &&
            coordinate.X < X + W &&
            coordinate.Y >= Y &&
            coordinate.Y < Y + H;
    }
};

class TObject {
public:
    virtual TConsoleShape GetConsoleShape(const size_t resolution) const = 0;
};

class TBuilding : public TObject {
public:
    TConsoleShape GetConsoleShape(const size_t resolution) const override {
        // FIXME
        TConsoleShape shape;
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
