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
