/*
 * DefaultRule.h
 *
 *  Created on: Mar 9, 2014
 *      Author: parth
 */

#ifndef DEFAULTRULE_H_
#define DEFAULTRULE_H_

#include "Rule.h"
#include <vector>

using namespace std;

class DefaultRule: public Rule {
public:
    DefaultRule() {}
    virtual ~DefaultRule() {}
    virtual bool execute(const FiringContext& ctx) const {
        int liveNeighbors = _getLiveNeighbors(ctx);
        return _execute(liveNeighbors, ctx);
    }
protected:
    virtual bool _execute(int liveNeighbors,
            const FiringContext& ctx) const = 0;
private:

    int _getLiveNeighbors(const FiringContext& ctx) const {
        int liveNeighbors = 0;
        const Grid& grid = ctx.getGrid();
        const Cell& cell = ctx.getCurrentCell();
        int x = cell.getX();
        int y = cell.getY();

        for (int row = x - 1; row <= (x + 1); row++) {
            for (int column = y - 1; column <= (y + 1); column++) {
                if (grid.isCellValid(row, column) && !(row == x && column == y)) {
                    const Cell& neighbor = grid.getCell(row, column);
                    if (neighbor.isAlive())
                        liveNeighbors++;
                }
            }
        }
        return liveNeighbors;
    }
};

#endif /* DEFAULTRULE_H_ */
