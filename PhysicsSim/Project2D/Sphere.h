#pragma once
#include "glm/glm.hpp"
#include "RigidBody.h"


class Sphere : public Rigidbody
{
public:
    Sphere(glm::vec2 position, glm::vec2 velocity,
        float mass, float radius, glm::vec4 colour);
    ~Sphere();

    virtual void draw();
    virtual void debugDraw(aie::Renderer2D* renderer) override;

    float getRadius() { return m_radius; }
    glm::vec4 getColour() { return m_colour; }

protected:
    float m_radius;
    glm::vec4 m_colour;
};

