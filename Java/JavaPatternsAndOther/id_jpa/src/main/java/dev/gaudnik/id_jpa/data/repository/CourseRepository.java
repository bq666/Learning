package dev.gaudnik.id_jpa.data.repository;

import dev.gaudnik.id_jpa.data.entity.Course;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.UUID;

public interface CourseRepository extends JpaRepository<Course, UUID> {
}
