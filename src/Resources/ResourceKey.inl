//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

namespace scct
{

template <typename T>
ResourceKey<T>::ResourceKey( Loader loader, std::string id ) :
	m_loader( loader ),
	m_id( id )
{
}

template <typename T>
std::shared_ptr<T> ResourceKey<T>::load() const
{
	return m_loader();
}

template <typename T>
std::string ResourceKey<T>::getId() const
{
	return m_id;
}

} // namespace scct
