//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED

#include "NonCopyable.hpp"

#include <string>
#include <map>
#include <sstream>
#include <iostream>

namespace scct
{

/// Class to read and write INI files
class Config : public NonCopyable
{
    public:
        Config();
        ~Config();

        bool loadFromFile( const std::string &path );

        bool saveToFile( const std::string &path ) const;

        std::string getStringValue( const std::string &key ) const;

		void setStringValue( const std::string &key, const std::string &value );

        // returns value converted to type T
		template<typename T>
		T getValue( std::string key, T defaultValue = T() ) const;

		// saves value to the config, returns false in case of failure
		template<typename T>
		bool setValue( std::string key, const T &value );

    private:
		typedef std::map<std::string, std::string> StringMap;
        StringMap m_map;
};

} // namespace scct

#include "Config.inl"

#endif // CONFIG_HPP_INCLUDED
