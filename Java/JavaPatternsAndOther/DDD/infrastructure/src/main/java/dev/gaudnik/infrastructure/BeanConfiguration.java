package dev.gaudnik.infrastructure;

import dev.gaudnik.domain.OrderRepository;
import dev.gaudnik.domain.OrderService;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
class BeanConfiguration {

	@Bean
	OrderService orderService(OrderRepository orderRepository) {

	}
}
