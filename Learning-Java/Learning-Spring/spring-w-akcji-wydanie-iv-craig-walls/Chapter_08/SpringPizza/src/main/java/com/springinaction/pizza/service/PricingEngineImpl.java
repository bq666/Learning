package com.springinaction.pizza.service;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

import org.apache.log4j.Logger;

import com.springinaction.pizza.domain.Order;
import com.springinaction.pizza.domain.Pizza;
import com.springinaction.pizza.domain.PizzaSize;

@SuppressWarnings("serial")
public class PricingEngineImpl 
    implements PricingEngine, Serializable {
  private static final Logger LOGGER = 
      Logger.getLogger(PricingEngineImpl.class);
  
  private static Map<PizzaSize, Float> SIZE_PRICES;
  static {
    SIZE_PRICES = new HashMap<PizzaSize, Float>();
    SIZE_PRICES.put(PizzaSize.MAŁA, 6.99f);
    SIZE_PRICES.put(PizzaSize.ŚREDNIA, 7.99f);
    SIZE_PRICES.put(PizzaSize.DUŻA, 8.99f);
    SIZE_PRICES.put(PizzaSize.GIGANT, 9.99f);
  }
  private static float PRICE_PER_TOPPING = 0.20f;
  
  public PricingEngineImpl() {}
  
  public float calculateOrderTotal(Order order) {
    LOGGER.debug("Liczymy całkowitą kwotę zamówienia");
    
    float total = 0.0f;
    
    for (Pizza pizza : order.getPizzas()) {
      float pizzaPrice = SIZE_PRICES.get(pizza.getSize());
      if(pizza.getToppings().size() > 2) {
        pizzaPrice += (pizza.getToppings().size() * 
            PRICE_PER_TOPPING);
      }
      total += pizzaPrice;
    }
    
    return total;
  }
}
