#include "html.h"

#include <sstream>

namespace HTML
{
	std::string toAttributesString( const std::map< std::string, std::string> &attributes )
	{
		std::string attributesString{};

		for( const auto &keyVal : attributes )
		{
			attributesString += " " + keyVal.first + "=\"" + keyVal.second + "\"";
		}

		return attributesString;
	}

	std::string html( const std::string &head, const std::string &body,
					  const std::map<std::string, std::string> &attributes )
	{
		return "<!DOCTYPE html>\n<html" + toAttributesString( attributes ) 
			+ ">\n" + head + "\n" + body + "</html>\n\n";
	}

	std::string title( const std::string & _title, const std::map< std::string, std::string> &attributes )
	{
		return "      <title" + toAttributesString( attributes ) 
			+ ">" + _title + "</title>\n";
	}

	std::string metaCharset( const std::string &charset )
	{
		return "      <meta charset=\"" + charset + "\">\n";
	}

	std::string meta( const std::string &name, const std::string &content )
	{
		return "      <meta name=\"" + name + "\" content=\"" + content + "\">\n";
	}

	std::string link( const std::map< std::string, std::string> &attributes )
	{
		return "      <link" + toAttributesString( attributes ) + " />\n";
	}

	std::string style( const std::string &content )
	{
		return "      <style>\n" + content + "\n      </style>";
	}

	std::string head( const std::vector<std::string> &headerData, const std::map< std::string, std::string> &attributes )
	{
		std::string head( "   <head" + toAttributesString( attributes ) + ">\n" );

		for( const auto &header : headerData )
		{
			head += header;
		}

		head += "   </head>\n";

		return head;
	}

	std::string body( const std::string &content, const std::map< std::string, std::string> &attributes )
	{
		return "   <body" + toAttributesString( attributes ) + ">\n" + content + "   </body>\n\n";
	}

	std::string singleElement( const std::string &tag, const std::map< std::string, std::string> &attributes )
	{
		return "      <" + tag + toAttributesString( attributes ) + ">\n\n";
	}

	std::string pairedElement( const std::string &tag, const std::string &content, 
							  const std::map< std::string, std::string> &attributes )

	{
		return "      <" + tag + toAttributesString( attributes ) + ">" + content + "</" + tag + ">\n\n";
	}
}
