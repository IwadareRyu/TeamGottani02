#include "../stdafx.h"
#include "Button.h"

Button::Button(Rect buttonObj, Color color,String str) :
	m_buttonObj(buttonObj),m_buttonNormalColor(color),
	m_buttonOverColor(Palette::Red),m_buttonClickColor(Palette::Gray),
	buttonStr(str)
{

}

bool Button::ButtonClicked()
{
	return m_buttonObj.leftReleased();
}

void Button::Draw(Font buttonFont) const
{
	if (m_buttonObj.mouseOver())
	{
		if (m_buttonObj.leftClicked())
		{
			m_buttonObj.draw(m_buttonClickColor);
		}
		else
		{
			m_buttonObj.draw(m_buttonOverColor);
		}
	}
	else
	{
		m_buttonObj.draw(m_buttonNormalColor);
	}
	buttonFont(buttonStr)
		.drawAt(
			m_buttonObj.x + m_buttonObj.w / 2,
			m_buttonObj.y + m_buttonObj.h / 2,
			Palette::Black
			);
}
