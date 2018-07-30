#pragma once

#include "../Common/Control.h"
#include <vector>
using namespace std;

class Panel : public Control
{
public:
	Panel(short newLeft, short newTop, short newWidth, short newHeight);
	~Panel();
	void AddControl(Control*);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual bool pointInside(int x, int y);
	virtual void getAllControls(vector<Control*>* controls);
	virtual void setFontColor(Color newColor);
	virtual void setBackgroundColor(Color newColor);
protected:
	short width;
	short height;
	vector<Control*> controls;
};
