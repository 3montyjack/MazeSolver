package MazeSolver;

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.io.BufferedWriter;
import java.io.FileWriter;


public class ReadImage {
  File folder;
  File[] files;

  ReadImage(String fileLocation, String saveDir) {
    folder = new File(fileLocation);
    if (folder.isDirectory()) {
      files = folder.listFiles();
    } else {
      files = new File[] { folder };
    }
    ParseFiles(saveDir);
  }

  private void ParseFiles(String saveDir) {
    try {
      for (File photo : files) {
        System.out.println("Parsing File: " + photo.getName());
        BufferedImage picture = ImageIO.read(photo);
        parseImage(picture, photo.getName(), saveDir);
      }
    } catch (IOException e) {
      System.out.println("FileName is incorrect");
      e.printStackTrace();
    }
  }

  private void parseImage(BufferedImage image, String name, String saveDir) throws IOException {
    char[][] tempImg = new char[image.getWidth()][image.getHeight()];

    File Image = new File(saveDir, name.replace(".png", ".txt"));
    BufferedWriter writer = new BufferedWriter(new FileWriter(Image));
    for (int i = 0; i < image.getHeight(); i++) {
      for (int j = 0; j < image.getWidth(); j++) {
        int p = image.getRGB(j, i);

        // System.out.println("Hex: " + Integer.toHexString(p));

        switch (Integer.toHexString(p)) {
            case "ffffffff":
              tempImg[i][j] = "1".charAt(0);
              break;
            case "ff000000":
              tempImg[i][j] = "0".charAt(0);
              break;
            case "ff47f441":
              tempImg[i][j] = "S".charAt(0);
              break;
            case "fff44242":
              tempImg[i][j] = "E".charAt(0);
              break;

            default:
              tempImg[i][j] = "5".charAt(0);
        }
      }
      writer.write(tempImg[i], 0, image.getWidth());
      writer.newLine();
    }
    writer.close();
    System.out.println("Just Parsed: " + Image.getName());
  } /* parseImage */
}
