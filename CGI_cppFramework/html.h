#ifndef HTML_H 
#define HTML_H

#include <map>
#include <string>
#include <vector>

namespace HTML
{
	std::string toAttributesString( const std::map< std::string, std::string> &attributes );

	std::string html( const std::string &head, const std::string &body,
					  const std::map< std::string, std::string> &attributes = std::map<std::string, std::string>{} );
	std::string head( const std::vector<std::string> &headerData, const std::map< std::string, std::string> &attributes = std::map<std::string, std::string>{} );
	std::string title( const std::string &_title, const std::map< std::string, std::string> &attributes = std::map<std::string, std::string>{} );
	std::string metaCharset( const std::string &charset );
	std::string meta( const std::string &name, const std::string &content );
	std::string link( const std::map< std::string, std::string> &attributes );
	std::string style( const std::string &content );

	std::string body( const std::string &content, const std::map< std::string, std::string> &attributes = std::map<std::string, std::string>{} );
	
	std::string singleElement( const std::string &tag, const std::map< std::string, std::string> &attributes = std::map<std::string, std::string>{} );
	std::string pairedElement( const std::string &tag, const std::string &content, const std::map< std::string, std::string> &attributes = std::map<std::string, std::string>{} );
}

#endif // HTML_H
