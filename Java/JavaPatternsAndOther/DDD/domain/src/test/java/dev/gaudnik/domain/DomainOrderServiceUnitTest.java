package dev.gaudnik.domain;

import dev.gaudnik.domain.OrderRepository;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.math.BigDecimal;
import java.util.UUID;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.verify;

class DomainOrderServiceUnitTest {

	private OrderRepository orderRepository;
	private DomainOrderService tested;

	@BeforeEach
	void setUp() {
		orderRepository = mock(OrderRepository.class);
		tested = new DomainOrderService(orderRepository);
	}

	@Test
	void shouldCreateOrder_thenSaveIt() {
		final Product product = new Product(UUID.randomUUID(), BigDecimal.TEN, "productName");
		final UUID id = tested.createOrder(product);

		verify(orderRepository).save(any(Order.class));
		assertNotNull(id);
	}
}
