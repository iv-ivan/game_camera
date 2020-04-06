//
//  render.cpp
//  ProtestGame
//
//  Created by Ivan Ivashkovskii on 06/04/2020.
//  Copyright © 2020 Ivan Ivashkovskii. All rights reserved.
//

#include "render.h"
#include <iostream>

using namespace std;

void TConsoleRenderer::Flush() {
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void TConsoleRenderer::Render(const TMap& map) {
    for (size_t x = 0; x < Screen_.size(); ++x) {
        for (size_t y = 0; y < Screen_[0].size(); ++y) {
            Screen_[x][y] = ' ';
        }
    }

    for (const shared_ptr<TObject>& object : map.GetObjects()) {
        const TConsoleShape& consoleOnjectShape = object->GetConsoleShape(Resolution_);
    
        for (size_t x = 0; x < consoleOnjectShape.Shape.size(); ++x) {
            for (size_t y = 0; y < consoleOnject.Shape[0].size(); ++y) {
                Screen_[x + consoleOnjectShape.Position.X][y + consoleOnjectShape.Position.Y] = consoleOnjectShape.Shape[x][y];
            }
        }
    }
    
    for (size_t y = 0; y < Screen_[0].size(); ++y) {
        for (size_t x = 0; x < Screen_.size(); ++x) {
            std::cout << Screen_[x][y];
        }
        std::cout << '\n';
    }
}
