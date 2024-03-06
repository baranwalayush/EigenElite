#include "Physics/PhysicsEngine.h"
#include "PhysicsEngine.h"
#include "Physics/Collider.h"
#include <chrono>


// PhysicsEngine::PhysicsEngine() {
//     // SetGravity(0.f, 0.f);
// }

PhysicsEngine* PhysicsEngine::GetInstance() {
    if (m_Instance == nullptr) {
        m_Instance = new PhysicsEngine();
    }
    return m_Instance;
}

PhysicsObject* PhysicsEngine::GetPhysicsObject(i32 theIndex) {
    return this->m_Objs[theIndex];
}

void PhysicsEngine::PushPhyObject(PhysicsObject* theObject) {
    m_Objs.PushBack(theObject);
}

PhysicsObject* PhysicsEngine::PopPhyObject() {
    m_Objs.Pop();
    return m_Objs.Last();
}

void PhysicsEngine::UpdateObjects() {
    for (int i = 0; i < m_Objs.GetSize(); i++) {
        Vec2 pos = m_Objs[i]->GetPosition();
        Vec2 vel = m_Objs[i]->GetVelocity();
        pos = pos + vel;
        m_Objs[i]->SetPosition(pos);
    }
}

void PhysicsEngine::Simulate(i32 theTime) {
    auto start = std::chrono::steady_clock::now();
;
    while (std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::steady_clock::now() - start).count() < theTime) {

        for (i32 i = 0; i < m_Objs.GetSize() - 1; i++) {
            for (i32 j = 0; j < m_Objs.GetSize() - 1; j++) {
                // collision check
                // Collider::CheckCollision(m_Objects[i], m_Objects[i + 1]);
                if (i != j) {
                    Collider* collider1 = static_cast<Collider*>(m_Objs[i]);
                    Collider* collider2 = static_cast<Collider*>(m_Objs[j]);
                }
            }
        }
        UpdateObjects();
    }
}

void PhysicsEngine::SetGravity(f32 a, f32 b) {
    m_Gravity.SetX(a);
    m_Gravity.SetY(b);
}

