#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_symbol(char);
bool is_multiple(char);
int find_symbol(const vector<string>&);
int check_line(string);
int adjacent(string, string, string);
vector<int> possible_values(string);

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage " << argv[0] << " <filename>\n";
    return 1;
  }
  
  ifstream file(argv[1]);
  if (!file.is_open()) {
    cout << "Error when opening file\n";
    return 1; 
  }
  
  string line;
  vector<string> input;
  while (getline(file, line)) {
    input.push_back(line);
  }
  int sum = find_symbol(input);
  cout << "The sum of the engine parts is: " << sum << endl;
  file.close();
  return 0;
}

bool is_symbol(char current_symbol) {
  const vector<char> symbols = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };
  if (find(symbols.begin(), symbols.end(), current_symbol) != symbols.end()) {
    return false;
  }
  return true;
}

bool is_multiple(char current_symbol) {
  return current_symbol == '*';
}

int find_symbol(const vector<string>& lines) {
  string full_num;
  int num = 0, product = 0;
  bool adding = false;
  for (int i = 1; i < lines.size() - 1; i++) {
    const string prev_line = lines[i - 1];
    const string line = lines[i];
    const string next_line = lines[i + 1];

    for (int j = 0; j < lines[i].length(); j++) {
      if (is_multiple(line[j])) {
        int result = adjacent(prev_line.substr(j - 3, 7), line.substr(j - 3, 7), next_line.substr(j - 3, 7));
        product += result;
        cout << result << endl << endl;
      }
      if (is_symbol(line[j])) {
        num += check_line(prev_line.substr(j - 3, 7));
        num += check_line(line.substr(j - 3, 7));
        num += check_line(next_line.substr(j - 3, 7));
      }
    }
  }
  cout << "The product between the second engines parts is: " << product << endl;
  return num;
}

//part 1
int check_line(string line) {
  int result = 0;
  //3 digit numbers
  if (isdigit(line[0]) && isdigit(line[1]) && isdigit(line[2])) {
    result += (line[0] - 0x30) * 100 + (line[1] - 0x30) * 10 + (line[2] - 0x30);
  }
  if (isdigit(line[1]) && isdigit(line[2]) && isdigit(line[3])) {
    result += (line[1] - 0x30) * 100 + (line[2] - 0x30) * 10 + (line[3] - 0x30);
  }
  if (isdigit(line[2]) && isdigit(line[3]) && isdigit(line[4])) {
    result += (line[2] - 0x30) * 100 + (line[3] - 0x30) * 10 + (line[4] - 0x30);
  }
  if (isdigit(line[3]) && isdigit(line[4]) && isdigit(line[5])) {
    result += (line[3] - 0x30) * 100 + (line[4] - 0x30) * 10 + (line[5] - 0x30);
  }
  if (isdigit(line[4]) && isdigit(line[5]) && isdigit(line[6])) {
    result += (line[4] - 0x30) * 100 + (line[5] - 0x30) * 10 + (line[6] - 0x30);
  }

  //2 digit numbers
  if (!isdigit(line[0]) && isdigit(line[1]) && isdigit(line[2]) && !isdigit(line[3])) {
    result += (line[1] - 0x30) * 10 + (line[2] - 0x30);
  }
  if (!isdigit(line[1]) && isdigit(line[2]) && isdigit(line[3]) && !isdigit(line[4])) {
    result += (line[2] - 0x30) * 10 + (line[3] - 0x30);
  }
  if (!isdigit(line[2]) && isdigit(line[3]) && isdigit(line[4]) && !isdigit(line[5])) {
    result += (line[3] - 0x30) * 10 + (line[4] - 0x30);
  }
  if (!isdigit(line[3]) && isdigit(line[4]) && isdigit(line[5]) && !isdigit(line[6])) {
    result += (line[4] - 0x30) * 10 + (line[5] - 0x30);
  }

  //1 digit numbers
  if (!isdigit(line[1]) && isdigit(line[2]) && !isdigit(line[3])) {
    result += (line[2] - 0x30);
  }
  if (!isdigit(line[2]) && isdigit(line[3]) && !isdigit(line[4])) {
    result += (line[3] - 0x30);
  }
  if (!isdigit(line[3]) && isdigit(line[4]) && !isdigit(line[5])) {
    result += (line[4] - 0x30);
  }
  return result;
}

//part 2
int adjacent(string line1, string line2, string line3) {
  vector<int> top = possible_values(line1);
  vector<int> mid = possible_values(line2);
  vector<int> bot = possible_values(line3);

  if (top.size() + mid.size() + bot.size() == 2) {
    int temp = 1;
    for (int i = 0; i < top.size(); i++) {
      temp *= top[i];
    }
    for (int i = 0; i < mid.size(); i++) {
      temp *= mid[i];
    }
    for (int i = 0; i < bot.size(); i++) {
      temp *= bot[i];
    }
    return temp;
  } else {
    return 0;
  }
}

vector<int> possible_values(string line) {
  vector<int> temp;
  if (isdigit(line[0]) && isdigit(line[1]) && isdigit(line[2])) {
    temp.push_back((line[0] - 0x30) * 100 + (line[1] - 0x30) * 10 + (line[2] - 0x30));
  }
  if (isdigit(line[1]) && isdigit(line[2]) && isdigit(line[3])) {
    temp.push_back((line[1] - 0x30) * 100 + (line[2] - 0x30) * 10 + (line[3] - 0x30));
  }
  if (isdigit(line[2]) && isdigit(line[3]) && isdigit(line[4])) {
    temp.push_back((line[2] - 0x30) * 100 + (line[3] - 0x30) * 10 + (line[4] - 0x30));
  }
  if (isdigit(line[3]) && isdigit(line[4]) && isdigit(line[5])) {
    temp.push_back((line[3] - 0x30) * 100 + (line[4] - 0x30) * 10 + (line[5] - 0x30));
  }
  if (isdigit(line[4]) && isdigit(line[5]) && isdigit(line[6])) {
    temp.push_back((line[4] - 0x30) * 100 + (line[5] - 0x30) * 10 + (line[6] - 0x30));
  }

  //2 digit numbers
  if (!isdigit(line[0]) && isdigit(line[1]) && isdigit(line[2]) && !isdigit(line[3])) {
    temp.push_back((line[1] - 0x30) * 10 + (line[2] - 0x30));
  }
  if (!isdigit(line[1]) && isdigit(line[2]) && isdigit(line[3]) && !isdigit(line[4])) {
    temp.push_back((line[2] - 0x30) * 10 + (line[3] - 0x30));
  }
  if (!isdigit(line[2]) && isdigit(line[3]) && isdigit(line[4]) && !isdigit(line[5])) {
    temp.push_back((line[3] - 0x30) * 10 + (line[4] - 0x30));
  }
  if (!isdigit(line[3]) && isdigit(line[4]) && isdigit(line[5]) && !isdigit(line[6])) {
    temp.push_back((line[4] - 0x30) * 10 + (line[5] - 0x30));
  }

  //1 digit numbers
  if (!isdigit(line[1]) && isdigit(line[2]) && !isdigit(line[3])) {
    temp.push_back((line[2] - 0x30));
  }
  if (!isdigit(line[2]) && isdigit(line[3]) && !isdigit(line[4])) {
    temp.push_back((line[3] - 0x30));
  }
  if (!isdigit(line[3]) && isdigit(line[4]) && !isdigit(line[5])) {
    temp.push_back((line[4] - 0x30));
  }
  cout << temp.size() << endl;
  for (int i = 0; i < temp.size(); i++) {
    cout << temp[i] << " ";
  }
  cout << endl;
  return temp;
}
