#include "Sphere.h"
#include "Gizmos.h"

Sphere::Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour) :
    Rigidbody(SPHERE, position, velocity, 0, mass)
{
    m_radius = radius;
    m_colour = colour;
}

Sphere::~Sphere()
{
}

void Sphere::draw()
{
    int segments = 14;
    aie::Gizmos::add2DCircle(m_position, m_radius, segments, m_colour);
    //glm::vec2 endPos = m_position + m_velocity;
    //aie::Gizmos::add2DLine(m_position, endPos, glm::vec4(0, 1, 0, 1));
 
}

void Sphere::debugDraw(aie::Renderer2D* renderer)
{
    //int segments = 14;
    //aie::Gizmos::add2DCircle(m_position, m_radius, segments, m_colour);
    glm::vec2 endPos = m_position + m_velocity; 
    aie::Gizmos::add2DLine(m_position, endPos, glm::vec4(0, 1, 0, 1));
}
