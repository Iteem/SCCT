//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

#ifndef RESOURCEMANAGER_HPP_INCLUDED
#define RESOURCEMANAGER_HPP_INCLUDED

#include "../NonCopyable.hpp"
#include "ResourceKey.hpp"

#include <functional>
#include <memory>
#include <string>
#include <map>

namespace scct
{

template <typename T>
class ResourceManager : public NonCopyable
{
	public:
		ResourceManager();

		std::shared_ptr<T> get( const ResourceKey<T>& key );

		void release( std::string& id );

	private:
		typedef std::map< std::string, std::shared_ptr<T> > ResourceMap;

		ResourceMap m_map;
};


} // namespace scct

#include "ResourceManager.inl"

#endif // RESOURCEMANAGER_HPP_INCLUDED
