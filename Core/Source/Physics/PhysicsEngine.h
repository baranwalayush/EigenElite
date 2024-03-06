#pragma once

#include "Linear/Vector.h"
#include "Physics/Vector2.h"
#include "Physics/PhysicsObject.h"

class PhysicsEngine {
    private:
        Vec2<f32> m_Gravity;
        Vector<PhysicsObject> m_Objs;

    public:
        PhysicsEngine();
        PhysicsEngine(f32, f32);

        void SetGravity(f32, f32);
        Vec2<f32> SetGravity();

        PhysicsObject& GetPhysicsObject(i32);
        void PushPhyObject(PhysicsObject&);
        PhysicsObject& PopPhyObject();
        PhysicsEngine* GetInstance();
        void Simulate(i32);
        void UpdateObject();

    private:
        static PhysicsEngine* m_Instance;
};

PhysicsEngine* PhysicsEngine::m_Instance = nullptr;

