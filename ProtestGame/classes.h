//
//  classes.h
//  ProtestGame
//
//  Created by Ivan Ivashkovskii on 06/04/2020.
//  Copyright © 2020 Ivan Ivashkovskii. All rights reserved.
//

#ifndef classes_h
#define classes_h

class TObject {
    
};

class TBuilding : public TObject {
    
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
