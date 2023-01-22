package dev.gaudnik.domain;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.UUID;


public class Order {

	private UUID id;
	private Status status;
	private List<OrderItem> orderItems;
	private BigDecimal price;

	public Order(UUID id, Product product) {
		this.id = id;
		this.orderItems = new ArrayList<>(Arrays.asList(new OrderItem(product)));
		this.status = Status.CREATED;
	}

	public void complete() {
		validateState();
		this.status = Status.COMPLETED;
	}

	public void addOrder(Product product) {
		validateState();
		validateProduct();
		orderItems.add(new OrderItem(product));
		price = price.add(product.getPrice());
	}

	public void removeOrder(UUID id) {
		validateState();
		final OrderItem orderItem = getOrderItem(id);
		orderItems.remove(orderItem);
		price = price.subtract(orderItem.getPrice());

	}

	private OrderItem getOrderItem(UUID id) {
		return orderItems.stream().filter(orderItem -> orderItem.getId().equals(id)).findFirst().orElseThrow();
	}

	private void validateProduct() {

	}

	private void validateState() {

	}

	public UUID getId() {
		return id;
	}

	public enum Status {
		CREATED, COMPLETED, ORDERED, CANCELLED, SENT
	}
}
