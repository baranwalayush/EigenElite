#pragma once
#include "Linear/Vector.h"

template <class T>
class Vector2 : public Vector<T> {
    private:
    public:
        Vector2<T>();
        Vector2<T>(T, T);
};

#define Vec2 Vector2
