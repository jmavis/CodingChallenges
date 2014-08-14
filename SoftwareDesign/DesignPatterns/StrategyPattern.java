public class StrategyPatternExampleBasic{
	public static void main(String args[]){
		Console console = System.console();
		String choice = console.readLine("Do you want a [C]at or [D]og Companion?");
		Companion companion;
		if (choice.Equals("C")){
			companion = new catCompanion();
		} else if (choice.Equals("D")){
			companion = new dogCompanion();
		} else {
			System.out.println("Only good people who read directions get a companion");
			return();
		}
		companion.speak();
	}

	/**
		Base class for a player's animal companion.
		Currently has a speak function
	*/
	private abstract class Companion{
		public abstract void speak();
	}

	public class dogCompanion{
		public void speak(){
			System.out.println("Woof");
		}
	}

	public class catCompanion{
		public void speak(){
			System.out.println("Nya");
		}
	}
}