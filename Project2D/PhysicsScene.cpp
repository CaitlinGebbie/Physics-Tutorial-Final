#include "PhysicsScene.h"

#include <algorithm>

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0, 0))
{
}

void PhysicsScene::removeActor(PhysicsObject* actor)
{
    it = find(m_actors.begin(), m_actors.end(), actor);
    if (it != m_actors.end())
    {
        it = m_actors.erase(it);
    }
}

void PhysicsScene::update(float dt)
{
    // update physics at a fixed time step

    static float accumulatedTime = 0.0f;
    accumulatedTime += dt;

    while (accumulatedTime >= m_timeStep)
    {
        for (auto pActor : m_actors)
        {
            pActor->fixedUpdate(m_gravity, m_timeStep);
        }

        accumulatedTime -= m_timeStep;
    }
}

void PhysicsScene::draw()
{
    for (auto pActor : m_actors) {
        pActor->draw();
    }
}