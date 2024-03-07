#include "Collider.h"
#include <iostream>

Collider::Collider(Vec2 theVelocity, Vec2 thePosition, bool theGravityEnabled, bool theCollisionEnabled, Shape theShape)
	: PhysicsObject(theVelocity, thePosition, theGravityEnabled, theCollisionEnabled), m_Shape(theShape) {}


bool Collider::Intersects(const Collider& theOther) const
{
	if (this->m_Shape.GetType() == Shape::Type::Circle &&
            theOther.m_Shape.GetType() == Shape::Type::Circle)
		return intersectCircleCircle(*this, theOther);
	return false; // For unsupported type
}

void Collider::ResolveCollision(Collider& theFirst, Collider& theSecond, f32 theCoefficientOfRestitution=1.0f)
{// Assuming unit mass

	if (theFirst.IsCollisionEnabled() && theSecond.IsCollisionEnabled())
	{
		if (theFirst.Intersects(theSecond))
		{

			Vec2 aRelativeVelocity = theFirst.GetVelocity() - theSecond.GetVelocity();
			Vec2 aUnitNormal = theFirst.GetPosition() - theSecond.GetPosition();

			aUnitNormal.Normalize();

			f32 aImpulse = -(1 + theCoefficientOfRestitution) *
				(aRelativeVelocity.GetX() * aUnitNormal.GetX() + aRelativeVelocity.GetY() * aUnitNormal.GetY());

			theFirst.GetVelocity().SetX(theFirst.GetVelocity().GetX() +
				(aImpulse * aUnitNormal.GetX()));
			theFirst.GetVelocity().SetY(theFirst.GetVelocity().GetY() +
				(aImpulse * aUnitNormal.GetY()));

			theSecond.GetVelocity().SetX(theSecond.GetVelocity().GetX() -
				(aImpulse * aUnitNormal.GetX()));
			theSecond.GetVelocity().SetY(theSecond.GetVelocity().GetY() -
				(aImpulse * aUnitNormal.GetY()));
		}

	}
}


bool Collider::intersectCircleCircle(const Collider& theFirst, const Collider& theSecond) const
{
    f32 dist = SQ(theFirst.GetPosition().GetX() - theSecond.GetPosition().GetX()) + SQ(theFirst.GetPosition().GetY() - theSecond.GetPosition().GetY());
    // std::cout << dist << std::endl;
	return dist < 1;
}

