//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Config.hpp"
#include "Resources.hpp"

const sf::Vector2u windowSize( 800, 600 );

int main( int argc, char **argv )
{
	scct::Config config;
	if( !config.loadFromFile( "game.ini" ) ){
		std::cerr << "Failed to load game.ini." << std::endl;
		return 1;
	}

	sf::RenderWindow app( sf::VideoMode( windowSize.x, windowSize.y , 32 ), "SCCT" );
	app.setVerticalSyncEnabled( true );

	scct::ResourceManager<sf::Texture> rm;
	std::string logoPath = config.getStringValue( "sfml-logo" );

	sf::Sprite sprite;
	try {
		sprite.setTexture( *rm.get( scct::fromFile<sf::Texture>( logoPath ) ) );
		sprite.setOrigin( static_cast< sf::Vector2f >( sprite.getTexture()->getSize() ) / 2.f );
		sprite.setPosition( static_cast<sf::Vector2f>( windowSize ) / 2.f );
	} catch ( std::runtime_error &e ) {
		std::cerr << e.what();
	}

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
