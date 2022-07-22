package com.habuma.restfun;

import static org.junit.Assert.*;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=MagicConfig.class)
public class MagicExistsTest {

  @Autowired
  private ApplicationContext context;
  
  /*
   * Ten test nie powiedzie się, jeśli nie ustawisz właściwości "magic".
   * Właściwość tę możesz ustawić jako zmienną środowiskową, właściwość systemu JVM, dodając metodę
   * opatrzoną adnotacją @BeforeClass i wywołując metodę System.setProperty(), bądź na kilka innych sposobów.
   */
  @Test
  public void shouldNotBeNull() {
    assertTrue(context.containsBean("magicBean"));
  }
  
}
