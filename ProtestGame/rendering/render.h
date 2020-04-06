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
#include <vector>

class TRenderer {
public:
    virtual void Render(const TMap& map) = 0;
    virtual void Flush() = 0;
};

class TConsoleRenderer : public TRenderer {
public:
    TConsoleRenderer(const size_t resolution);

    void Render(const TMap& map) override;
    void Flush() override;
private:
    const size_t Resolution_;
    std::vector<std::vector<char>> Screen_;
};
#endif /* render_h */
