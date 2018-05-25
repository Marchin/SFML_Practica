#include <SFML/Graphics.hpp>
#include "Shot\ShotPool.h"

namespace player {
	class Player : public sf::Drawable{
	public:
		Player(const sf::Vector2f& position, const sf::View* pView);
		~Player();
		void SetColor(const sf::Color& color);
		void Rotate(const float& angle,const float& deltaTime = 1.f);
		void Fire();
		void UpdateShots(
			const std::array<sf::Sprite, 0>& obstacles,
			const float& deltaTime = 1.f);
		float Width() const;
		float Height() const;
	private:
		virtual void draw(sf::RenderTarget& target, 
						  sf::RenderStates states) const;
		shotSys::ShotPool* m_ammo;
		sf::Texture m_texture;
		sf::Sprite m_sprite;
		sf::Color m_color;
		const sf::View* m_pView;
		std::array<sf::Sprite, AMMO_AMOUNT> shotSprites;
	};
}