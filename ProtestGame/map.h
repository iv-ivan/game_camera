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
    TMap();
    ~TMap();
private:
    std::vector<std::shared_ptr<TObject>> Objects_;
    size_t Width_;
    size_t Height_;
};

#endif /* map_h */
