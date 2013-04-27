//Copyright (c) 2013 Patrick Winkler (iteem7777@gmail.com)
//This work is free. You can redistribute it and/or modify it under the
//terms of the Do What The Fuck You Want To Public License, Version 2,
//as published by Sam Hocevar. See the COPYING file for more details.

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
