package day4;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.stream.IntStream;

public class App {
  public static void main(String[] args) {
    int result = 0, counter = 0;
    int[] nums = new int[201];
    Arrays.fill(nums, 1);

    try {
      File file = new File("src/main/java/day4/input.txt");
      Scanner scanner = new Scanner(file);
      while (scanner.hasNextLine()) {
        String data = scanner.nextLine();
        int colon_index = data.indexOf(":");
        int pipe_index = data.indexOf("|");
        int count = 0;

        String card = data.substring(colon_index + 1, pipe_index).trim();
        String hand = data.substring(pipe_index + 1).trim();
        String[] card_nums = card.split("\\s+");
        String[] hand_nums = hand.split("\\s+");

        //part 1
        for (String value : hand_nums) {
          if (Arrays.asList(card_nums).contains(value)) {
            count++;
          }
        }

        //part 2
        for (int i = 0; i < count; i++) {
          nums[counter + 1 + i] += nums[counter];
        }

        result += (int) Math.pow(2, count - 1);
        counter++;
      }
    } catch (FileNotFoundException e) {
      System.out.println("Error: " + e.getMessage());
    }
    System.out.println("The result is: " + result);
    System.out.println("The total number of cards is: " + IntStream.of(nums).sum());
  }
}
