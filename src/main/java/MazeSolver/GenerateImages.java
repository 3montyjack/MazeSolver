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

    BufferedImage bufferedImage = new BufferedImage(size, size, BufferedImage.TYPE_INT_RGB);


    bufferedImage = generateStartStop(bufferedImage, size);
    bufferedImage = generateMaze(bufferedImage, size);
    boolean[][] imagePart = new boolean[size][size];

    for (int i = 0; i < size; i++) {
      imagePart[i]       [0] = false;
      imagePart[0]       [i] = false;
      imagePart[size - 1][i] = false;
      imagePart[i][size - 1] = false;
    }


    int nameTemp  = (int) (Math.random() * 10);
    File fileName = new File(folder, nameTemp + ".png");
    try {
      ImageIO.write(bufferedImage, "png", fileName);
    } catch (IOException e) {
      System.out.println(e);
    }
    System.out.println("Made File: " + fileName);
  }

  BufferedImage generateStartStop(BufferedImage image, int size) {
    image.setRGB((int) (Math.random() * (size - 2)) + 1, 0, Integer.parseInt("F44242", 16));

    image.setRGB((int) (Math.random() * (size - 2)) + 1, size - 1, Integer.parseInt("47f441", 16));


    return image;
  }

  BufferedImage generateMaze(BufferedImage image, int size) {
    // The PP Principal of some sort even though I am thinking of it wrong
    for (int i = 0; i < ((((size - 1) * (size - 1)) / 2) + size * 2); i++) {
      int x = ((int) (Math.random() * (size - 2)) + 1);
      int y = ((int) (Math.random() * (size - 2)) + 1);
      if (image.getRGB(x, y) != Integer.parseInt("ffffff", 16)) {
        image.setRGB(x, y, Integer.parseInt("ffffff", 16));
      } else {
        i--;
      }
    }
    return image;
  }
}
