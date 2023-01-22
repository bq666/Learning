package dev.gaudnik.id_jpa.data.repository;

import dev.gaudnik.id_jpa.data.entity.StudentSimpleId;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

public interface StudentRepository extends JpaRepository<StudentSimpleId, Long> {
}
