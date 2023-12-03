#include <iostream>
#include <fstream>
#include <string>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

using namespace std;

int cube_of_line(string line) {
  int red = -1, green = -1, blue = -1, temp = 0;
  for (int i = 0; i < line.length(); i++) {
    if (isdigit(line[i])) {
      if (!isdigit(line[i-1])) {
        temp = 0;
      }
      if (isdigit(line[i + 1])) {
        temp += (line[i] - 0x30) * 10;
      } else {
        temp += line[i] - 0x30;
      }
    } else {
      if (line[i] == 'r') {
        if (line.compare(i, 3, "red") == 0) {
          if (red < temp) red = temp;
        }
      } else if (line[i] == 'g') {
        if (line.compare(i, 5, "green") == 0) {
          if (green < temp) green = temp;
        }
      } else if (line[i] == 'b') {
        if (line.compare(i, 4, "blue") == 0) {
          if (blue < temp) blue = temp;
        }
      }
    }
  }
  return red * green * blue;
}

bool get_values(string line, string color) {
  int red = 0, green = 0, blue =0, temp = 0;

  for (int i = 0; i < line.length(); i++) {
    if (isdigit(line[i])) {
      if (!isdigit(line[i-1])) {
        temp = 0;
      }
      if (isdigit(line[i + 1])) {
        temp += (line[i] - 0x30) * 10;
      } else {
        temp += line[i] - 0x30;
      }
    } else {
      if (color == "red" && line[i] == 'r') {
        if (line.compare(i, 3, "red") == 0) {
          if (temp > MAX_RED) return false;
        }
      } else if (color == "green" && line[i] == 'g') {
        if (line.compare(i, 5, "green") == 0) {
          if (temp > MAX_GREEN) return false;
        }
      } else if (color == "blue" && line[i] == 'b') {
        if (line.compare(i, 4, "blue") == 0) {
          if (temp > MAX_BLUE) return false;
        }
      }
    }
  }
  return true;
}

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
  char digit_1, digit_2;
  int possible_ids = 0;
  int game_id = 0;
  int count = 1;
  int part_2 = 0;
  
  while (getline(file, line)) {
    for (int i = 0; line[i] != ':'; i++) {
      if (isdigit(line[i])) {
        if (line[i + 3] == ':') {
          game_id += (line[i] - 0x30) * 100;
        } else if (line[i + 2] == ':') {
          game_id += (line[i] - 0x30) * 10;
        } else {
          game_id += line[i] - 0x30;
        }
      }
    }
    if (get_values(line, "red") && get_values(line, "green") && get_values(line, "blue")) {
      possible_ids += game_id;
    }
    part_2 += cube_of_line(line);
    game_id = 0;
  }
  cout << "The sum of the possible game ids is: " << possible_ids << endl;
  cout << "The sume of the power of the sets is: " << part_2 << endl;
  return 0;
}
