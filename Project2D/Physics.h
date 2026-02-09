#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Physics : public aie::Application {
public:

	Physics();
	virtual ~Physics();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;

	float m_timer;
};