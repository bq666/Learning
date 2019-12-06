package com.springinaction.pizza.domain;


public class CashOrCheckPayment extends Payment {
  public CashOrCheckPayment() {}
  
  public String toString() {
    return "GOTÓWwKA lub CZEK:  $" + getAmount();
  }
}
