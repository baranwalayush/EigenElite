#include "Physics/Vector2.h"

template <class T>
Vector2<T>::Vector2() {
    this->SetSize(2);
}

template <class T>
Vector2<T>::Vector2(T a , T b) {
    this->PushBack(a);
    this->PushBack(b);
}


template class Vector2<i32>;
