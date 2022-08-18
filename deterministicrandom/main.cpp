//
//  main.cpp
//  deterministicrandom
//
//  Created by Burak on 18.08.2022.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "Bytestring.hpp"
#include "sha256.h"
#include "endian.h"

int deterministicrandom(int intMax, int intMin, std::string entropy){
    
    ByteString bs(entropy);
    std::string s1 = bs.fromHexString();
    
    std::vector<unsigned char> t1;
    t1.insert(t1.begin(), s1.begin(), s1.end());
    

    uint64_t nMax = (intMax - intMin);
    uint64_t nRange = (std::numeric_limits<uint64_t>::max() / nMax) * nMax;
    uint64_t nRand;
    
    
    std::vector<unsigned char> vchHash(32, 0);
    uint64_t nCounter = 0;
    int nHashIndex = 3;
    
    CSHA256 hasher;
    hasher.Write(t1.data(), t1.size());
    
    do {
        if (nHashIndex >= 3) {
            uint64_t le_counter = htole64(nCounter);
            CSHA256(hasher).Write((const unsigned char*)&le_counter, sizeof(nCounter)).Finalize(vchHash.data());
                nHashIndex = 0;
                nCounter++;
        }

            nRand = 0;
        for (size_t i=0; i<8; ++i)
                nRand |= ((uint64_t)vchHash[(nHashIndex*8) + i]) << (8*i);

                nHashIndex++;
        } while (nRand > nRange);
    
    int result(nRand % nMax);
    result += intMin;
    
    
    
    return result;
}

int main() {
    
    std::cout << deterministicrandom(7247,889,"523ee23d70f6cc76dfcc5d40ce8c963f169ad651715a93ddfc72ff8ece53aae9") << std::endl;
    
    return 0;
}
