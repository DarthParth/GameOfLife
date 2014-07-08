/*
 * RuleContext.h
 *
 *  Created on: Mar 9, 2014
 *      Author: parth
 */

#ifndef RULECONTEXT_H_
#define RULECONTEXT_H_

#include "Grid.h"
#include "Cell.h"

class FiringContext {
public:
	FiringContext(const Cell& currentCell, Cell& targetCell, const Grid& currentGrid) :
		_currentCell(currentCell),
		_targetCell(targetCell),
		_currentGrid(currentGrid) {}
	virtual ~FiringContext() {}
	const Grid& getGrid() const { return _currentGrid; }
	const Cell& getCurrentCell() const { return _currentCell; }
	Cell& getTargetCell() const { return _targetCell; }
private:
	const Cell& _currentCell;
	Cell& _targetCell;
	const Grid& _currentGrid;
};

#endif /* RULECONTEXT_H_ */
