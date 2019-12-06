package com.learning.spring.knight;

import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

public class KnightMain {

  public static void main(String[] args) throws Exception {
    FileSystemXmlApplicationContext context = new FileSystemXmlApplicationContext(
            "src/main/java/com/learning/spring/knight/spring/knight.xml");

    Knight knight = context.getBean(Knight.class);
    knight.embarkOnQuest();
    context.close();
  }

}
