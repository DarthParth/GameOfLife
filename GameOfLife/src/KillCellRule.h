/*
 * KillCellRule.h
 *
 *  Created on: Mar 10, 2014
 *      Author: parth
 */

#ifndef KILLCELLRULE_H_
#define KILLCELLRULE_H_

#include "DefaultRule.h"

class KillCellRule: public DefaultRule {
public:
    KillCellRule() {}
    virtual ~KillCellRule() {}

protected:

    virtual bool _execute(int liveNeighbors, const FiringContext& ctx) const {
        bool result = (liveNeighbors <= 1 || liveNeighbors >= 4) ? true : false;
        if (result)
            ctx.getTargetCell().kill();
        return result;
    }
};

#endif /* KILLCELLRULE_H_ */
