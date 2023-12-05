#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int get_digit_forward(string);
int get_digit_backward(string); 

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
  int sum = 0, count = 1;
  
  while (getline(file, line)){
    int num = 0;
    for (int i = 0; i < line.length(); i++) {
      if (isdigit(line[i])) {
        int temp = stoi(string(1, line[i]));
        int letter_temp = get_digit_forward(line.substr(0, i));
        if (letter_temp == -1) {
          num += temp * 10;
        } else {
          num += letter_temp * 10;
        }
        break;
      }
    }
    for (int i = line.length() - 1; i >= 0; i--) {
      if (isdigit(line[i])) {
        int temp = stoi(string(1, line[i]));
        int letter_temp = get_digit_backward(line.substr(i + 1));
        if (letter_temp == -1) {
          num += temp;
        } else {
          num += letter_temp;
        }
        break;
      }
    }
    cout << "The number for the string at index: " << count << " is: " << num << endl;
    sum += num;
    count++;
  }

  printf("The total sum of all the lines is: %d\n", sum);
  file.close();
  return 0;
}

int get_digit_forward(string substring) {
  unordered_map<string, int> word_to_num = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
  };

  for (int i = 0; i < substring.length(); i++) {
    for (const auto &pair : word_to_num) {
      if (i + pair.first.length() <= substring.length() && substring.compare(i, pair.first.length(), pair.first) == 0) {
        return pair.second;
      }
    }
  }
  return -1;
}

int get_digit_backward(string substring) {
  int temp_num = -1;
  unordered_map<string, int> word_to_num = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
  };

  for (int i = 0; i < substring.length(); i++) {
    for (const auto &pair : word_to_num) {
      if (i + pair.first.length() <= substring.length() && substring.compare(i, pair.first.length(), pair.first) == 0) {
        temp_num = pair.second;
      }
    }
  }
  return temp_num;
}
