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
        BufferedImage picture = ImageIO.read(photo);
        System.out.println("Parsing File: " + photo.getName());
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

        System.out.println("Hex: " + Integer.toHexString(p));

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

        // if (Integer.toHexString(p) == "ffffffff") {
        //   System.out.println("Ahhh");
        // } else if (p == Integer.parseInt("F44242", 16)) {
        //   tempImg[i][j] = "S".charAt(0);
        // } else if (p == Integer.parseInt("47f441", 16)) {
        //   tempImg[i][j] = "E".charAt(0);
        //   System.out.println(Integer.toHexString(p));
        // } else if (Integer.toHexString(p) == "ff000000") {
        //   // System.out.println(Integer.toHexString(p));
        // } else { }
      }
      writer.write(tempImg[i], 0, image.getWidth());
      writer.newLine();
    }
    writer.close();
    System.out.println("Just Parsed: " + Image.getName());
  } /* parseImage */
}
