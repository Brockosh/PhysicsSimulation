#pragma once
#include "glm/glm.hpp"
#include "Renderer2D.h"

enum ShapeType
{
    PLANE = 0,
    SPHERE,
    SHAPE_COUNT
};

class PhysicsObject
{
protected:
    PhysicsObject(ShapeType a_shapeID)
                : m_shapeID(a_shapeID) {}
    PhysicsObject() {}

public:
    virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
    virtual void draw() = 0;
    virtual void debugDraw(aie::Renderer2D* renderer) = 0;
    virtual void resetPosition() {};
    ShapeType getShapeID() const { return m_shapeID; }

protected:
    ShapeType m_shapeID;
};

