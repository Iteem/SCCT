//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

#include "Config.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>

namespace scct
{

Config::Config()
{
}

Config::~Config()
{
}

bool Config::loadFromFile( const std::string &path )
{
    std::ifstream file( path.c_str() );
    if( !file.good() ){
        std::cerr << "Failed to open file \"" << path << "\"." << std::endl;
        return false;
    }

    // delete all old values and keys
    m_map.clear();

    std::string str;
    unsigned int linenum = 0;
    while( std::getline(file, str) ){
        linenum++;

        // skip comments and empty lines
        if( str.empty() || str[0] == ';' ){
            continue;
        }

        size_t pos = str.find( '=' );
        if( pos == std::string::npos ){
            std::cerr << path << " " << linenum << ": Equality sign missing." << std::endl;
            continue;
        }

		// get key/value pair
        std::string key( str.substr(0, pos) );
        std::transform( key.begin(), key.end(), key.begin(), tolower );
        std::string value( str.substr(pos+1) );

        if( key.empty() ){
            std::cerr << path << " " << linenum << ": Key missing." << std::endl;
            continue;
        }
        if( value.empty() ){
            std::cerr << path << " " << linenum << ": Value missing." << std::endl;
            continue;
        }

        // add the element to the map
        m_map[key] = value;
    }

    return true;
}

bool Config::saveToFile( const std::string &path ) const
{
	std::string tmpPath( path + ".tmp" );

	std::ifstream oldFile( path.c_str() );
	std::ofstream newFile( tmpPath.c_str() );

	StringMap tmpMap( m_map );

    if( oldFile.good() ){
		std::string str;
		unsigned int linenum = 0;
		while( oldFile.good() ){
			if( linenum > 0 )
				newFile << std::endl;

			std::getline(oldFile, str);
			linenum++;

			// leave comments and empty lines
			if( str[0] == ';' || str.empty() ){
				newFile << str;
				continue;
			}

			// find pairs and update them
			size_t pos = str.find('=');
			if( pos == std::string::npos ){
				newFile << str;
				continue;
			}
			std::string key( str.substr(0, pos) );

			// check for invalide lines and delete them
			if( key.empty() ){
				continue;
			}

			std::string value = getStringValue(key);
			// delete lines with no values set as well
			if( value.empty() ) {
				continue;
			}

			// write valid key/value pair to the file
			newFile << key << "=" << getStringValue(key);

			// erase updated pair from the map
			tmpMap.erase(key);
		}
    }
    else {
        std::cerr << "Failed to open file \"" << path << "\"." << std::endl;
    }

	// write new key/value pairs to the end of the file
	for( auto it = tmpMap.cbegin(); it != tmpMap.cend(); ++it ){
		newFile << std::endl << it->first << "=" << it->second;
	}

	oldFile.close();
	newFile.close();

	// replace the old file with the new one
	std::remove( path.c_str() );
	std::rename( tmpPath.c_str(), path.c_str() );

	return true;
}

std::string Config::getStringValue( std::string key ) const
{
	std::transform( key.begin(), key.end(), key.begin(), tolower );
    std::map<std::string, std::string>::const_iterator it = m_map.find( key );
    if( it == m_map.end() ){
        std::cerr << "Warning: Value of " << key << " requested but not set." << std::endl;
        return ""; //value not found, return an empty string
    }
    else{
        return it->second;
    }
}

void Config::setStringValue( std::string key, const std::string &value )
{
	std::transform( key.begin(), key.end(), key.begin(), tolower );
	m_map[key] = value;
}

} // namespace scct
