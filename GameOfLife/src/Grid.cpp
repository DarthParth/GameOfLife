/*
 * Grid.cpp
 *
 *  Created on: Mar 15, 2014
 *      Author: parth
 */
#include "Grid.h"
#include "FiringContext.h"
#include "Rule.h"

void Grid::advance(Grid& targetGrid, const Rule& rule) {
    if (targetGrid._sizeX != _sizeX || targetGrid._sizeY != _sizeY)
        throw std::exception();
    for (int row = 0; row < _sizeX; row++) {
        for (int column = 0; column < _sizeY; column++) {
            Cell& targetCell = targetGrid.getCell(row, column);
            const Cell& currentCell = getCell(row, column);
            rule.execute(FiringContext(currentCell, targetCell, *this));
        }
    }
}

