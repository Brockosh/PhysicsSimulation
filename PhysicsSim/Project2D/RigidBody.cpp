#include "RigidBody.h"

Rigidbody::Rigidbody(ShapeType shapeID, glm::vec2 position, 
                    glm::vec2 velocity, float orientation, float mass)

    : PhysicsObject(shapeID), // Initialize the base class member
        m_position(position),
        m_velocity(velocity),
        m_orientation(orientation),
        m_mass(mass)
{
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::fixedUpdate(glm::vec2 gravity, float timeStep)
{
    m_position += m_velocity * timeStep;
    applyForce(gravity * m_mass * timeStep);
}

void Rigidbody::applyForce(glm::vec2 force)
{
    //Calc acceleration
    glm::vec2 acceleration = force / m_mass;

    //Velocity = v+= a
    m_velocity += acceleration;
}

void Rigidbody::applyForceToActor(Rigidbody* actor2, glm::vec2 force)
{
    if (actor2)
    {
        actor2->applyForce(force);
        this->applyForce(-force);
    }
}
