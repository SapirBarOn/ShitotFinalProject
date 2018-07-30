#include "RadioBox.h"

RadioBox::RadioBox(short newLeft, short newTop, short newWidth, vector<string> options) :
CheckList(newLeft, newTop, newWidth, options)
{

}

void RadioBox::keyDown(int keyCode, char charecter)
{
	if (keyCode == VK_UP) // up
	{
		if (tempIndex > 0)
			tempIndex--;
	}
	else if (keyCode == VK_DOWN) // down
	{
		if (tempIndex < options.size() - 1)
			tempIndex++;
	}
	else if ((keyCode == VK_SPACE) || (keyCode == VK_RETURN)) // space or enter
	{
		std::vector<size_t>::iterator iter = std::find(selectedIndices.begin(), selectedIndices.end(), tempIndex);
		if (iter == selectedIndices.end())
		{
			selectedIndices.clear();
			selectedIndices.push_back(tempIndex);
		}
		else
		{
			selectedIndices.erase(iter);
		}
	}
}

void RadioBox::mousePressed(int x, int y, bool isLeft)
{
	Control::setFocus(*this);
	int index = y - top;
	tempIndex = index;
	std::vector<size_t>::iterator iter = std::find(selectedIndices.begin(), selectedIndices.end(), tempIndex);
	if (iter == selectedIndices.end())
	{
		selectedIndices.clear();
		selectedIndices.push_back(tempIndex);
	}
	else
	{
		selectedIndices.erase(iter);
	}
}

