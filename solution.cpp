/*
 * Solution to http://projecteuler.net/problem=67
 *
 * Notes: This algorithm begins with the base of the triangle and 'rolls up' the rows
 * into the one above by comparing each row's elements to its immediate neighbor
 * choosing the one with the higher value and adding that to the shared adjacent
 * element in the next row. This continues until the 'top' of the triangle is reached.
 *
 * Assumptions: The input file is in perfect format containing only positive integers
 * and spaces in a 'triangle' format.
 *
 * Created on: July 30, 2010
 * Author: Randy Shepherd
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

const string INPUT_FILE_NAME = "triangle.txt";

// Fills a 2-dimensional vector containing the contents of the file.
// Note that the base of the triangle is the 1st element of 1st dimension.
void parseFile(ifstream& inFile, vector<vector<unsigned> >& lines);

// Returns the sum of the optimal path through the triangle
unsigned calculate(vector<vector<unsigned> >& lines);

int main() {
  ifstream inFile;
  inFile.open(INPUT_FILE_NAME.c_str());

  // 1D=lines 2D=numbers in each line
  vector<vector<unsigned> > lines;
  parseFile(inFile, lines);

  cout << calculate(lines) << endl;
}

void parseFile(ifstream& inFile, vector<vector<unsigned> >& lines) {
  string line;
  unsigned number;
  while (getline(inFile, line)) {
    lines.push_back(vector<unsigned> ());
    istringstream stringStream(line);
    while (stringStream >> number)
      lines.back().push_back(number);
  }

  reverse(lines.begin(), lines.end());
}

unsigned calculate(vector<vector<unsigned> >& lines) {
  // Starting at the bottom of the triangle...
  for (int k = 0; k < lines.size() - 1; ++k) {
    vector<unsigned>& current = lines.at(k);
    vector<unsigned>& next = lines.at(k + 1);

    // ...evaluate each element's value relative to it's neighbor on the right.
    // The greater is added to the shared adjacent element in the next line.
    for (int i = 0; i < current.size() - 1; i++)
      if (current[i] >= current[i + 1]) next[i] += current[i];
      else next[i] += current[i + 1];
  }

  // the new value at top of the triangle
  return lines.back()[0];
}
