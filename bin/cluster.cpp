
#include <string>
#include <iostream>

int main() {

  int pend;
  int pstart;
  int distance;
  int maxdistance = 500;
  
  std::string chr;
  std::string readID;
  std::string chr_cache = "start";

  int c = 0;
  int i = 0;
  int end_cache;
  
  while (std::cin >> chr >> pstart >> pend >> readID >> distance) {
    if (i == 0) { end_cache = pstart; }
    
    if (chr_cache == chr || chr_cache == "start") {
      if (distance <= 500) {
	if (pstart - end_cache > 500) { c++; }
	std::cout << chr << " " << pstart << " " << pend << " " << readID << " " << distance << " " << c << std::endl;
      } 
    } else {
	c++;
	if (distance <= 500) {
	  std::cout << chr << " " << pstart << " " << pend << " " << readID << " " << distance << " " << c << std::endl;
	}
    }
    end_cache = pend;
    chr_cache = chr;
    i++;
  }  
  return 0;
}
