package dev.gaudnik.application;

import dev.gaudnik.domain.OrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.UUID;

@RestController
@RequestMapping("/orders")
class OrderController {

	private OrderService orderService;

	@Autowired
	public OrderController(OrderService orderService) {
		this.orderService = orderService;
	}

	@PostMapping
	CreateOrderResponse createOrder(@RequestBody CreateOrderRequest request) {
		UUID id = orderService.createOrder(request.getProduct());

		return new CreateOrderResponse(id);
	}

	@PostMapping(value = "/{id}/products")
	void addProduct(@PathVariable UUID id, @RequestBody AddProductRequest request) {
		orderService.addProduct(id, request.getProduct());
	}

	@DeleteMapping(value = "/{id}/products")
	void deleteProduct(@PathVariable UUID id, @RequestParam UUID productId) {
		orderService.deleteProduct(id, productId);
	}

	@PostMapping("/{id}/complete")
	void completeOrder(@PathVariable UUID id) {
		orderService.completeOrder(id);
	}
}
