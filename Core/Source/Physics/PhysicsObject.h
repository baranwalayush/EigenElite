#pragma once
#include "defines.h"

struct Vec2
{
	f32 x, y;
};

class PhysicsObject
{
public:
	PhysicsObject(Vec2 theVelocity, Vec2 thePosition, bool theGravityEnabled, bool theCollisionEnabled)
		: m_Veclocity(theVelocity), m_Position(thePosition), m_GravityEnabled(theGravityEnabled), m_CollisionEnabled(theCollisionEnabled) {}

	inline void SetVelocity(Vec2 theVelocity) { m_Veclocity = theVelocity; }
	inline void SetPosition(Vec2 thePosition) { m_Position = thePosition; }
	
	inline void SetVelocity(f32 theX, f32 theY) { m_Veclocity = Vec2(theX, theY); }
	inline void SetPosition(f32 theX, f32 theY) { m_Position = Vec2(theX, theY); }

	inline Vec2 GetVelocity() const { return m_Veclocity; }
	inline Vec2 GetPosition() const { return m_Position; }

	inline bool IsGravityEnabled() const { return m_GravityEnabled; }
	inline bool IsCollisionEnabled() const { return m_CollisionEnabled; }

	//error-> create a pure virtual function. This becomes abstract class. Object creation error
	
protected:
	Vec2 m_Veclocity;
	Vec2 m_Position;

	bool m_GravityEnabled;
	bool m_CollisionEnabled;
};

