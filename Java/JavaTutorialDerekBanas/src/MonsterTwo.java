import java.util.Arrays;

public class MonsterTwo {
	static char[][] battleBoard = new char[10][10];
	public static void buildBattleBoard(){
		for(char[] row : battleBoard){
			Arrays.fill(row, '*');
		}
	}
	public static void redrawBoard(){
		int k = 1;
		while (k <= 30){System.out.print('-');k++;}
		System.out.println();
		for (int i = 0; i < battleBoard.length; i++){
			for (int j = 0; j < battleBoard[i].length; j++){
				System.out.print("|" + battleBoard[i][j] + "|");
			}
			System.out.println();
		}
		k = 1;
		while (k <= 30){System.out.print('-');k++;}
		System.out.println();
	}

	public final String TOMBSTONE = "Here lies a dead monster";

	private int health = 500;
	private int attack = 20;
	private int movement = 2;
	private boolean alive = true;

	public String name = "Big Monster";
	public char nameChar1 = 'B';
	public int xPosition = 0;
	public int yPosition = 0;
	public static int numOfMonsters = 0;

	public int getAttack(){
		return attack;
	}
	public int getMovement(){
		return movement;
	}
	public int getHealth(){
		return health;
	}
	public boolean getAlive(){
		return alive;
	}
	public void setHealth(int decreaseHealth){
		health -= decreaseHealth;
		if(health < 0){
			alive = false;
		}
	}
	public void setHealth(double decreaseHealth){
		int intDecreaseHealth = (int) decreaseHealth;
		health -= intDecreaseHealth;
		if(health < 0){
			alive = false;
		}
	}
	public void moveMonster(MonsterTwo[] monster, int arrayItemIndex) {
		boolean isSpaceOpen = true;
		int maxXBoardSpace = battleBoard.length - 1;
		int maxYBoardSpace = battleBoard[0].length - 1;

		while (isSpaceOpen) {
			int randomMoveDirection = (int) (Math.random() * 4);
			int randomMoveDistance = (int) (Math.random() * (this.getMovement() + 1));
//			System.out.println(randomMoveDistance + " " + randomMoveDirection);
			battleBoard[this.yPosition][this.xPosition] = '*';
			if (randomMoveDirection == 0) {
				if ((this.yPosition - randomMoveDistance) < 0) {
					this.yPosition = 0;
				} else {
					this.yPosition = this.yPosition - randomMoveDirection;
				}
			} else if (randomMoveDirection == 1) {
				if ((this.xPosition + randomMoveDistance) > maxXBoardSpace) {
					this.xPosition = maxXBoardSpace;
				} else {
					this.xPosition = this.xPosition + randomMoveDirection;
				}
			} else if (randomMoveDirection == 2) {
				if ((this.yPosition + randomMoveDistance) > maxYBoardSpace) {
					this.yPosition = maxYBoardSpace;
				} else {
					this.yPosition = this.yPosition + randomMoveDirection;
				}
			} else if (randomMoveDirection == 3) {
				if ((this.xPosition - randomMoveDistance) < 0) {
					this.xPosition = 0;
				} else {
					this.xPosition = this.xPosition - randomMoveDirection;
				}
			}
			for(int i = 0; i < monster.length; i++){
				if(i == arrayItemIndex){
					continue;
				}
				if(onMySpace(monster, i, arrayItemIndex)){
					isSpaceOpen = true;
					break;
				} else {
					isSpaceOpen = false;
				}
			}

		}
		battleBoard[this.yPosition][this.xPosition] = this.nameChar1;
	}

	public boolean onMySpace(MonsterTwo[] monster, int indexToChk1, int indexToChk2){
		if((monster[indexToChk1].xPosition) == (monster[indexToChk2].xPosition) && (monster[indexToChk1].yPosition) == (monster[indexToChk2].yPosition)){
			return true;
		} else {
			return false;
		}
	}
	public MonsterTwo(int health, int attack, int movement, String name){
		this.health = health;
		this.attack = attack;
		this.movement = movement;
		this.name = name;

		int maxXBoardSpace = battleBoard.length - 1;
		int maxYBoardSpace = battleBoard[0].length - 1;

		int randNumX, randNumY;
		do {
			randNumX = (int) (Math.random() * maxXBoardSpace);
			randNumY = (int) (Math.random() * maxYBoardSpace);
		} while (battleBoard[randNumX][randNumY] != '*');

		this.xPosition = randNumX;
		this.yPosition = randNumY;

		this.nameChar1 = this.name.charAt(0);
		battleBoard[this.yPosition][this.xPosition] = this.nameChar1;
	}

	public MonsterTwo(){
		numOfMonsters++;
	}

//	public static void main(String[] args){
////		MonsterTwo Frank = new MonsterTwo(10, 20, 3);
////		System.out.println(Frank.attack);
////		Frank.buildBattleBoard();
////		System.out.println(Frank.battleBoard.length);
////		Frank.redrawBoard();
////		System.out.println("test");
//		System.out.println(System.getProperty("java.ext.dirs"));
//	}

}
