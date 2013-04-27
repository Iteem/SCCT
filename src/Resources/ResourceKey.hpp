//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

#ifndef RESOURCEKEY_HPP_INCLUDED
#define RESOURCEKEY_HPP_INCLUDED

#include <functional>
#include <memory>
#include <string>

namespace scct
{

template <typename T>
class ResourceKey
{
	public:
		typedef std::function< std::shared_ptr<T>() > Loader;

		ResourceKey( Loader loader, std::string id );

		std::shared_ptr<T> load() const;

		std::string getId() const;

	private:
		Loader m_loader;
		std::string m_id;
};

} // namespace scct

#include "ResourceKey.inl"

#endif // RESOURCEKEY_HPP_INCLUDED
