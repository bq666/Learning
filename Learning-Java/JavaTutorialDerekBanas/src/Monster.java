public class Monster {

	public final String TOMBSTONE = "Here Lies a Dead Monster";
	private int health = 500;
	private int attack = 20;
	private int movement = 2;
	private int xPosition = 0;
	private int yPosition = 0;
	private boolean alive = true;

	public String name = "Big Monster";

	public Monster(int Health, int newAttack, int newMovement){
		this.health = Health;
		attack = newAttack;
		movement = newMovement;
	}

	// Defaul Constructor
	public Monster(){

	}

	public Monster(int newHealth){
		health = newHealth;
	}

	public Monster(int newHealth, int newAttack){
		this(newHealth);
		attack = newAttack;
	}


	public int getAttack(){
		return attack;

	}
	public int getMovement(){
		return movement;
	}

	public int getHealth(){
		return health;
	}

	public void setHealth(int decreaseHealth){
		health = health - decreaseHealth;
		if (health < 0){
			alive = false;
		}
	}

	public void setHealth(double decreaseHealth){
		int intDecreaseHealth = (int) decreaseHealth;
		if (health < 0){
			alive = false;
		}
	}

	public static void main(String[] args){
		Monster Frank = new Monster();
		System.out.println(Frank.attack);
	}

}
