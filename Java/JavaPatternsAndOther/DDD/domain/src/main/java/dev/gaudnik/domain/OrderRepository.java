package dev.gaudnik.domain;

import java.util.Optional;
import java.util.UUID;

public interface OrderRepository {

	Optional<Order> findById(UUID id);

	void save(Order order);
}
