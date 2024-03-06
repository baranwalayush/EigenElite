#pragma once

#include "defines.h"

#include "Linear/Matrix.h"
#include "Linear/Vector.h"

#include "Physics/PhysicsEngine.h"
#include "Physics/PhysicsObject.h"
#include "Physics/Collider.h"
#include "Physics/Shape.h"
#include "Physics/Vec2.h"

using std::cout, std::endl;

template <class T>
void TestDefines() {
    T  x0 = 0;
    i16 x1 = 0;

    cout << MAX(x0, x1) << endl;
    cout << MIN(x0, x1) << endl;
    cout << SQ(6) << endl;
}


template <class T>
void TestMatrix() {
    Matrix<T> x0(3, 2);

    for (T i = 0; i < x0.GetRowSize(); i++) {
        for (T j = 0; j < x0.GetColumnSize(); j++) {
            x0[i][j] = i;
        }
    }
    x0.Print();
    Matrix<T> x1 = x0.Transpose();
    x1.Print();

    std::cout << x1.Trace() << std::endl;;
}

template <class T>
void TestVector() {
    Vector<T> x0(3);

    x0.PushBack(1);
    x0.PushBack(2);
    x0.PushBack(3);
    x0.Pop();
    cout << x0.Last() << endl;
    x0.Clear();
}


void TestEngine() {
    PhysicsObject a(Vec2(1, 2), Vec2(1, 2), true, true);
    PhysicsObject b(Vec2(1, 2), Vec2(1, 2), true, true);
    PhysicsObject c(Vec2(1, 2), Vec2(1, 2), true, true);

    PhysicsEngine* engine = PhysicsEngine::GetInstance();
    engine->PushPhyObject(&a);
    engine->PushPhyObject(&b);
    engine->PushPhyObject(&c);
}

void TestCollider() {

}
