/*
 * Renderer.h
 *
 *  Created on: Mar 15, 2014
 *      Author: parth
 */

#ifndef RENDERER_H_
#define RENDERER_H_
#include <vector>

using namespace std;

class Renderer {
public:
	Renderer() {}
	virtual ~Renderer() {}
	virtual void render(const vector<vector<Cell *> >& grid) const = 0;
};

#endif /* RENDERER_H_ */
