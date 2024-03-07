#include "Physics/PhysicsEngine.h"
#include "PhysicsEngine.h"
#include "Physics/Collider.h"
#include <iostream>


PhysicsEngine::PhysicsEngine() {
    // SetGravity(0.f, 0.f);
}


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
    Vec2 pos;
    Vec2 vel;

    for (int i = 0; i < m_Objs.GetSize(); i++) {
        if (m_Objs[i]->IsGravityEnabled()) {
            pos = m_Objs[i]->GetPosition() + GetGravity();
            vel = m_Objs[i]->GetVelocity() + GetGravity();
        }
        else {
            pos = m_Objs[i]->GetPosition();
            vel = m_Objs[i]->GetVelocity();
        }

        if (pos.GetX() > SCREEN_WIDTH || pos.GetX() < 0) {
            vel.SetX(-vel.GetX());
        }
        if (pos.GetY() > SCREEN_HEIGHT || pos.GetY() < 0) {
            vel.SetY(-vel.GetY());
        }

        pos = pos + vel;
        m_Objs[i]->SetPosition(pos);
        m_Objs[i]->SetVelocity(vel);
    }
}

void PhysicsEngine::Simulate() {
    for (i32 i = 0; i < m_Objs.GetSize(); i++) {
        for (i32 j = i+1; j < m_Objs.GetSize(); j++) {
            // collision check
            // Collider::CheckCollision(m_Objects[i], m_Objects[i + 1]);

            if (m_Objs[i]->IsCollisionEnabled()) {
                Collider* collider1 = static_cast<Collider*>(m_Objs[i]);
                Collider* collider2 = static_cast<Collider*>(m_Objs[j]);

                if (collider1->Intersects(*collider2)) {
                    m_Objs[i]->SetVelocity(-m_Objs[i]->GetVelocity().GetX(),
                            -m_Objs[i]->GetVelocity().GetY());
                    m_Objs[j]->SetVelocity(-m_Objs[j]->GetVelocity().GetX(),
                            -m_Objs[i]->GetVelocity().GetY());
                }
            }


        }
    }
    UpdateObjects();
}

void PhysicsEngine::SetGravity(f32 a, f32 b) {
    m_Gravity.SetX(a);
    m_Gravity.SetY(b);
}

