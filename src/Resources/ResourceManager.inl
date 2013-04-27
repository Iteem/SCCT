//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

#include <stdexcept>

namespace scct
{

template <typename T>
ResourceManager<T>::ResourceManager()
{
}

template <typename T>
std::shared_ptr<T> ResourceManager<T>::get( const ResourceKey<T>& key )
{
	auto it = m_map.find( key.getId() );

	if( it != m_map.end() )
		return it->second;

	std::shared_ptr<T> res( key.load() );
	if(!res){
		throw std::runtime_error( "Could not load resource \"" + key.getId() + "\"");
	}

	return m_map.insert( std::make_pair( key.getId(), res ) ).first->second;

}

template <typename T>
void ResourceManager<T>::release( std::string& id )
{
	m_map.erase( id );
}

} // namespace scct
