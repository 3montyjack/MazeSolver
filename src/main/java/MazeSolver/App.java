package MazeSolver;

import MazeSolver.GenerateImagaes;
import MazeSolver.ReadImage;


public class App {
  static ReadImage imageFiles;
  static GenerateImagaes imageGen;
  public static void main(String[] args){
    String directory = "images/0.png";
    String saveDir = "parsedImages";
    // imageGen = new GenerateImagaes(20,1,directory);
    imageFiles = new ReadImage(directory, saveDir);
  }
}
