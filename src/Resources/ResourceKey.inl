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
