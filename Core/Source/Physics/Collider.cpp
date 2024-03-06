#include "Collider.h"
#include <iostream>

Collider::Collider(Vec2 theVelocity, Vec2 thePosition, bool theGravityEnabled, bool theCollisionEnabled, Shape theShape)
	: PhysicsObject(theVelocity, thePosition, theGravityEnabled, theCollisionEnabled), m_Shape(theShape) {}


bool Collider::Intersects(const Collider& theOther)
{
	if (this->m_Shape.GetType() == Shape::Type::Circle &&
            theOther.m_Shape.GetType() == Shape::Type::Circle)
		return intersectCircleCircle(*this, theOther);
	return false; // For unsupported type
}


bool Collider::intersectCircleCircle(const Collider& theFirst, const Collider& theSecond)
{
    f32 dist = SQ(theFirst.GetPosition().GetX() - theSecond.GetPosition().GetX()) + SQ(theFirst.GetPosition().GetY() - theSecond.GetPosition().GetY());
    // std::cout << dist << std::endl;
	return dist < 1;
}

