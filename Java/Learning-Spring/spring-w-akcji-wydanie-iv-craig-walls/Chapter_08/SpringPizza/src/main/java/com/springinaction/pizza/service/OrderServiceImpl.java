package com.springinaction.pizza.service;

import org.apache.log4j.Logger;

import com.springinaction.pizza.domain.Order;

public class OrderServiceImpl {
  private static final Logger LOGGER = 
      Logger.getLogger(OrderServiceImpl.class);
  
  public OrderServiceImpl() {}
  
  public void saveOrder(Order order) {
    LOGGER.debug("ZAPISUJEMY ZAMÓWIENIE:  " );
    LOGGER.debug("   Klient:  " + order.getCustomer().getName());
    LOGGER.debug("   # sztuk pizzy:  " + order.getPizzas().size());
    LOGGER.debug("   Płatność:  " + order.getPayment());
  }
}
