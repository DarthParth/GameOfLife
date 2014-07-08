/*
 * N00BRenderer.h
 *
 *  Created on: Mar 15, 2014
 *      Author: parth
 */

#ifndef N00BRENDERER_H_
#define N00BRENDERER_H_

#include "Renderer.h"
#include "Cell.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

class N00BRenderer: public Renderer {
public:
    N00BRenderer() {}
    virtual ~N00BRenderer() {}
    virtual void render(const vector<vector<Cell *> >& grid) const {
        ::system("clear");
        for (vector<Cell *> row : grid) {
            for (const Cell *cell : row) {
                if (cell->isAlive())
                    cout << "* ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }
};

#endif /* N00BRENDERER_H_ */
