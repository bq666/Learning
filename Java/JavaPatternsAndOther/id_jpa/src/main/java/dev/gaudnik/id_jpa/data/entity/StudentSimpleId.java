package dev.gaudnik.id_jpa.data.entity;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class StudentSimpleId {
	@Id
	private Long id;

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}
}
