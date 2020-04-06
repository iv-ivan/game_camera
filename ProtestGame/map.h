//
//  map.h
//  ProtestGame
//
//  Created by Ivan Ivashkovskii on 06/04/2020.
//  Copyright © 2020 Ivan Ivashkovskii. All rights reserved.
//

#ifndef map_h
#define map_h

#include "classes.h"
#include <vector>
#include <memory>

class TMap {
public:
    TMap()
        : Width_(20)
        , Height_(40)
    {
        Objects_.push_back(std::make_shared<TBuilding>());
    }

    ~TMap() = default;
    const std::vector<std::shared_ptr<TObject>>& GetObjects() const {
        return Objects_;
    }

    TCoordinate GetMapBorder() const {
        return TCoordinate{Width_, Height_};
    }
private:
    std::vector<std::shared_ptr<TObject>> Objects_;
    size_t Width_;
    size_t Height_;
};

#endif /* map_h */
