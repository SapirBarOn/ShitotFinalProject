#pragma once

#include "Panel.h"

class TextBox;
class Button;

class ComboBox : public Panel
{
public:
	ComboBox(short newLeft, short newTop, short newWidth, vector<string> options);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual bool canGetFocus() { return TRUE; };
	virtual void keyDown(int keyCode, char charecter);
	virtual void mousePressed(int x, int y, bool isLeft);
	void toggleListIsOpen();
	virtual void getAllControls(vector<Control*>* controls);
	virtual bool pointInside(int x, int y);

private:
	vector<string> options;
	size_t selectedIndex;
	int tempIndex;
	Button* openListButton;
	bool listIsOpen;
};
