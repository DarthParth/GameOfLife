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
	//test2();
	//test1();
//	TextTestRunner runner;
//	runner.addTest(GridTest::suite());
//	runner.addTest(DefaultRuleTest::suite());
//	runner.addTest(KillCellRuleTest::suite());
//	runner.addTest(KeepCellAliveRuleTest::suite());
//	TextTestResult r;
//	runner.run(r, "GridTest");
//	runner.run(r, "DefaultRuleTest");
//	runner.run(r, "KillCellRuleTest");
//	runner.run(r, "KeepCellAliveRuleTest");

	GameOfLife gol(new N00BRenderer(), GameOfLife::IterationSpeed::FAST);
	bool seed[5][5];
	for(int i = 0; i < 5; i++ )
		for(int j = 0; j < 5; j++)
			seed[i][j] = false;

	seed[2][1] = true;
	seed[2][2] = true;
	seed[2][3] = true;
	gol.start<5, 5>(seed);
	return 0;
}

