
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

struct Fasta {
  std::string name;
  std::string seq;
  std::string::size_type nseq;
};

int main(int argc, char *argv[]) {

  Fasta Fsa;
  std::string line;
  std::ifstream infile(argv[1]);

  // ./cinv <fasta.fa> <chr> <start> <end>

  std::string contig = argv[2];
  std::string::size_type begin = atoi(argv[3]);
  std::string::size_type end = atoi(argv[4]);

  std::string one;
  std::string two;
  std::string three;

  Fsa.nseq = 0;  
  while (std::getline(infile, line)) {

    if (line.rfind(">", 0) == 0) {
      
      if (Fsa.nseq > 0) {
	
	if (Fsa.name.substr(1, Fsa.name.size() - 1) == contig) {
	  one = Fsa.seq.substr(0, begin);
	  two = Fsa.seq.substr(begin, end - begin);
	  std::reverse(two.begin(), two.end());
	  three = Fsa.seq.substr(end, Fsa.seq.size() - end);
	  
	  std::cout << Fsa.name << '\n' << one <<  two  << three << std::endl;
	} else {
	  std::cout << Fsa.name << '\n' << Fsa.seq << std::endl;
	}
      }
      
      Fsa.name = line;
      Fsa.seq = "";
      Fsa.nseq++;
      
    } else { Fsa.seq += line; }
  }

  if (Fsa.name.substr(1, Fsa.name.size() - 1) == contig) {
    one = Fsa.seq.substr(0, begin);
    two = Fsa.seq.substr(begin, end - begin);
    std::reverse(two.begin(), two.end());
    three = Fsa.seq.substr(end, Fsa.seq.size() - end);
    
    std::cout << Fsa.name << '\n' << one <<  two  << three << std::endl;
  } else {
    std::cout << Fsa.name << '\n' << Fsa.seq << std::endl;
  }
  
  return 0;
}
