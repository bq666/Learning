package dev.gaudnik.transactional;

import org.springframework.transaction.annotation.Transactional;

class Isolation {

	//	suffer from:
//	dirty read: read uncommitted change of a concurrent transaction
//	non-repeatable read: get different value on re-read of a row if a concurrent transaction updates the same row and commits
//	phantom read: get different rows after re-execution of a range query if another transaction adds or removes some rows in the range and commits
//	most concurrent, fastest
	@Transactional(isolation = org.springframework.transaction.annotation.Isolation.READ_UNCOMMITTED)
	public void readUncomitted() {
	}

//	suffer from:
//	non-repeatable read
//	phantom read

	@Transactional(isolation = org.springframework.transaction.annotation.Isolation.READ_COMMITTED)
	public void readCommitted() {
	}

	//	suffer from:
//	phantom read
//	so we are not affected by uncommitted changes in concurrent transactions
//	it is the lowest required level to prevent the lost update
	@Transactional(isolation = org.springframework.transaction.annotation.Isolation.REPEATABLE_READ)
	public void repeatableRead() {
	}

	//	the slowest as transaction one by one in serial
	@Transactional(isolation = org.springframework.transaction.annotation.Isolation.SERIALIZABLE)
	public void serializableRead() {
	}


}
