#pragma once
class Button
{
public:
	Button(Rect buttonObj,Color color,String str);
	~Button() {};
	bool ButtonClicked();
	void Draw(Font buttonFont) const;
	Rect m_buttonObj;
	Color m_buttonNormalColor;
	Color m_buttonOverColor;
	Color m_buttonClickColor;
	String buttonStr;
};

