#ifndef END_STATE_H
#define END_STATE_H

#include "IState.h"
#include "Controllers/EndController.h"

namespace state {

class EndState : public IState {
public:
	EndState(sf::RenderWindow* window, const sf::Time* elapsed);
	~EndState();
	void Update(IState** pNextState, bool& exitGame) override;
private:
	void CheckInput();
	sf::RenderWindow* m_pWindow;
	const sf::Time* const m_pTime;
	input::EndController m_endController;
	sf::Font m_font;
	sf::Text m_gameOverText;
	const float m_flickInterval;
	float m_counter;
};

}

#endif // !END_STATE_H
