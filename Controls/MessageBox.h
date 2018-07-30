#pragma once

#include "Panel.h"

class Label;
class Button;

// call it SpecialMessageBox because there is a mismatch with MessageBox
class SpecialMessageBox : public Panel
{
public:
	SpecialMessageBox(short newLeft, short newTop, short newWidth, string message);
	string getClickedButton();
	void setClickedButton(string);

private:
	Label* text;
	Button* okButton;
	Button* cancelButton;
	string clickedButton;
};


