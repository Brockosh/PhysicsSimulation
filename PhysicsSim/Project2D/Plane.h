#pragma once
#include "PhysicsObject.h"

class Plane : public PhysicsObject
{
public:
    Plane(glm::vec2 normal, float distance, glm::vec4 colour);
    ~Plane();

    virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
    virtual void draw();
    virtual void debugDraw(aie::Renderer2D* renderer) override;

    virtual void resetPosition();

    glm::vec2 getNormal() { return m_normal; }
    float getDistance() { return m_distanceToOrigin; }

protected:
    glm::vec4 m_colour;
    glm::vec2 m_normal;
    float m_distanceToOrigin;
};


