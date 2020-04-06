//
//  render.cpp
//  ProtestGame
//
//  Created by Ivan Ivashkovskii on 06/04/2020.
//  Copyright © 2020 Ivan Ivashkovskii. All rights reserved.
//

#include "render.h"
#include <iostream>
#include <cmath>

using namespace std;

TConsoleRenderer::TConsoleRenderer(const size_t resolution, const TMap& map)
    : Resolution_(resolution)
    , Map_(map)
{
    const TCoordinate mapBorder = Map_.GetMapBorder();
    Screen_.resize(round(mapBorder.X * 1.0 / Resolution_));
    for (size_t x = 0; x < Screen_.size(); ++x) {
        Screen_[x].resize(round(mapBorder.Y * 1.0 / Resolution_), ' ');
    }
}

void TConsoleRenderer::Flush() {
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void TConsoleRenderer::Render() {
    for (size_t x = 0; x < Screen_.size(); ++x) {
        for (size_t y = 0; y < Screen_[0].size(); ++y) {
            Screen_[x][y] = ' ';
        }
    }

    for (const shared_ptr<TObject>& object : Map_.GetObjects()) {
        const TConsoleShape& consoleOnjectShape = object->GetConsoleShape(Resolution_);
    
        for (size_t x = 0; x < consoleOnjectShape.Shape.size(); ++x) {
            for (size_t y = 0; y < consoleOnjectShape.Shape[0].size(); ++y) {
                Screen_[x + consoleOnjectShape.Position.X][y + consoleOnjectShape.Position.Y] = consoleOnjectShape.Shape[x][y];
            }
        }
    }
    
    cout << '*';
    for (size_t x = 0; x < Screen_.size(); ++x) {
        cout << '-';
    }
    cout << '*' << '\n';

    for (size_t y = 0; y < Screen_[0].size(); ++y) {
        cout << '|';
        for (size_t x = 0; x < Screen_.size(); ++x) {
            cout << Screen_[x][y];
        }
        cout << '|' << '\n';
    }
    
    cout << '*';
    for (size_t x = 0; x < Screen_.size(); ++x) {
        cout << '-';
    }
    cout << '*';
}
