#ifndef LOADERS_HPP_INCLUDED
#define LOADERS_HPP_INCLUDED

#include "ResourceKey.hpp"

#include <string>
#include <functional>
#include <memory>

namespace scct
{

template <typename T, typename Fn>
std::function< std::shared_ptr<T>() > convertLoader( Fn boolLoader )
{
	return [=]() -> std::shared_ptr<T>
	{
		std::shared_ptr<T> res( new T() );

		if( boolLoader(*res) ){
			return res;
		}
		else {
			return nullptr;
		}
	};
}

template <typename T>
ResourceKey<T> fromFile( const std::string& path )
{
	return ResourceKey<T>( convertLoader<T>( [=](T& res){ return res.loadFromFile( path ); } ),
						   path );
}

template <typename T, typename U>
ResourceKey<T> fromFile( const std::string& path, U arg1 )
{
	return ResourceKey<T>( convertLoader<T>( [=](T& res){ return res.loadFromFile( path, arg1 ); } ),
						   path );
}

template <typename T, typename U, typename V>
ResourceKey<T> fromMemory( const std::string &id, U arg1, U arg2 )
{
	return ResourceKey<T>( convertLoader<T>( [=](T& res){ return res.loadFromMemory( arg1, arg2 ); } ),
						   id );
}

template <typename T, typename U, typename V, typename W>
ResourceKey<T> fromMemory( const std::string &id, U arg1, U arg2, W arg3 )
{
	return ResourceKey<T>( convertLoader<T>( [=](T& res){ return res.loadFromMemory( arg1, arg2, arg3 ); } ),
						   id );
}


} // namespace scct

#endif // LOADERS_HPP_INCLUDED
