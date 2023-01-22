package dev.gaudnik.transactional;


import org.springframework.transaction.annotation.Transactional;

class Propagation {

//	if tr exists add if not create new
	@Transactional(propagation = org.springframework.transaction.annotation.Propagation.REQUIRED)
	public void defaultPropagation() {}

//	if exists add if not run without transaction
	@Transactional(propagation = org.springframework.transaction.annotation.Propagation.SUPPORTS)
	public void supportsPropagation () {}

//	if exists use it if not throw exception
	@Transactional(propagation = org.springframework.transaction.annotation.Propagation.MANDATORY)
	public void mandatoryPropagation() {}

//	if exists throw exception
	@Transactional(propagation = org.springframework.transaction.annotation.Propagation.NEVER)
	public void neverPropagation() {}

//	if exists suspend and execute without transaction
	@Transactional(propagation = org.springframework.transaction.annotation.Propagation.NOT_SUPPORTED)
	public void notSupportedPropagation(){}

//	if exists suspend and create new and execute
	@Transactional(propagation = org.springframework.transaction.annotation.Propagation.REQUIRES_NEW)
	public void requiresNewPropagation(){}

//	if exists make save point and create new, it throws roll back to this point
	@Transactional(propagation = org.springframework.transaction.annotation.Propagation.NESTED)
	public void nestedPropagation(){}
}
