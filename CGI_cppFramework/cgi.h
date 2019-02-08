#ifndef CGI_H
#define CGI_H

#include <iostream>
#include <string>
#include <ostream>

class CGI
{
public:
	CGI( std::ostream& o = std::cout )
	: out{ o }
	{
	}

	bool first = true;
	std::ostream& out;

	CGI& operator<<( const std::string& str )
	{
		if( first )
		{
			out << "Content-type: text/html\n\n";
			first = false;
		}
		out << str;
		return *this;
	}
};

#endif // CGI_H