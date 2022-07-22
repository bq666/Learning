package spittr.db;

import java.util.List;

import spittr.domain.Spitter;

/**
 * Interfejs repozytorium zawierający operacje utrwalania dla klasy {@link Spitter}.
 * @author habuma
 */
public interface SpitterRepository {

  long count();
  
  Spitter save(Spitter spitter);
  
  Spitter findOne(long id);

  Spitter findByUsername(String username);

  List<Spitter> findAll();

}
