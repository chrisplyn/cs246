#include "tblock.h"
#include "cell.h"


//direction:
//
// 0:             1:                 2:                  3:
//-------------       -------------      -------------        -------------
//|   |   |   |       | 0 |   |   |      |   |   |   |        |   | 2 |   |
//-------------       -------------      -------------        -------------
//|   | 3 |   |       | 1 | 3 |   |      | 2 | 1 | 0 |        | 3 | 1 |   |
//-------------       -------------      -------------        -------------
//| 0 | 1 | 2 |       | 2 |   |   |      |   | 3 |   |        |   | 0 |   |
//-------------       -------------      -------------        -------------
//

int TBlock::direction(){
    int originX = cells[0]->getX();
    int originY = cells[0]->getY();
    int nextX = cells[1]->getX();
    int nextY = cells[1]->getY();
    
    if (originX == nextX-1) {
        return 0;
    } else if (originX == nextX+1) {
        return 2;
    } else {
        if (originY == nextY+1) {
            return 1;
        }
        else {
            return 3;
        }
    }
}

