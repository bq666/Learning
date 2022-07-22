package com.springinaction.pizza.domain;

import java.io.Serializable;
import java.util.Arrays;
import java.util.List;

import org.apache.commons.lang3.text.WordUtils;

public enum Topping implements Serializable {
  PEPPERONI, 
  KIEŁBASA, 
  HAMBURGER,
  GRZYBY, 
  BEKON, 
  ANANAS,
  ZIELONY_PIEPRZ,
  JALAPENO,
  POMIDOR,
  CEBULA,
  DODATKOWY_SER;
  
  public static List<Topping> asList() {
    Topping[] all = Topping.values();
    return Arrays.asList(all);
  }
  
  @Override
  public String toString() {
    return WordUtils.capitalizeFully(name().replace('_', ' '));
  }
}
