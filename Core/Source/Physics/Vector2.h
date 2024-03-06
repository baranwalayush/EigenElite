#pragma once
#include "Linear/Vector.h"

class Vec2{
    private:
        float m_X;
        float m_Y;

    public:
        Vec2() {}

        Vec2(const Vec2& theVec) {
            this->m_X = theVec.m_X;
            this->m_Y = theVec.m_Y;
        }

        Vec2(Vec2&& theVec) {
            this->m_X = theVec.m_X;
            this->m_Y = theVec.m_Y;
        }

        Vec2(f32 a, f32 b): m_X(a), m_Y(b) {}

        ~Vec2();

        inline f32 GetX() {return m_X;}
        inline f32 GetY() {return m_Y;}

        inline f32 SetX() {return m_X;}
        inline f32 SetY() {return m_Y;}

        f32 dot(Vec2 theVec) {
            return (this->m_X * theVec.m_X) + (this->m_Y * theVec.m_Y);
        }

        Vec2 operator+(Vec2 theVec) {
            return Vec2(this->m_X + theVec.m_X, this->m_Y + theVec.m_Y);
        }

        Vec2 operator-(Vec2 theVec) {
            return Vec2(this->m_X - theVec.m_X, this->m_Y - theVec.m_Y);
        }

        Vec2 operator=(Vec2 theVec) {
            return Vec2(theVec.m_X, theVec.m_Y);
        }

        bool operator==(Vec2 theVec) {
            if (theVec.m_X == this->m_X && theVec.m_Y == this->m_Y) {
                return true;
            }
            return false;
        }
};
