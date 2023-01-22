package dev.gaudnik.id_jpa.controler;


import dev.gaudnik.id_jpa.data.entity.StudentSimpleId;
import dev.gaudnik.id_jpa.data.repository.StudentRepository;
import lombok.AllArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.PostConstruct;
import java.util.List;

@AllArgsConstructor
@RestController
class IdController {

	final StudentRepository studentRepository;

	@GetMapping("/test")
	List<StudentSimpleId> getId() {
		return studentRepository.findAll();
	}

	@PostConstruct
	void bootstrap() {
		var student = new StudentSimpleId();
		student.setId(1L);
		studentRepository.save(student);
	}

}
