//
//  render.h
//  ProtestGame
//
//  Created by Ivan Ivashkovskii on 06/04/2020.
//  Copyright © 2020 Ivan Ivashkovskii. All rights reserved.
//

#ifndef render_h
#define render_h

#include "map.h"
#include "classes.h"
#include <vector>

class TRenderer {
public:
    virtual void Render(const TCamera& camera) = 0;
    virtual void Flush() = 0;
};

class TConsoleRenderer : public TRenderer {
public:
    TConsoleRenderer(const size_t resolution, const TMap& map);

    void Render(const TCamera& camera) override;
    void Flush() override;
private:
    const size_t Resolution_;
    const TMap& Map_;
    std::vector<std::vector<char>> Screen_;
};
#endif /* render_h */
