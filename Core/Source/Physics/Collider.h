#pragma once

#include "PhysicsObject.h"
#include "Shape.h"

class Collider : public PhysicsObject
{
public:
	Collider(Vec2 theVelocity, Vec2 thePosition, bool theGravityEnabled, bool theCollisionEnabled, Shape theShape);

	bool Intersects(const Collider& theOther);

private:
    Shape m_Shape;

	// All these assume Circles and Rectangles are of unit height and width

	bool intersectCircleCircle(const Collider& theFirst, const Collider& theSecond);
};

