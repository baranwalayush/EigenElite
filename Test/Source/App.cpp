#include "test.h"

int main()
{
	Vector<Vec2> a;
	a.PushBack({ 1, 2 });
	a.PushBack({});
	a.PushBack({ 3, 4 });
	a.Print();
	a.Pop();
	a.Print();
	a.Clear();
	a.EmplaceBack(5, 6);
	a.Print();
}
