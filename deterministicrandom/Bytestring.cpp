//
//  Bytestring.cpp
//  sha256context
//
//  Created by Burak on 16.08.2022.
//

#include "Bytestring.hpp"



ByteString::ByteString(std::string in){
    setString = in;
}

std::string ByteString::fromHexString(){
    
    std::stringstream ss;

    for (int i=0; i < setString.size()/2; i++) {

        std::stringstream icat;
        icat << setString[i*2] << setString[i*2+1];

        std::string icatstr = icat.str();

        unsigned char hexNumber;

        sscanf(icatstr.c_str(), "%x", &hexNumber);
        ss << hexNumber;
    }

    return ss.str();
}
