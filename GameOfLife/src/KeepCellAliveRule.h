/*
 * KeepCellAliveRule.h
 *
 *  Created on: Mar 11, 2014
 *      Author: parth
 */

#ifndef KEEPCELLALIVERULE_H_
#define KEEPCELLALIVERULE_H_

#include "DefaultRule.h"

class KeepCellAliveRule: public DefaultRule {
public:
    KeepCellAliveRule() {}
    virtual ~KeepCellAliveRule() {}

protected:

    virtual bool _execute(int liveNeighbors, const FiringContext& ctx) const {
        bool result = (liveNeighbors == 2 || liveNeighbors == 3);
        result = result && ctx.getCurrentCell().isAlive();
        if (result)
            ctx.getTargetCell().resurrect();
        return result;
    }
};

#endif /* KEEPCELLALIVERULE_H_ */
