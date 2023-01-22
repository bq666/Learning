package dev.gaudnik.infrastructure;

import org.springframework.data.mongodb.repository.config.EnableMongoRepositories;

@EnableMongoRepositories(basePackageClasses = SpringDataMongoOrderRepository.class)
class MongoDBConfiguration {
}
