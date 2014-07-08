/*
 * main.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: parth
 */

#include "GameOfLife.h"
#include "N00BRenderer.h"

#include<iostream>

using namespace std;

int main() {
    GameOfLife gol(new N00BRenderer(), GameOfLife::IterationSpeed::FAST);
    bool seed[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            seed[i][j] = false;

    seed[2][1] = true;
    seed[2][2] = true;
    seed[2][3] = true;
    gol.start<5, 5>(seed);
    return 0;
}

