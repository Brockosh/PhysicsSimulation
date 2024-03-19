#include "Plane.h"
#include "Gizmos.h"


Plane::Plane(glm::vec2 normal, float distance, glm::vec4 colour)
    : PhysicsObject(ShapeType::PLANE), m_normal(normal), m_distanceToOrigin(distance), m_colour(colour)
{
}

//Plane::Plane() : PhysicsObject(ShapeType::PLANE) {
//    m_distanceToOrigin = 0;
//    m_normal = glm::vec2(0, 1);
//}

// Destructor
Plane::~Plane()
{
}

void Plane::fixedUpdate(glm::vec2 gravity, float timeStep)
{
}

void Plane::draw()
{
    float lineSegmentLength = 300;
    glm::vec2 centerPoint = m_normal * m_distanceToOrigin;
    // easy to rotate normal through 90 degrees around z
    glm::vec2 parallel(m_normal.y, -m_normal.x);
    glm::vec4 colourFade = m_colour;
    colourFade.a = 0;
    glm::vec2 start = centerPoint + (parallel * lineSegmentLength);
    glm::vec2 end = centerPoint - (parallel * lineSegmentLength);
    //aie::Gizmos::add2DLine(start, end, colour);
    aie::Gizmos::add2DTri(start, end, start - m_normal * 10.0f, m_colour, m_colour, colourFade);
    aie::Gizmos::add2DTri(end, end - m_normal * 10.0f, start - m_normal * 10.0f, m_colour, colourFade, colourFade);
}

void Plane::debugDraw(aie::Renderer2D* renderer) {
    // Calculate the line segment ends for the plane
    float lineSegmentLength = 300; // Adjust based on your scene size
    glm::vec2 centerPoint = m_normal * m_distanceToOrigin;
    glm::vec2 parallel(m_normal.y, -m_normal.x); // Rotate the normal 90 degrees to get a parallel vector
    glm::vec2 start = centerPoint + (parallel * lineSegmentLength);
    glm::vec2 end = centerPoint - (parallel * lineSegmentLength);

    // Draw the line segment representing the plane
    renderer->setRenderColour(m_colour.r, m_colour.g, m_colour.b, m_colour.a);
    renderer->drawLine(start.x, start.y, end.x, end.y, 2.0f); // 2.0f is the line thickness

    // Draw the normal
    glm::vec2 midPoint = (start + end) * 0.5f; // Midpoint of the line segment
    glm::vec2 normalEnd = midPoint + m_normal * 10.0f; // Extend the normal out from the midpoint
    renderer->drawLine(midPoint.x, midPoint.y, normalEnd.x, normalEnd.y, 2.0f); // Draw the normal as a line

    // Optionally, draw an arrow head for the normal
    glm::vec2 normalPerpendicular(m_normal.y, -m_normal.x);
    glm::vec2 arrowLeft = normalEnd + normalPerpendicular * 5.0f - m_normal * 5.0f; // Adjust size as needed
    glm::vec2 arrowRight = normalEnd - normalPerpendicular * 5.0f - m_normal * 5.0f;
    renderer->drawLine(normalEnd.x, normalEnd.y, arrowLeft.x, arrowLeft.y, 2.0f);
    renderer->drawLine(normalEnd.x, normalEnd.y, arrowRight.x, arrowRight.y, 2.0f);

    // Reset render colour back to white
    renderer->setRenderColour(1, 1, 1, 1);
}


void Plane::resetPosition()
{
    // m_normal = glm::vec2(0, 1); // Reset to default normal
    // m_distanceToOrigin = 0.0f; // Reset distance to origin
}

