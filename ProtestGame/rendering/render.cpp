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

TConsoleRenderer::TConsoleRenderer(const size_t resolution, const TMap& map)
    : Resolution_(resolution)
    , Map_(map)
    , Camera_(map.GetCamera())
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
    const TCamera resolutedCamera = Camera_->ApplyResolution(Resolution_);

    for (size_t x = 0; x < Screen_.size(); ++x) {
        for (size_t y = 0; y < Screen_[0].size(); ++y) {
            if (resolutedCamera.IsVisible({x, y})) {
                Screen_[x][y] = ' ';
            }
        }
    }

    auto drawConsoleShape = [&resolutedCamera, &screen = Screen_](const TConsoleShape& objectShape) {
        for (size_t x = 0; x < objectShape.Shape.size(); ++x) {
            for (size_t y = 0; y < objectShape.Shape[0].size(); ++y) {
                const TCoordinate currentCoordinate{x + objectShape.Position.X, y + objectShape.Position.Y};
                if (resolutedCamera.IsVisible(currentCoordinate)) {
                    screen[x + objectShape.Position.X][y + objectShape.Position.Y] = objectShape.Shape[x][y];
                }
            }
        }
    };

    for (const shared_ptr<TObject>& object : Map_.GetObjects()) {
        const TConsoleShape& objectShape = object->GetConsoleShape(Resolution_);
        drawConsoleShape(objectShape);
    }
    
    const TConsoleShape& playerShape = Map_.GetPlayer().GetConsoleShape(Resolution_);
    drawConsoleShape(playerShape);

    for (size_t x = resolutedCamera.X; x < resolutedCamera.X + resolutedCamera.W; ++x) {
        for (size_t y = resolutedCamera.Y; y < resolutedCamera.Y + resolutedCamera.H; ++y) {
            cout << Screen_[x][y];
        }
        cout << '\n';
    }
}
