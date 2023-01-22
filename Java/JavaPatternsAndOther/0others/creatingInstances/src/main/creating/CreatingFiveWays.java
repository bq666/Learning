package creating;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

class CreatingFiveWays {
	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, NoSuchMethodException, InvocationTargetException, CloneNotSupportedException, IOException {
		var one = new CreatingFiveWays();

		var c = Class.forName("creating.ClassToBeInstantiated");
		var two = (ClassToBeInstantiated) c.newInstance();
		var twoBid = ClassToBeInstantiated.class.newInstance();

		Constructor<ClassToBeInstantiated> ctob = ClassToBeInstantiated.class.getConstructor();
		ctob.setAccessible(true);
		var three = (ClassToBeInstantiated) ctob.newInstance();

		var test = new ClassToBeInstantiated();
		var four = (ClassToBeInstantiated)test.clone();

		var test2 = new ClassToBeInstantiated();
		FileOutputStream fos = new FileOutputStream("serialized.txt");
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		oos.writeObject(test2);
		FileInputStream fis = new FileInputStream("serialized.txt");
		ObjectInputStream ois = new ObjectInputStream(fis);
		var five = (ClassToBeInstantiated)ois.readObject();
	}
}

