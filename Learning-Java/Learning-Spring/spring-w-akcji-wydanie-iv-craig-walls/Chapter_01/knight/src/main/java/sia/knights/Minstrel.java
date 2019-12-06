package sia.knights;

import java.io.PrintStream;

public class Minstrel {

  private PrintStream stream;
  
  public Minstrel(PrintStream stream) {
    this.stream = stream;
  }

  public void singBeforeQuest() {
    stream.println("Tra la la; Jakiż rycerz jest dzielny!");
  }

  public void singAfterQuest() {
    stream.println("Hip hip hura; Dzielny rycerz wypełnił misję!");
  }

}
