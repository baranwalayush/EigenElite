#include "Collider.h"

Collider::Collider(Vec2 theVelocity, Vec2 thePosition, bool theGravityEnabled, bool theCollisionEnabled, Shape theShape)
	: PhysicsObject(theVelocity, thePosition, theGravityEnabled, theCollisionEnabled), m_Shape(theShape) {}


bool Collider::Intersects(const Collider& theOther)
{
	if (this->m_Shape.GetType() == Shape::Type::Circle && theOther.m_Shape.GetType() == Shape::Type::Circle)
		return intersectCircleCircle(*this, theOther);
	return false; // For unsupported type
}


bool Collider::intersectCircleCircle(const Collider& theFirst, const Collider& theSecond)
{
	return (SQ(theFirst.GetPosition().x - theSecond.GetPosition().x) + SQ(theFirst.GetPosition().y - theSecond.GetPosition().y)) < 1;
}

