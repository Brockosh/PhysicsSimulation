#pragma once
#include "glm/glm.hpp"
#include "PhysicsObject.h"

class Rigidbody : public PhysicsObject 
{
public:
    Rigidbody(ShapeType shapeID, glm::vec2 position,
        glm::vec2 velocity, float orientation, float mass);
    ~Rigidbody();

    virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
    void applyForce(glm::vec2 force);
    void applyForceToActor(Rigidbody* actor2, glm::vec2 force);

    glm::vec2 getPosition() { return m_position; }
    float getOrientatation() { return m_orientation; }
    glm::vec2 getVelocity() { return m_velocity; }

    void setVelocity(glm::vec2 newVelocity) { m_velocity = newVelocity; }
    float getMass() { return m_mass; }
    void resolveCollision(Rigidbody* actor2);
protected:
    glm::vec2 m_position;
    glm::vec2 m_velocity;
    float m_mass;
    float m_orientation;    //2D so we only need a single float to represent our orientation
};

