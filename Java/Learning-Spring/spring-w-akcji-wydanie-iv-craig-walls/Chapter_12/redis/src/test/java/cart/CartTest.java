package cart;

import static org.junit.Assert.*;

import java.util.List;
import java.util.Set;

import org.junit.After;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.data.redis.core.BoundListOperations;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.data.redis.serializer.Jackson2JsonRedisSerializer;
import org.springframework.data.redis.serializer.StringRedisSerializer;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=RedisConfig.class)
public class CartTest {

	/*
	 * WAŻNE: Ta klasa testowa wymaga działającego serwera Redis działającego na
	 *            komputerze lokalnym i nasłuchującego na porcie 6379 (porcie domyślnym).
	 */
	
	@Autowired
	private RedisConnectionFactory cf;
	
	@Autowired
	private RedisTemplate<String, Product> redis;
	
	@After
	public void cleanUp() {
		redis.delete("9788324648887");
		redis.delete("cart");
		redis.delete("cart1");
		redis.delete("cart2");
	}
	
	@Test
	public void workingWithSimpleValues() {
		Product product = new Product();
		product.setSku("9788324648887");
		product.setName("Spring w Akcji");
		product.setPrice(54.99f);
		
		redis.opsForValue().set(product.getSku(), product);
		
		Product found = redis.opsForValue().get(product.getSku());
		assertEquals(product.getSku(), found.getSku());
		assertEquals(product.getName(), found.getName());
		assertEquals(product.getPrice(), found.getPrice(), 0.005);
	}
	
	@Test
	public void workingWithLists() {
		Product product = new Product();
		product.setSku("9788324648887");
		product.setName("Spring w Akcji");
		product.setPrice(39.99f);
		
		Product product2 = new Product();
		product2.setSku("9788324633807");
		product2.setName("Android w Akcji");
		product2.setPrice(99.00f);

		Product product3 = new Product();
		product3.setSku("9788324696789");
		product3.setName("Node.js w Akcji");
		product3.setPrice(49.99f);

		redis.opsForList().rightPush("cart", product);
		redis.opsForList().rightPush("cart", product2);
		redis.opsForList().rightPush("cart", product3);
		
		assertEquals(3, redis.opsForList().size("cart").longValue());
		
		Product first = redis.opsForList().leftPop("cart");
		Product last = redis.opsForList().rightPop("cart");
		
		assertEquals(product.getSku(), first.getSku());
		assertEquals(product.getName(), first.getName());
		assertEquals(product.getPrice(), first.getPrice(), 0.005);

		assertEquals(product3.getSku(), last.getSku());
		assertEquals(product3.getName(), last.getName());
		assertEquals(product3.getPrice(), last.getPrice(), 0.005);

		assertEquals(1, redis.opsForList().size("cart").longValue());
	}
	
	@Test
	public void workingWithLists_range() {
		for(int i=0; i < 30; i++) {
			Product product = new Product();
			product.setSku("ISBN-" + i);
			product.setName("PRODUKT " + i);
			product.setPrice(i + 0.99f);
			redis.opsForList().rightPush("cart", product);
		}
		
		assertEquals(30, redis.opsForList().size("cart").longValue());

		List<Product> products = redis.opsForList().range("cart", 2, 12);
		for(int i=0; i < products.size(); i++) {
			Product product = products.get(i);
			assertEquals("ISBN-" + (i+2), product.getSku());
			assertEquals("PRODUKT " + (i+2), product.getName());
			assertEquals(i + 2 + 0.99f, product.getPrice(), 0.005);
		}
	}
	
	@Test
	public void performingOperationsOnSets() {
		Product product = new Product();
		product.setSku("9788324648887");
		product.setName("Spring w Akcji");
		product.setPrice(54.99f);

		redis.opsForSet().add("cart", product);
		assertEquals(1, redis.opsForSet().size("cart").longValue());
	}
	
	@Test
	public void performingOperationsOnSets_setOperations() {
		for(int i=0; i < 30; i++) {
			Product product = new Product();
			product.setSku("ISBN-" + i);
			product.setName("PRODUKT " + i);
			product.setPrice(i + 0.99f);
			redis.opsForSet().add("cart1", product);
			if (i%3 == 0) {
				redis.opsForSet().add("cart2", product);
			}
		}
		
		Set<Product> diff = redis.opsForSet().difference("cart1", "cart2");
		Set<Product> union = redis.opsForSet().union("cart1", "cart2");
		Set<Product> isect = redis.opsForSet().intersect("cart1", "cart2");
		
		assertEquals(20, diff.size());
		assertEquals(30, union.size());
		assertEquals(10, isect.size());		
		
		Product random = redis.opsForSet().randomMember("cart1");
		// nie jestem przekonany co tu sprawdzać... wynik jest losowy
		assertNotNull(random);
	}

	@Test
	public void bindingToAKey() {
		Product product = new Product();
		product.setSku("9788324648887");
		product.setName("Spring w Akcji");
		product.setPrice(54.99f);
		
		Product product2 = new Product();
		product2.setSku("9788324633807");
		product2.setName("Android w Akcji");
		product2.setPrice(99.00f);

		Product product3 = new Product();
		product3.setSku("9788324696789");
		product3.setName("Node.js w akcji");
		product3.setPrice(49.99f);

		BoundListOperations<String, Product> cart = redis.boundListOps("cart");
		cart.rightPush(product);
		cart.rightPush(product2);
		cart.rightPush(product3);
		
		assertEquals(3, cart.size().longValue());
		
		Product first = cart.leftPop();
		Product last = cart.rightPop();
		
		assertEquals(product.getSku(), first.getSku());
		assertEquals(product.getName(), first.getName());
		assertEquals(product.getPrice(), first.getPrice(), 0.005);

		assertEquals(product3.getSku(), last.getSku());
		assertEquals(product3.getName(), last.getName());
		assertEquals(product3.getPrice(), last.getPrice(), 0.005);

		assertEquals(1, cart.size().longValue());
	}
	
	@Test
	public void settingKeyAndValueSerializers() {
		// potrzebujemy wersji lokalnej, aby móc dostosować ustawienia serializacji
		RedisTemplate<String, Product> redis = new RedisTemplate<String, Product>();
		redis.setConnectionFactory(cf);
		redis.setKeySerializer(new StringRedisSerializer());
		redis.setValueSerializer(new Jackson2JsonRedisSerializer<Product>(Product.class));
		redis.afterPropertiesSet(); // nie jest to potrzebne przy deklaracji w postaci komponentu
		
		Product product = new Product();
		product.setSku("9788324648887");
		product.setName("Spring w Akcji");
		product.setPrice(54.99f);
		
		redis.opsForValue().set(product.getSku(), product);
		
		Product found = redis.opsForValue().get(product.getSku());
		assertEquals(product.getSku(), found.getSku());
		assertEquals(product.getName(), found.getName());
		assertEquals(product.getPrice(), found.getPrice(), 0.005);
		
		StringRedisTemplate stringRedis = new StringRedisTemplate(cf);
		String json = stringRedis.opsForValue().get(product.getSku());
		assertEquals("{\"sku\":\"9788324648887\",\"name\":\"Spring w Akcji\",\"price\":54.99}", json);
	}
	
}
