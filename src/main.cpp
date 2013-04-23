#include <SFML/Graphics.hpp>

int main( int argc, char **argv )
{
	sf::RenderWindow app( sf::VideoMode( 800, 600, 32), "SCCT" );
	app.setVerticalSyncEnabled( true );

	while( app.isOpen() ){
		sf::Event event;
		while( app.pollEvent( event ) ){
			if( event.type == sf::Event::Closed ){
				app.close();
			}
		}

		app.clear();

		app.display();
	}
}

