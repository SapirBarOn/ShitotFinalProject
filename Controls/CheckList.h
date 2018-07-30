#pragma once

#include "Panel.h"

class CheckList : public Panel
{
public:
	CheckList(short newLeft, short newTop, short newWidth, vector<string> options);
	vector<size_t> GetSelectedIndices();
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual bool canGetFocus() { return TRUE; };
	virtual void keyDown(int keyCode, char charecter);
	virtual void mousePressed(int x, int y, bool isLeft);
	bool AddSelectedItem(string item);
	bool RemoveSelectedItem(string item);
	virtual void getAllControls(vector<Control*>* controls);
	virtual bool pointInside(int x, int y);
	virtual void removeFocus();
protected:
	vector<string> options;
	vector<size_t> selectedIndices;
	int tempIndex;
};

