#include <iostream>
#include <fstream>
#include <unordered_map>
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

  string input;
  int sum = 0, count = 1;
  
  while (getline(file, input)){
    int num = 0;
    for (int i = 0; i < input.length(); i++) {
      if (isdigit(input[i])) {
        int temp = static_cast<int>(input[i]) - static_cast<int>('0');
        int letter_temp = get_digit_forward(input.substr(0, i));
        if (letter_temp == -1) {
          num += temp * 10;
        } else {
          num += letter_temp * 10;
        }
        break;
      }
    }
    for (int i = input.length() - 1; i >= 0; i--) {
      if (isdigit(input[i])) {
        int temp = static_cast<int>(input[i]) - static_cast<int>('0');
        int letter_temp = get_digit_backward(input.substr(i + 1));
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
  for (int i = 0; i < substring.length(); i++) {
    if (i + 2 < substring.length() && substring[i] == 'o' && substring[i + 1] == 'n' && substring[i + 2] == 'e') {
      return  1;
    } else if (i + 2 < substring.length() && substring[i] == 't' && substring[i + 1] == 'w' && substring[i + 2] == 'o') {
      return  2;
    } else if (i + 4 < substring.length() && substring[i] == 't' && substring[i + 1] == 'h' && substring[i + 2] == 'r' && substring[i + 3] == 'e' && substring[i + 4] == 'e') {
      return 3;
    } else if (i + 3 < substring.length() && substring[i] == 'f' && substring[i + 1] == 'o' && substring[i + 2] == 'u' && substring[i + 3] == 'r') {
      return  4;
    } else if (i + 3 < substring.length() && substring[i] == 'f' && substring[i + 1] == 'i' && substring[i + 2] == 'v' && substring[i + 3] == 'e') {
      return  5;
    } else if (i + 2 < substring.length() && substring[i] == 's' && substring[i + 1] == 'i' && substring[i + 2] == 'x') {
      return  6;
    } else if (i + 4 < substring.length() && substring[i] == 's' && substring[i + 1] == 'e' && substring[i + 2] == 'v' && substring[i + 3] == 'e' && substring[i + 4] == 'n') {
      return  7;
    } else if (i + 4 < substring.length() && substring[i] == 'e' && substring[i + 1] == 'i' && substring[i + 2] == 'g' && substring[i + 3] == 'h' && substring[i + 4] == 't') {
      return 8;
    } else if (i + 3 < substring.length() && substring[i] == 'n' && substring[i + 1] == 'i' && substring[i + 2] == 'n' && substring[i + 3] == 'e') {
      return 9;
    }
  }
  return -1;
}

int get_digit_backward(string substring) {
  int temp_num = -1;
  for (int i = 0; i < substring.length(); i++) {
    if (i + 2 < substring.length() && substring[i] == 'o' && substring[i + 1] == 'n' && substring[i + 2] == 'e') {
      temp_num = 1;
    } else if (i + 2 < substring.length() && substring[i] == 't' && substring[i + 1] == 'w' && substring[i + 2] == 'o') {
      temp_num = 2;
    } else if (i + 4 < substring.length() && substring[i] == 't' && substring[i + 1] == 'h' && substring[i + 2] == 'r' && substring[i + 3] == 'e' && substring[i + 4] == 'e') {
      temp_num = 3;
    } else if (i + 3 < substring.length() && substring[i] == 'f' && substring[i + 1] == 'o' && substring[i + 2] == 'u' && substring[i + 3] == 'r') {
      temp_num = 4;
    } else if (i + 3 < substring.length() && substring[i] == 'f' && substring[i + 1] == 'i' && substring[i + 2] == 'v' && substring[i + 3] == 'e') {
      temp_num = 5;
    } else if (i + 2 < substring.length() && substring[i] == 's' && substring[i + 1] == 'i' && substring[i + 2] == 'x') {
      temp_num = 6;
    } else if (i + 4 < substring.length() && substring[i] == 's' && substring[i + 1] == 'e' && substring[i + 2] == 'v' && substring[i + 3] == 'e' && substring[i + 4] == 'n') {
      temp_num = 7;
    } else if (i + 4 < substring.length() && substring[i] == 'e' && substring[i + 1] == 'i' && substring[i + 2] == 'g' && substring[i + 3] == 'h' && substring[i + 4] == 't') {
      temp_num = 8;
    } else if (i + 3 < substring.length() && substring[i] == 'n' && substring[i + 1] == 'i' && substring[i + 2] == 'n' && substring[i + 3] == 'e') {
      temp_num = 9;
    }
  }
  return temp_num;
}
