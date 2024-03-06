#pragma once
#include "Linear/Vector.h"

class Vec2
{
    private:
        float m_X;
        float m_Y;

    public:
        Vec2()
            : m_X(0), m_Y(0) {}

        Vec2(float a, float b)
            : m_X(a), m_Y(b) {}

        Vec2(const Vec2& theVec)
            : m_X(theVec.m_X), m_Y(theVec.m_Y) {}
        

        Vec2(Vec2&& theVec)
            : m_X(theVec.m_X), m_Y(theVec.m_Y) {}
        

        inline f32 GetX() const {return m_X;}
        inline f32 GetY() const {return m_Y;}
                           
        inline f32 SetX() const {return m_X;}
        inline f32 SetY() const {return m_Y;}

        f32 dot(Vec2 theVec) {
            return (this->m_X * theVec.m_X) + (this->m_Y * theVec.m_Y);
        }

        Vec2 operator+(Vec2 theVec) {
            return Vec2(this->m_X + theVec.m_X, this->m_Y + theVec.m_Y);
        }

        Vec2 operator-(Vec2 theVec) {
            return Vec2(this->m_X - theVec.m_X, this->m_Y - theVec.m_Y);
        }

        Vec2& operator=(const Vec2& theVec) {
            if (this != &theVec)
            {
                m_X = theVec.m_X;
                m_Y = theVec.m_Y;
            }

            return *this;
        }
        
        Vec2& operator=(Vec2&& theVec) {
            if (this != &theVec)
            {
                m_X = theVec.m_X;
                m_Y = theVec.m_Y;
            }

            return *this;
        }


        bool operator==(Vec2 theVec) {
            if (theVec.m_X == this->m_X && theVec.m_Y == this->m_Y) {
                return true;
            }
            return false;
        }
};
