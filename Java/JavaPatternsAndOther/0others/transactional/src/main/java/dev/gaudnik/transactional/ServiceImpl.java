package dev.gaudnik.transactional;

import jakarta.transaction.Transactional;
import org.springframework.stereotype.Service;

@Service
@Transactional
class ServiceImpl implements ServiceApi{


	@Override
	public void test(int i) {

	}
}
