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
    TMap(const size_t width, const size_t height, const size_t cameraWidth, const size_t cameraHeight)
        : Width_(width)
        , Height_(height)
    , Camera_(std::make_shared<TCamera>())
    {
        Camera_->W = cameraWidth;
        Camera_->H = cameraHeight;
    }

    ~TMap() = default;
    const std::vector<std::shared_ptr<TObject>>& GetObjects() const {
        return Objects_;
    }

    const std::shared_ptr<const TCamera> GetCamera() const {
        return Camera_;
    }

    TCoordinate GetMapBorder() const {
        return TCoordinate{Width_, Height_};
    }
private:
    std::vector<std::shared_ptr<TObject>> Objects_;
    TPlayer Me_;
    const std::shared_ptr<TCamera> Camera_;

    size_t Width_;
    size_t Height_;
};

#endif /* map_h */
