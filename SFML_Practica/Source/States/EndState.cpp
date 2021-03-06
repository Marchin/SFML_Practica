#include "States/EndState.h"
#include "States/StartState.h"
#include "ColorExtension.h"

namespace state {

EndState::EndState(sf::RenderWindow* window, const sf::Time* elapsed) :
	m_pWindow(window), m_pTime(elapsed), m_FLICK_INTERVAL(0.75f), 
	m_counter(m_FLICK_INTERVAL), m_enableControlCounter(1.5f) {

	if (!m_font.loadFromFile("Resources/8-BIT WONDER.TTF")) {
		printf("Error: Font could not be loaded");
	}
	if (!m_loseSound.loadFromFile("Resources/Lose.wav")) {
		printf("Error: Lose sound not found");
	}
	m_soundPlayer.setBuffer(m_loseSound);
	m_soundPlayer.play();
	m_gameOverText.setStyle(sf::Text::Bold);
	m_gameOverText.setFont(m_font);
	m_gameOverText.setString("GAME OVER");
	m_gameOverText.setCharacterSize(8);
	sf::Vector2f centerText(window->getView().getSize().x / 2.f,
		window->getView().getSize().y / 2.f);
	centerText.x -= m_gameOverText.getLocalBounds().width * 0.5f;
	centerText.y -= m_gameOverText.getLocalBounds().height * 0.5f;
	m_gameOverText.setPosition(centerText);
}

EndState::~EndState() {
}

void EndState::Update(IState** pNextState, bool& exitGame){
	if (m_counter <= 0.f) {
		if (m_gameOverText.getFillColor().a == 0.f) {
			m_gameOverText.setFillColor(color::Opaque(m_gameOverText.getFillColor()));
		}
		else {
			m_gameOverText.setFillColor(color::Transparent(m_gameOverText.getFillColor()));
		}
		m_counter = m_FLICK_INTERVAL;
	}
	m_counter -= m_pTime->asSeconds();
	m_pWindow->draw(m_gameOverText);
	if (m_enableControlCounter < 0.f) {
		CheckInput();
	} else {
		m_enableControlCounter -= m_pTime->asSeconds();
	}
	if (m_endController.Confirm()) {
		*pNextState = new StartState(m_pWindow, m_pTime);
	}
}

void EndState::CheckInput() {
	m_endController.UpdateKeys();
}

}