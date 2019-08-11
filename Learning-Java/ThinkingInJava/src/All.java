import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class All {
	public static void main(String[] args) {
		List<Object> myList = new ArrayList<>();
		int i1 = 0x2f;
		int i2 = 0X2F;
		int i3 = 0177;
		char c = 0xffff;
		byte b = 0x7f;
		short s = 0x7fff;
		long n1 = 200L;
		long n2 = 200l;
		long n3 = 200;
		float f1 = 1;
		float f2 = 1F;
		float f3 = 1f;
		double d1 = 1d;
		double d2 = 1D;
		Collections.addAll(myList, i1, i2, i3, c, b, s, n1, n2, n3, f1, f2, f3, d1, d2);
		for (Object item : myList) {
			System.out.println(item);
		}


		int a = 1;
		for (int i = 0; i < 8; i++) {
			a = a << 1;
			System.out.println(Integer.toString(a, 2) + " " + a);

		}


		String name = "";
		name += "First";
		name += " Second";
		System.out.println(name);
		int x = 0;
		int y = 1;
		System.out.println(x = x + y);

		name = "This is a simple sentence, for a foreach loop";
		for (char aa : name.toCharArray()) {
			System.out.println(aa);
		}


		for(;;){
			a++;
			if (a == 100) {
				a = 0;
				break;
			}
		}

		myLable:
		while (true) {
			b++;
			if (a == 100 && b != 100) {
				a = 0;
				break myLable;
			} else if (b == 100) {
				break;
			}
		}


	}
}
