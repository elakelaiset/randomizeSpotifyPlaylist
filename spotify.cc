#include <algorithm> // for copy() and assign()
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Function to plot a vector
template <typename T>
void display(std::vector<T> m) {
  size_t N = m.size();
  std::cout << "Vector length: " << N << std::endl;
  // display array elements
  for (unsigned int i = 0; i < N; ++i) {
    std::cout << "#" << i + 1 << ": " << m[i] << std::endl;
  };
}

// Function to randomize the element order of a vector
template <typename T>
void randomzeVector(std::vector<T> &inputVector)
{
  size_t N = inputVector.size(), NT = N;
  std::vector<T> tempVector;
  int randomInteger;
  std::copy(inputVector.begin(), inputVector.end(), back_inserter(tempVector));

  // defining the seed for random number generator
  std::srand((unsigned) std::time(0));

  for (unsigned int i = 0; i < N; ++i) {
    // acces random element of tempVector and assign it to the
    // the ith position of inputVector
    randomInteger = std::rand() % NT;
    inputVector[i]= tempVector[randomInteger];
    // delete random element within the tempVector
    tempVector.erase( tempVector.begin() + randomInteger );
    NT--;
    // std::cout << NT << std::endl;
  };
}

int main(int argc, char *argv[]) {
  // argc specifies how many arguments are given (program name = 1; arguments rest)
  // argv[] are the arguments themselves, 0=program name, 1=arg0, 2=arg1 etc...

  // argc == 1 >> playlist.txt and random.txt as default
  // argc == 2 >> input file given; but no output file
  // argc == 3 >> input and output file given
  std::string inputfile, outputfile;
  if (argc == 1)
  {
    inputfile = "playlist.txt";
  }
  else
  {
    inputfile = argv[1];
  }

  if (argc <= 2)
  {
    outputfile = "playlist_randomized.txt";
  }
  else
  {
    outputfile = argv[2];
  }

  // define input and output streams for file handling
  std::ifstream inputStream;
  std::ofstream outputStream;
  // define vector to store inputStream
  std::vector<std::string> inputVector;
  std::string textOfLine;

  // read in playlist.txt
  std::cout << "Reading <" << inputfile << ">" << std::endl;
  inputStream.open(inputfile);
  if (inputStream.fail( ))
  {
    std::cout << "Input file <" << inputfile << "> opening failed" << std::endl;
    exit(1);
  }
  while (inputStream >> textOfLine)
  {
    inputVector.push_back(textOfLine);
  }
  inputStream.close();

  randomzeVector(inputVector);
  outputStream.open(outputfile);
  if (outputStream.fail( ))
  {
    std::cout << "Output file <" << outputfile << "> opening failed" << std::endl;
    exit(1);
  }
  size_t N = inputVector.size();
  for (unsigned int i = 0; i < N; ++i) {
    outputStream << inputVector[i] << std::endl;
  }
  outputStream.close();
  std::cout << "Randomizing " << N << " Entries"<< std::endl;
  std::cout << "Writing <" << outputfile << ">" << std::endl;
  return 0;
}
