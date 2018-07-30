#pragma once

#include "Panel.h"

class TextBox;
class Button;

class NumericBox : public Panel
{
public:
	NumericBox(short newLeft, short newTop, short newWidth, int min, int max);
	int GetValue() { return currentValue; }
	bool SetValue(int value);
	void upOne();
	void downOne();
	void setMin(int newMin) { minValue = newMin; }
	void setMax(int newMax) { maxValue = newMax; }
	virtual bool canGetFocus() { return FALSE; };
	virtual void getAllControls(vector<Control*>* controls) {}

private:
	TextBox* text;
	Button* up;
	Button* down;
	int minValue;
	int maxValue;
	int currentValue;
};
