package dev.gaudnik.domain;

import java.math.BigDecimal;
import java.util.UUID;

class OrderItem {

	private UUID id;
	private BigDecimal price;

	public OrderItem(Product product) {
		this.id = product.getId();
		this.price = product.getPrice();

	}

	public UUID getId() {
		return id;
	}

	public BigDecimal getPrice() {
		return null;
	}
}
