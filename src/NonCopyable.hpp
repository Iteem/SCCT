#ifndef NONCOPYABLE_HPP_INCLUDED
#define NONCOPYABLE_HPP_INCLUDED

namespace scct
{

/// A class to derive from, to prevent copying of your class.
class NonCopyable
{
	protected:
		// Default constructor
		NonCopyable() {}
		~NonCopyable() {}

	private:
		// Copy constructor
		NonCopyable(const NonCopyable& origin);

		// Assignment operator
		NonCopyable&	operator= (const NonCopyable& origin);
};

} // namespace scct

#endif // NONCOPYABLE_HPP_INCLUDED
