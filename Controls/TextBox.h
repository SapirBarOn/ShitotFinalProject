#pragma once

#include "Label.h"
#include <string>

class TextBox : public Label
{
public:
	TextBox(short newLeft, short newTop, string val, int newWidth);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter);
	virtual bool canGetFocus() { return TRUE; };
	short getWidth() const { return width; }
	void setWidth(short newWidtn) { width = newWidtn; }

private:
	short width;
	short cursorPosition;
};
