package sia.knights;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import sia.knights.Knight;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration
public class KnightXMLInjectionTest {

  @Autowired
  Knight knight;

  @Autowired
  FakePrintStream printStream;

  @After
  public void clearPrintStream() {
    printStream.clear();
  }

  @Test
  public void shouldInjectKnightWithSlayDragonQuest() {
    knight.embarkOnQuest();
    assertEquals(
        "Tra la la; Jakiż rycerz jest dzielny!\n" +
        "Podejmuję misję pokonania smoka!\n" +
        "Hip hip hura; Dzielny rycerz wypełnił misję!\n", 
        printStream.getPrintedString());
  }

}
