package com.springinaction.pizza.flow;

import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;
import org.springframework.webflow.execution.Action;
import org.springframework.webflow.execution.Event;
import org.springframework.webflow.execution.RequestContext;

import com.springinaction.pizza.domain.Pizza;
import com.springinaction.pizza.domain.Topping;

public class SpecialtyPizzaBuilder implements Action {
   private static final Logger LOGGER = Logger
                     .getLogger(SpecialtyPizzaBuilder.class);

   public Event execute(RequestContext request) throws Exception {
      String type = request.getRequestParameters().get("pizzaType");

      LOGGER.debug("BUDOWANIE SPECJALNEJ PIZZY:  " + type);

      Pizza pizza = (Pizza) request.getFlowScope().get("pizza");
      if ("MIĘSNA".equals(type)) {
         LOGGER.debug("TWORZYMY PIZZĘ CARNIVORE");

         List<Topping> meats = new ArrayList<Topping>();

         meats.add(Topping.BEKON);
         meats.add(Topping.HAMBURGER);
         meats.add(Topping.PEPPERONI);
         meats.add(Topping.KIEŁBASA);

         pizza.setToppings(meats);
      } else if ("WEGETARIAŃSKA".equals(type)) {
         LOGGER.debug("TWORZYMY PIZZĘ HERBIVORE");
         List<Topping> meats = new ArrayList<Topping>();

         meats.add(Topping.ZIELONY_PIEPRZ);
         meats.add(Topping.GRZYBY);
         meats.add(Topping.ANANAS);
         meats.add(Topping.POMIDOR);

         pizza.setToppings(meats);
      } else if ("WŁASNA".equals(type)) {
         LOGGER.debug("TWORZYMY PIZZĘ OMNIVORE");

         List<Topping> meats = new ArrayList<Topping>();
         System.out.println("TO DZIAŁA!");

         meats.add(Topping.BEKON);
         meats.add(Topping.HAMBURGER);
         meats.add(Topping.PEPPERONI);
         meats.add(Topping.KIEŁBASA);
         meats.add(Topping.ZIELONY_PIEPRZ);
         meats.add(Topping.GRZYBY);
         meats.add(Topping.ANANAS);
         meats.add(Topping.POMIDOR);
         meats.add(Topping.DODATKOWY_SER);
         meats.add(Topping.CEBULA);
         meats.add(Topping.JALAPENO);

         pizza.setToppings(meats);
      }

      request.getFlowScope().put("pizza", pizza);

      return new Event(this, "success");
   }
}
