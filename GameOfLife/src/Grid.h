/*
 * Grid.h
 *
 *  Created on: Mar 9, 2014
 *      Author: parth
 */

#ifndef GRID_H_
#define GRID_H_

#include <exception>
#include <vector>
#include "Cell.h"
#include "Renderer.h"

using namespace std;

class Rule;

class Grid {
public:
    Grid(int sizeX, int sizeY) : _grid(0), _sizeX(sizeX), _sizeY(sizeY) {
        for (int row = 0; row < _sizeX; row++) {
            _grid.push_back(vector<Cell *>());
            for (int column = 0; column < _sizeY; column++) {
                _grid[row].push_back(new Cell(row, column));
            }
        }
    }

    virtual ~Grid() {
        for (int row = 0; row < _sizeX; row++) {
            for (int column = 0; column < _sizeY; column++) {
                delete _grid[row][column];
            }
        }
    }

    Cell& getCell(int x, int y) const {
        if (!isCellValid(x, y))
            throw exception();
        return *(_grid[x][y]);
    }

    bool isCellValid(int x, int y) const {
        return !(x < 0 || x >= _sizeX || y < 0 || y >= _sizeY);
    }

    void reset() {
        for (int row = 0; row < _sizeX; row++) {
            for (int column = 0; column < _sizeY; column++) {
                _grid[row][column]->kill();
            }
        }
    }

    template<size_t sizeX, size_t sizeY>
    void initialize(bool seed[sizeX][sizeY]) {
        if (sizeX != _sizeX || sizeY != _sizeY)
            throw exception();
        for (int row = 0; row < _sizeX; row++) {
            for (int column = 0; column < _sizeY; column++) {
                if (seed[row][column]) {
                    _grid[row][column]->resurrect();
                }
            }
        }
    }

    /* implemented in Grid.cpp to break include loop */
    void advance(Grid& targetGrid, const Rule& rule);

    void render(const Renderer* renderer) {
        renderer->render(_grid);
    }

private:
    vector<vector<Cell *> > _grid;
    int _sizeX;
    int _sizeY;
};

#endif /* GRID_H_ */
