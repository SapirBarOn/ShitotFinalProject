#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{
protected:
	short left;
	short top;
	Control* parent;
	Color fontColor;
	Color backgroundColor;
	static Control* focus;
	
public:
	Control();
	Control(short newLeft, short newTop);
	static Control* getFocus() { return focus; };
	static void setFocus(Control& control);

	virtual void draw(Graphics& g, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus() { return FALSE; };
	virtual bool pointInside(int x, int y) = 0;
	void setParent(Control* newParent) { parent = newParent; }
	Control* getParent() { return parent; }
	Color getFontColor() { return fontColor; }
	virtual void setFontColor(Color newColor) { fontColor = newColor; }
	Color getBackgroundColor() { return backgroundColor; }
	virtual void setBackgroundColor(Color newColor) { backgroundColor = newColor; }
	virtual void removeFocus() {}
	~Control();
};
