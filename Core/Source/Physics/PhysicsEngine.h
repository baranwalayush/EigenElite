#pragma once

#include "Linear/Vector.h"
#include "Physics/Vector2.h"
#include "Physics/PhysicsObject.h"

class PhysicsEngine {
    private:
        Vec2 m_Gravity;
        Vector<PhysicsObject> m_Objs;

    public:
        PhysicsEngine();
        PhysicsEngine(f32, f32);

        void SetGravity(f32, f32);
        Vec2 SetGravity();

        PhysicsEngine* GetInstance();

        PhysicsObject& GetPhysicsObject(i32);
        void PushPhyObject(PhysicsObject&);
        PhysicsObject& PopPhyObject();

        void UpdateObjects();
        void Simulate(i32);

    private:
        static PhysicsEngine* m_Instance;
};

PhysicsEngine* PhysicsEngine::m_Instance = nullptr;

