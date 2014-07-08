/*
 * Cell.h
 *
 *  Created on: Mar 5, 2014
 *      Author: parth
 */

#ifndef CELL_H_
#define CELL_H_

class Cell {
public:
	Cell(int x, int y) : _alive( false ), _x( x ), _y( y ) {}
	~Cell() {}
	void kill() { _alive = false; }
	void resurrect() { _alive = true; }
	bool isAlive() const { return _alive; }
	int getX() const { return _x; }
	int getY() const { return _y; }
private:
	bool _alive;
	int _x;
	int _y;

};

#endif /* CELL_H_ */
