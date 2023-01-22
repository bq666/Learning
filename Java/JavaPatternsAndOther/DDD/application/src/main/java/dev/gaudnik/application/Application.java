package dev.gaudnik.application;

import dev.gaudnik.domain.DomainOrderService;
import dev.gaudnik.domain.OrderRepository;
import dev.gaudnik.domain.OrderService;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class Application {

	public static void main(String[] args) {
		SpringApplication.run(Application.class, args);
	}

	@Bean
	OrderService getOrderService() {
		return new DomainOrderService();
	}

}
