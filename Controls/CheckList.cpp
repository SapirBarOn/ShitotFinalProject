#include "CheckList.h"
#include <algorithm>

CheckList::CheckList(short newLeft, short newTop, short newWidth, vector<string> _options) :
Panel(newLeft, newTop, newWidth, 1), options(_options), tempIndex(-1)
{
}

vector<size_t> CheckList::GetSelectedIndices()
{
	return selectedIndices;
}

void CheckList::SelectIndex(size_t index)
{
	if (std::find(selectedIndices.begin(), selectedIndices.end(), index) == selectedIndices.end())
		selectedIndices.push_back(index);
}

void CheckList::DeselectIndex(size_t index)
{
	std::vector<size_t>::iterator iter = std::find(selectedIndices.begin(), selectedIndices.end(), index);
	selectedIndices.erase(iter);
}

void CheckList::getAllControls(vector<Control*>* controls)
{
	controls->push_back(this);
}

bool CheckList::pointInside(int x, int y)
{
	return (x >= left) && (x <= left + width) && (y >= top) && (y <= top + options.size());
}

void CheckList::removeFocus()
{
	tempIndex = -1;
}

void CheckList::draw(Graphics& g, int x, int y, size_t z)
{
	int i = 0;
	for (std::vector<string>::iterator it = options.begin(); it != options.end(); ++it)
	{
		if (tempIndex != i)
		{
			g.setBackground(backgroundColor);
			g.setForeground(fontColor);
		}
		else
		{
			g.setBackground(fontColor);
			g.setForeground(backgroundColor);
		}
		if (std::find(selectedIndices.begin(), selectedIndices.end(), i) != selectedIndices.end())
		{
			g.write(left + x, top + y + i, " * ");
		}
		else
		{
			g.write(left + x, top + y + i, "   ");
		}
		g.write(left + x + 3, top + y + i, (*it));
		i++;
	}
	g.setBackground(backgroundColor);
	g.setForeground(fontColor);
}

bool CheckList::AddSelectedItem(string item)
{
	int i = 0;
	for (std::vector<string>::iterator it = options.begin(); it != options.end(); ++it)
	{
		if ((*it) == item)
		{
			std::vector<size_t>::iterator iter = std::find(selectedIndices.begin(), selectedIndices.end(), tempIndex);
			if (iter == selectedIndices.end())
				selectedIndices.push_back(i);
			return true;
		}
		i++;
	}
	return false;
}

bool CheckList::RemoveSelectedItem(string item)
{
	int i = 0;
	for (std::vector<string>::iterator it = options.begin(); it != options.end(); ++it)
	{
		if ((*it) == item)
		{
			std::vector<size_t>::iterator iter = std::find(selectedIndices.begin(), selectedIndices.end(), tempIndex);
			if (iter != selectedIndices.end())
				selectedIndices.erase(iter);
			return true;
		}
		i++;
	}
	return false;
}

void CheckList::keyDown(int keyCode, char charecter)
{
	if (keyCode == VK_UP) // up
	{
		if (tempIndex > 0)
			tempIndex--;
		else
			tempIndex = options.size() - 1;
	}
	else if (keyCode == VK_DOWN) // down
	{
		if (tempIndex < options.size() - 1)
			tempIndex++;
		else
			tempIndex = 0;
	}
	else if ((keyCode == VK_SPACE) || (keyCode == VK_RETURN)) // space or enter
	{
		std::vector<size_t>::iterator iter = std::find(selectedIndices.begin(), selectedIndices.end(), tempIndex);
		if (iter == selectedIndices.end())
			selectedIndices.push_back(tempIndex);
		else
			selectedIndices.erase(iter);
	}
}

void CheckList::mousePressed(int x, int y, bool isLeft)
{
	Control::setFocus(*this);
	int index = y - top;
	tempIndex = index;
	std::vector<size_t>::iterator iter = std::find(selectedIndices.begin(), selectedIndices.end(), tempIndex);
	if (iter == selectedIndices.end())
		selectedIndices.push_back(tempIndex);
	else
		selectedIndices.erase(iter);
}


