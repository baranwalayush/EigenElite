#pragma once

#include "PhysicsObject.h"
#include "Shape.h"

class Collider : public PhysicsObject
{
public:
	Collider(Vec2 theVelocity, Vec2 thePosition,
            bool theGravityEnabled, bool theCollisionEnabled, Shape theShape);

	bool Intersects(const Collider& theOther) const;

	static void ResolveCollision(Collider& theFirst, Collider& theSecond, f32 theCoefficientOfRestitution);

    Shape m_Shape;
private:

	// All these assume Circles and Rectangles are of unit height and width

	bool intersectCircleCircle(const Collider& theFirst, const Collider& theSecond) const;
};

