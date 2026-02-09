#include "RigidBody.h"
#include "PhysicsScene.h"

void Rigidbody::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	m_position += m_velocity * timeStep; // position is added by velocity over time - movement is always updated
	applyForce(gravity * m_mass * timeStep); // gravity always applies force
}

void Rigidbody::applyForce(glm::vec2 force)
{
	// a = F/m
	glm::vec2 acc = force / m_mass;
	// increase velocity by acceleration
	m_velocity += acc;
}

void Rigidbody::applyForceFromOther(Rigidbody* other, glm::vec2 force)
{
	applyForce(force);
	other->applyForce(-force);
}
