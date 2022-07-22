package com.springinaction.pizza.service;

import com.springinaction.pizza.PaymentException;

/**
 * Prosta implementacja procesora płatności.
 * 
 * Pokazana pobieżnie na stronie 606, ale tutaj zaimplementowane sztucznie w ten sposób,
 * aby odrzucać płatności w kwocie powyżej 20 PLN.
 * 
 * @author wallsc
 */
public class PaymentProcessor {
   public PaymentProcessor() {}

   public void approveCreditCard(String creditCardNumber, String expMonth,
                     String expYear, float amount) throws PaymentException {
      if (amount > 20.00) {
         throw new PaymentException();
      }
   }
}
