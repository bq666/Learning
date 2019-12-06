package soundsystem;

import static org.junit.Assert.assertEquals;

import org.junit.Rule;
import org.junit.Test;
import org.junit.contrib.java.lang.system.StandardOutputStreamLog;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes=SoundSystemConfig.class)
public class ImportXmlConfigTest {

  @Rule
  public final StandardOutputStreamLog log = new StandardOutputStreamLog();

  @Autowired
  private MediaPlayer player;


  @Test
  public void play() {
    player.play();
    assertEquals(
        "Odtwarzam utwór Sgt. Pepper's Lonely Hearts Club Band artysty The Beatles\n" +
        "-Utwór: Sgt. Pepper's Lonely Hearts Club Band\n" +
        "-Utwór: With a Little Help from My Friends\n" +
        "-Utwór: Lucy in the Sky with Diamonds\n" +
        "-Utwór: Getting Better\n" +
        "-Utwór: Fixing a Hole\n",
        log.getLog());
  }

}
