#pragma once

#include "Linear/Vector.h"
#include "Physics/Vec2.h"
#include "Physics/PhysicsObject.h"

class PhysicsEngine {
    private:
        Vec2 m_Gravity;
        Vector<PhysicsObject*> m_Objs;

    public:
        PhysicsEngine();
        /**
         * 
         * @param  {f32} undefined : 
         * @param  {f32} undefined : 
         */
        void SetGravity(f32, f32);
        /**
         * 
         * @return {Vec2}  : 
         */
        inline Vec2 GetGravity() {return m_Gravity;}
        /**
         * 
         * @return {PhysicsEngine*}  : 
         */
        static PhysicsEngine* GetInstance();
        /**
         * 
         * @param  {i32} undefined   : 
         * @return {PhysicsObject*}  : 
         */
        PhysicsObject* GetPhysicsObject(i32);
        /**
         * 
         * @param  {PhysicsObject*} undefined : 
         */
        void PushPhyObject(PhysicsObject*);
        /**
         * 
         * @return {PhysicsObject*}  : 
         */
        PhysicsObject* PopPhyObject();
        /**
         * 
         * @return {u32}  : 
         */
        inline u32 GetSize() const {return m_Objs.GetSize();}
        /**
         * 
         */
        void UpdateObjects();
        /**
         * 
         */
        void Simulate();

    private:
        static PhysicsEngine* m_Instance;
};


inline PhysicsEngine* PhysicsEngine::m_Instance = nullptr;
