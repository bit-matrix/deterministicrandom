//
//  Bytestring.hpp
//  sha256context
//
//  Created by Burak on 16.08.2022.
//

#ifndef Bytestring_hpp
#define Bytestring_hpp

#include <stdio.h>
#include <string>
#include <sstream>

class ByteString{
private:
    std::string setString;
public:
    ByteString(std::string);
    std::string fromHexString();
};

#endif /* Bytestring_hpp */
