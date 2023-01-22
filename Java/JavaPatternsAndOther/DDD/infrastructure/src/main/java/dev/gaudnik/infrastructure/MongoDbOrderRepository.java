package dev.gaudnik.infrastructure;

import dev.gaudnik.domain.Order;
import dev.gaudnik.domain.OrderRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.Optional;
import java.util.UUID;

@Component
class MongoDbOrderRepository implements OrderRepository {

	private SpringDataMongoOrderRepository orderRepository;

	@Autowired
	public MongoDbOrderRepository(SpringDataMongoOrderRepository orderRepository) {
		this.orderRepository = orderRepository;
	}
	@Override
	public Optional<Order> findById(UUID id) {
		return Optional.empty();
	}

	@Override
	public void save(Order order) {

	}
}
