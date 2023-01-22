package dev.gaudnik.transactional;
import javax.transaction.Transactional;

@Transactional
interface ServiceApi {

	void test(int i);
}
