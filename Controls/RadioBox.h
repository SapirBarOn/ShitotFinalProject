#pragma once

#include "CheckList.h"

class RadioBox : public CheckList
{
public:
	RadioBox(short newLeft, short newTop, short newWidth, vector<string> options);
	virtual void keyDown(int keyCode, char charecter);
	virtual void mousePressed(int x, int y, bool isLeft);
private:
};




