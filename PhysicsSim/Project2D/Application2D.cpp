#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "glm/ext.hpp"
#include <Gizmos.h>
#include "PhysicsScene.h"
#include "Sphere.h"
#include "Plane.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

//bool Application2D::startup() {
//	
//	m_2dRenderer = new aie::Renderer2D();
//
//	m_texture = new aie::Texture("./textures/numbered_grid.tga");
//	m_shipTexture = new aie::Texture("./textures/ship.png");
//
//	m_font = new aie::Font("./font/consolas.ttf", 32);
//	
//	m_timer = 0; 
//
//	return true;
//}

void Application2D::shutdown() {
	
	delete m_font;
	//delete m_texture;
	//delete m_shipTexture;
	delete m_2dRenderer;
}

//void Application2D::update(float deltaTime) {
//
//	m_timer += deltaTime;
//
//	// input example
//	aie::Input* input = aie::Input::getInstance();
//
//	// Update the camera position using the arrow keys
//	float camPosX;
//	float camPosY;
//	m_2dRenderer->getCameraPos(camPosX, camPosY);
//
//	if (input->isKeyDown(aie::INPUT_KEY_UP))
//		camPosY += 500.0f * deltaTime;
//
//	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
//		camPosY -= 500.0f * deltaTime;
//
//	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
//		camPosX -= 500.0f * deltaTime;
//
//	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
//		camPosX += 500.0f * deltaTime;
//
//	m_2dRenderer->setCameraPos(camPosX, camPosY);
//
//	// exit the application
//	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
//		quit();
//}

//void Application2D::draw() {
//
//	// wipe the screen to the background colour
//	clearScreen();
//
//	// begin drawing sprites
//	m_2dRenderer->begin();
//
//	// demonstrate animation
//	m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
//	m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);
//
//	// demonstrate spinning sprite
//	m_2dRenderer->setUVRect(0,0,1,1);
//	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);
//
//	// draw a thin line
//	m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);
//
//	// draw a moving purple circle
//	m_2dRenderer->setRenderColour(1, 0, 1, 1);
//	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);
//
//	// draw a rotating red box
//	m_2dRenderer->setRenderColour(1, 0, 0, 1);
//	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);
//
//	// draw a slightly rotated sprite with no texture, coloured yellow
//	m_2dRenderer->setRenderColour(1, 1, 0, 1);
//	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
//	
//	// output some text, uses the last used colour
//	char fps[32];
//	sprintf_s(fps, 32, "FPS: %i", getFPS());
//	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
//	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
//
//	// done drawing sprites
//	m_2dRenderer->end();
//}

//bool Application2D::startup() {
//	// increase the 2d line count to maximize the number of objects we can draw
//	aie::Gizmos::create(255U, 255U, 65535U, 65535U);
//
//	m_2dRenderer = new aie::Renderer2D();
//	m_font = new aie::Font("./font/consolas.ttf", 32);
//
//	m_physicsScene = new PhysicsScene();
//	m_physicsScene->setTimeStep(0.01f);
//
//	//m_physicsScene->setGravity(glm::vec2(0, 0));  // turn off gravity
//
//	m_physicsScene->setGravity(glm::vec2(0, -9.82f));
//
//	Sphere* ball1 = new Sphere(glm::vec2(-20, 0), glm::vec2(0), 4.0f, 4, glm::vec4(1, 0, 0, 1));
//	Sphere* ball2 = new Sphere(glm::vec2(10, 0), glm::vec2(0), 4.0f, 4, glm::vec4(0, 1, 0, 1));
//	Plane* plane = new Plane(glm::vec2(0, 1), -30, glm::vec4(0, 1, 0, 1));
//
//	m_physicsScene->addActor(ball1);
//	m_physicsScene->addActor(ball2);
//	m_physicsScene->addActor(plane);
//
//	return true;
//}

bool Application2D::startup() {
	// Setup for Gizmos and renderer
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	// Create the physics scene
	m_physicsScene = new PhysicsScene();
	m_physicsScene->setTimeStep(0.001f);
	m_physicsScene->setGravity(glm::vec2(0, -9.82f)); // Gravity setup

	// Add planes representing walls
		// Top wall
	m_physicsScene->addActor(new Plane(glm::vec2(0, -1), -40, glm::vec4(1, 1, 1, 1)));
	// Bottom wall
	m_physicsScene->addActor(new Plane(glm::vec2(0, 1), -40, glm::vec4(1, 1, 1, 1)));
	// Left wall
	m_physicsScene->addActor(new Plane(glm::vec2(1, 0), -80, glm::vec4(1, 1, 1, 1)));
	// Right wall
	m_physicsScene->addActor(new Plane(glm::vec2(-1, 0), -80, glm::vec4(1, 1, 1, 1)));

	// Random initial direction for spheres
	float speed = 50;
	glm::vec2 initialVelocity1 = glm::circularRand(1.0f) * speed;
	glm::vec2 initialVelocity2 = glm::circularRand(1.0f) * speed;

	// Create spheres with random initial velocities
	Sphere* ball1 = new Sphere(glm::vec2(-20, 0), initialVelocity1, 4.0f, 4, glm::vec4(1, 0, 0, 1));
	Sphere* ball2 = new Sphere(glm::vec2(10, 0), initialVelocity2, 4.0f, 4, glm::vec4(0, 1, 0, 1));
	Sphere* ball3 = new Sphere(glm::vec2(-10, 0), initialVelocity2, 4.0f, 4, glm::vec4(1, 1, 0, 1));
	Sphere* ball4 = new Sphere(glm::vec2(20, 0), initialVelocity2, 4.0f, 4, glm::vec4(0, 1, 1, 1));

	// Add spheres to the physics scene
	m_physicsScene->addActor(ball1);
	m_physicsScene->addActor(ball2);
	m_physicsScene->addActor(ball3);
	m_physicsScene->addActor(ball4);

	

	return true;
}

//void Application2D::update(float deltaTime) {
//	// input example
//	aie::Input* input = aie::Input::getInstance();
//
//	aie::Gizmos::clear();
//
//	m_physicsScene->update(deltaTime);
//	m_physicsScene->draw();
//
//	// exit the application
//	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
//		quit();
//}

void Application2D::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();

	// Toggle debug mode on 'D' key press
	if (input->wasKeyPressed(aie::INPUT_KEY_D)) {
		m_debugMode = !m_debugMode;
	}

	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->draw();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

//void Application2D::draw() {
//	// wipe the screen to the background colour
//	clearScreen();
//
//	// begin drawing sprites
//	m_2dRenderer->begin();
//
//	// draw your stuff here!
//	static float aspectRatio = 16 / 9.f;
//	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));
//
//	// output some text, uses the last used colour
//	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
//	// done drawing sprites
//	m_2dRenderer->end();
//}

void Application2D::draw() {
	clearScreen();
	m_2dRenderer->begin();

	// Standard drawing code...
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));

	//// Conditional debug drawing
	//if (m_debugMode) {
	//	// Assuming you have a method to get all spheres or all objects and can distinguish them
	//	for (auto& object : m_physicsScene->getAllObjects()) {
	//		Sphere* sphere = dynamic_cast<Sphere*>(object);
	//		if (sphere) {
	//			sphere->debugDraw(m_2dRenderer);
	//		}
	//	}
	//}

	// Conditional debug drawing
	if (m_debugMode) {
		// Assuming m_physicsScene has a way to iterate over all physics objects
		for (auto& object : m_physicsScene->getAllObjects()) {
			object->debugDraw(m_2dRenderer);
		}
	}

	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->end();
}