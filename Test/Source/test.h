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
    f32 x = 0;
    FAST_INV_SQRT(0.25, x);
}


template <class T>
void TestMatrix() {
    Cybug::Matrix<T> x0(3, 2);

    for (T i = 0; i < x0.GetRowSize(); i++) {
        for (T j = 0; j < x0.GetColumnSize(); j++) {
            x0[i][j] = i;
        }
    }
    x0.Print();
    Cybug::Matrix<T> x1 = x0.Transpose();
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

template <class T>
void TestVec2() {
    Vec2 a(2, 3);
    Vec2 b(3, 3);

    Vec2 c = a - b;
    cout << c.GetX() << " " << c.GetY() << endl;
}


void TestEngine() {
    Collider a(Vec2(0, 2), Vec2(0, -2), true, true, Shape::Type::Circle);
    Collider b(Vec2(0, -2), Vec2(0, 2), true, true, Shape::Type::Circle);

    PhysicsEngine* engine = PhysicsEngine::GetInstance();
    engine->PushPhyObject(&a);
    engine->PushPhyObject(&b);

    int i = 5;
    while (i) {
        engine->Simulate();
        cout << engine->GetPhysicsObject(0)->GetPosition().GetX() << " " <<
             engine->GetPhysicsObject(0)->GetPosition().GetY() << endl;
        i--;
    }
}

void TestFastInv() {
    f32 x = 0;
    float y = 0.25;
    cout << x << endl;
}
