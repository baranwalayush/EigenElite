#include "Physics/PhysicsEngine.h"
#include "PhysicsEngine.h"
#include <chrono>


PhysicsEngine::PhysicsEngine() {
    SetGravity(0.f, 0.f);
}

PhysicsEngine::PhysicsEngine(f32 a, f32 b) {
    SetGravity(a, b);
}

PhysicsEngine* PhysicsEngine::GetInstance() {
    if (m_Instance == nullptr) {
        m_Instance = new PhysicsEngine();
    }
    return m_Instance;
}

void PhysicsEngine::PushPhyObject(PhysicsObject& theObject) {
    m_Objs.PushBack(theObject);
}

PhysicsObject& PhysicsEngine::PopPhyObject() {
    m_Objs.Pop();
    return m_Objs.Last();
}

void PhysicsEngine::UpdateObject() {
    
}

void PhysicsEngine::Simulate(i32 theTime) {
    auto start = std::chrono::steady_clock::now();
;
    while (std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::steady_clock::now() - start).count() < theTime) {

        for (i32 i = 0; i < m_Objs.GetSize() - 1; i++) {
            // collision check
            // Collider::CheckCollision(m_Objects[i], m_Objects[i + 1]);
        }
    }
}

