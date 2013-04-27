#include <SFML/Graphics.hpp>

#include "Resources.hpp"

const sf::Vector2u windowSize( 800, 600 );

int main( int argc, char **argv )
{
	sf::RenderWindow app( sf::VideoMode( windowSize.x, windowSize.y , 32 ), "SCCT" );
	app.setVerticalSyncEnabled( true );

	scct::ResourceManager<sf::Texture> rm;

	sf::Sprite sprite( *rm.get( scct::fromFile<sf::Texture>( "testsfml.png" ) ) );
	sprite.setOrigin( static_cast< sf::Vector2f >( sprite.getTexture()->getSize() ) / 2.f );
	sprite.setPosition( static_cast<sf::Vector2f>( windowSize ) / 2.f );

	while( app.isOpen() ){
		sf::Event event;
		while( app.pollEvent( event ) ){
			if( event.type == sf::Event::Closed ){
				app.close();
			}
		}

		app.clear();

		app.draw( sprite );

		app.display();
	}
}

