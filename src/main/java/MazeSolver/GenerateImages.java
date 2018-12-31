package MazeSolver;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.Color;
import java.lang.Integer;

class GenerateImagaes {
  public GenerateImagaes(int ammount, int complexity, String directory) {
    File folder = new File(directory);

    for (int i = 0; i < ammount; i++)
      if (complexity > 0) {
        generateImage(folder, complexity);
      }
  }

  public void generateImage(File folder, int complexity) {
    int size = complexity * 10;
    // Allow for a black box to be generated, adding one to the border size
    BufferedImage bufferedImage = new BufferedImage(size + 2, size + 2, BufferedImage.TYPE_INT_RGB);


    bufferedImage = generateStartStop(bufferedImage, size);
    bufferedImage = generateMaze(bufferedImage, size);


    int nameTemp  = (int) (Math.random() * 10);
    File fileName = new File(folder, nameTemp + ".png");
    try {
      ImageIO.write(bufferedImage, "png", fileName);
    } catch (IOException e) {
      System.out.println(e);
    }
    System.out.println("Made File: " + fileName);
  }

  // Adding one to the x,y to deal with the new black box surrounding the maze
  BufferedImage generateStartStop(BufferedImage image, int size) {
    image.setRGB((int) (Math.random() * (size - 2)) + 2, 0, Integer.parseInt("F44242", 16));
    image.setRGB((int) (Math.random() * (size - 2)) + 2, size - 1, Integer.parseInt("47f441", 16));

    return image;
  }

  // Adding one to the x,y to deal with the new black box surrounding the maze
  BufferedImage generateMaze(BufferedImage image, int size) {
    // The PP Principal of some sort even though I am thinking of it wrong
    for (int i = 0; i < ((((size - 1) * (size - 1)) / 2) + size * 2); i++) {
      int x = ((int) (Math.random() * (size - 2)) + 1) + 1;
      int y = ((int) (Math.random() * (size - 2)) + 1) + 1;
      if (image.getRGB(x, y) != Integer.parseInt("ffffff", 16)) {
        image.setRGB(x, y, Integer.parseInt("ffffff", 16));
      } else {
        i--;
      }
    }
    return image;
  }
}
