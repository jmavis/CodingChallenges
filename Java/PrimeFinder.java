import java.security.InvalidAlgorithmParameterException;
import java.util.ArrayList;
import java.util.List;

/*
 * Author Jared Mavis
 * Username jmavis
 * Project Euler Problem 7
 * Will find the nth prime
 */
public class PrimeFinder {
	private List<Integer> pastPrimes = new ArrayList<Integer>();
	
	public PrimeFinder(){
		pastPrimes.add(2);
	}
	
	public int findNthPrime(int n) throws InvalidAlgorithmParameterException{
		if (n <= 0) throw new InvalidAlgorithmParameterException();
		if (n < pastPrimes.size()) return (pastPrimes.get(n));
		int current = pastPrimes.get(pastPrimes.size()-1) + 1;
		while (n > pastPrimes.size()){
			if (isPrime(current)){
				pastPrimes.add(current);
			}
			current++;
		}
		return (pastPrimes.get(pastPrimes.size()-1));
	}
	
	private boolean isPrime(int toCheck){
		for (int i = 0; i < pastPrimes.size(); i++){
			if (toCheck != pastPrimes.get(i) && toCheck % pastPrimes.get(i) == 0){
				return (false);
			}
		}
		return (true);
	}
}
