#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "PhysicsObject.h"

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor) { m_actors.push_back(actor); }
	void removeActor(PhysicsObject* actor);

	void update(float dt);
	void draw();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 getGravity() const { return m_gravity; }

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() const { return m_timeStep; }

protected:
	glm::vec2 m_gravity = { 0, 0 };
	float m_timeStep = 0.01f;
	std::vector<PhysicsObject*> m_actors;
	std::vector<PhysicsObject*>::iterator it;
};
