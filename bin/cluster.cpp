
#include <string>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {

  // cat chr pstart pend readID distance | cluster maxdistance
  
  int pend;
  int pstart;
  int distance;
  int maxdistance = atoi(argv[1]);
  
  std::string chr;
  std::string readID;
  std::string chr_cache = "start";

  int c = 0;
  int i = 0;
  int end_cache;
  
  while (std::cin >> chr >> pstart >> pend >> readID >> distance) {
    if (i == 0) { end_cache = pstart; }
    
    if (chr_cache == chr || chr_cache == "start") {
      if (distance <= maxdistance) {
	if (pstart - end_cache > maxdistance) { c++; }
	std::cout << chr << " " << pstart << " " << pend << " " << readID << " " << distance << " " << c << std::endl;
      } 
    } else {
      
      if (distance <= maxdistance) {
	c++;
	std::cout << chr << " " << pstart << " " << pend << " " << readID << " " << distance << " " << c << std::endl;
      }
    }
    end_cache = pend;
    chr_cache = chr;
    i++;
  }  
  return 0;
}
