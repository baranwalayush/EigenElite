#pragma once
class Shape
{
public:
	enum Type
	{
		Circle, Square
	};

	inline Type GetType() const
	{
		return m_Type;
	}
private:
	Type m_Type;
};

