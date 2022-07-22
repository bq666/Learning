package spittr.db;

import java.util.List;

import spittr.domain.Spittle;

/**
 * Interfejs repozytorium zawierający operacje utrwalania dla klasy {@link Spittle}.
 * @author habuma
 */
public interface SpittleRepository {

  long count();

  List<Spittle> findRecent();

  List<Spittle> findRecent(int count);

  Spittle findOne(long id);

  Spittle save(Spittle spittle);

  List<Spittle> findBySpitterId(long spitterId);
  
  void delete(long id);

}
