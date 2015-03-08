/*
 * GameOfLife.h
 *
 *  Created on: Mar 12, 2014
 *      Author: parth
 */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#include "Grid.h"
#include "RuleChain.h"
#include "KillCellRule.h"
#include "KeepCellAliveRule.h"
#include "ResurrectCellRule.h"
#include "Renderer.h"
#include <unistd.h>

class GameOfLife {
public:
    enum IterationSpeed {
        TORTOISE = 1000, SLOW = 700, MEDIUM = 500, FAST = 200, EXTREME = 50
    };

    GameOfLife(const Renderer* renderer, IterationSpeed speed) :
            _sourceGrid(0), _targetGrid(0), _renderer(renderer), _speed(speed) {}
    virtual ~GameOfLife() {
        if (_sourceGrid)
            delete _sourceGrid;
        if (_targetGrid)
            delete _targetGrid;
        if(_renderer)    
            delete _renderer;
    }

    template<size_t sizeX, size_t sizeY>
    void start(bool seed[sizeX][sizeY]) {

        _sourceGrid = new Grid(sizeX, sizeY);
        _targetGrid = new Grid(sizeX, sizeY);
        _sourceGrid->initialize<sizeX, sizeY>(seed);
        _targetGrid->reset();
        vector<Rule *> rules;
        rules.push_back(new KillCellRule());
        rules.push_back(new KeepCellAliveRule());
        rules.push_back(new ResurrectCellRule());
        _sourceGrid->render(_renderer);
        RuleChain chain(rules);
        while (true) {
            _sourceGrid->advance(*_targetGrid, chain);
            _sourceGrid->reset();
            _targetGrid->render(_renderer);
            swapGrids();
            ::usleep(_speed * 1000);
        }
    }
private:
    Grid *_sourceGrid;
    Grid *_targetGrid;
    const Renderer* _renderer;
    IterationSpeed _speed;

    void swapGrids() {
        Grid *temp = _sourceGrid;
        _sourceGrid = _targetGrid;
        _targetGrid = temp;
    }
};

#endif /* GAMEOFLIFE_H_ */
