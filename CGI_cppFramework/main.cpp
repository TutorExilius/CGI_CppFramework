#include <iostream>
using std::cout;

#include "cgi.h"
#include "html.h"

int main()
{
	CGI cgi;

	// fill header
	std::vector<std::string> headerData{
		HTML::title( "From CGI Framework" ),
		HTML::metaCharset( "utf-8" ),
		HTML::meta( "author", "Tutor Exilius" ),
		HTML::meta( "keywords", "C++ CGI, Raspberry Pi, Tutor exilius, Twitch Community" ),
		HTML::link( {
			{ "rel", "stylesheet" },
			{ "type", "text/css" },
			{ "href", "http://exilius.de/format.css" },
			{ "media", "screen" },
					} )
	};

	// fill body
	const std::string head = HTML::head( headerData );

	std::string bodyContent = HTML::pairedElement( "p", "Test" );
	bodyContent += HTML::pairedElement( "p", "Hello World!", 
				{ { "style", "color: red; border: 1px solid blue;" } } );
	bodyContent += HTML::singleElement( "img", {
		{ "src", "http://exilius.de/img/banner.jpg"},
		{ "alt", "Exilius.de Banner" }
									   } );
	// Response with HTML Page
	const std::string body = HTML::body( bodyContent );
	cgi << HTML::html( head, body, { {"lang","de"} } );

	return 0;
}