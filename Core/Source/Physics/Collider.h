#pragma once

#include "PhysicsObject.h"
#include "Shape.h"

class Collider : public PhysicsObject
{
public:
	Collider(Vec2 theVelocity, Vec2 thePosition,
            bool theGravityEnabled, bool theCollisionEnabled, Shape theShape);
	/**
	 * 
	 * @param  Collider theOther  
	 * @return bool               
	 */
	bool Intersects(const Collider& theOther) const;
	/**
	 * 
	 * @param  Collider theFirst                
	 * @param  Collider theSecond               
	 * @param  f32 theCoefficientOfRestitution  
	 */
	static void ResolveCollision(Collider& theFirst, Collider& theSecond, f32 theCoefficientOfRestitution=1.0f);

    Shape m_Shape;
private:

	// All these assume Circles and Rectangles are of unit height and width

	bool intersectCircleCircle(const Collider& theFirst, const Collider& theSecond) const;
};

