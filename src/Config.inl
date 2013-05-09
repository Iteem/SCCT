//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

namespace scct
{

template<typename T>
T Config::getValue( std::string key, T defaultValue ) const
{
	T value;
	std::stringstream stream;
	stream << getStringValue(key);
	stream >> value;

	if(stream.fail()){
		std::cerr << "Warning: Failed to cast to the requested type from key " << key << "." << std::endl;
		return defaultValue;
	}

	return value;
}

template<typename T>
bool Config::setValue( std::string key, const T &value )
{
	std::stringstream stream;
	std::string str;
	stream << value;
	stream >> str;

	if(stream.fail()){
		std::cerr << "Warning: Failed to set value of key " << key << "." << std::endl;
		return false;
	}

	setStringValue(key, str);
	return true;
}

} // namespace scct
