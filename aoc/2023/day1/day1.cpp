#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <string>

using namespace std;

int get_digit_forward(string);
int get_digit_backward(string); 
int compare_digits(int, string);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage %s <filename>\n", argv[0]);
    return 1;
  }
  
  ifstream file(argv[1]);
  if (!file.is_open()) {
    printf("Error when opening file\n");
    return 1; 
  }

  string line;
  int sum = 0, count = 1;
  
  while (getline(file, line)){
    int num = 0;
    for (int i = 0; i < line.length(); i++) {
      if (isdigit(line[i])) {
        int temp = static_cast<int>(line[i]) - static_cast<int>('0');
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
        int temp = static_cast<int>(line[i]) - static_cast<int>('0');
        int letter_temp = get_digit_backward(line.substr(i + 1));
        if (letter_temp == -1) {
          num += temp;
        } else {
          num += letter_temp;
        }
        break;
      }
    }
    printf("The number for the string at index %d is: %d\n\n", count, num);
    sum += num;
    count++;
  }

  printf("The total sum of all the lines is: %d\n", sum);
  file.close();
  return 0;
}

int get_digit_forward(string substring) {
  int length = substring.length();
  for (int i = 0; i < length; i++) {
    if (i + 2 < substring.length() && substring.compare(i, 3, "one") == 0) {
      return  1;
    } else if (i + 2 < substring.length() && substring.compare(i, 3, "two") == 0) {
      return  2;
    } else if (i + 4 < substring.length() && substring.compare(i, 5, "three") == 0) {
      return 3;
    } else if (i + 3 < substring.length() && substring.compare(i, 4, "four") == 0) {
      return  4;
    } else if (i + 3 < substring.length() && substring.compare(i, 4, "five") == 0) {
      return  5;
    } else if (i + 2 < substring.length() && substring.compare(i, 3, "six") == 0) {
      return  6;
    } else if (i + 4 < substring.length() && substring.compare(i, 5, "seven") == 0) {
      return  7;
    } else if (i + 4 < substring.length() && substring.compare(i, 5, "eight") == 0) {
      return 8;
    } else if (i + 3 < substring.length() && substring.compare(i, 4, "nine") == 0) {
      return 9;
    }
  }
  return -1;
}

int get_digit_backward(string substring) {
  int temp_num = -1;
  for (int i = 0; i < substring.length(); i++) {
    if (i + 2 < substring.length() && substring.compare(i, 3, "one") == 0) {
      temp_num =  1;
    } else if (i + 2 < substring.length() && substring.compare(i, 3, "two") == 0) {
      temp_num =  2;
    } else if (i + 4 < substring.length() && substring.compare(i, 5, "three") == 0) {
      temp_num = 3;
    } else if (i + 3 < substring.length() && substring.compare(i, 4, "four") == 0) {
      temp_num = 4;
    } else if (i + 3 < substring.length() && substring.compare(i, 4, "five") == 0) {
      temp_num = 5;
    } else if (i + 2 < substring.length() && substring.compare(i, 3, "six") == 0) {
      temp_num = 6;
    } else if (i + 4 < substring.length() && substring.compare(i, 5, "seven") == 0) {
      temp_num = 7;
    } else if (i + 4 < substring.length() && substring.compare(i, 5, "eight") == 0) {
      temp_num = 8;
    } else if (i + 3 < substring.length() && substring.compare(i, 4, "nine") == 0) {
      temp_num = 9;
    }
  }
  return temp_num;
}
