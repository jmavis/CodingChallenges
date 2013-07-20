import java.util.ArrayList;
import java.util.List;

/**
 * Will find the largest prime palindrome under 1000
 * @author Jared Mavis
 */
public class PrimePalindrome {
	public static void main(String args[]){
		PrimePalindrome primePalindromeFinder = new PrimePalindrome();
		System.out.println(primePalindromeFinder.findLargestPrimePalindrom(1000));
	}
	
	/**
	 * Will find the largest prime palindrome that is less than the given max number
	 * @param max
	 */
	public int findLargestPrimePalindrom(int max){
		if (max <= 1) throw new IllegalArgumentException("Attempting to find prime below 2");
		int highestFoundPrimePalindrome = 2;
		List<Integer> pastPrimes = new ArrayList<Integer>();
		pastPrimes.add(2);
		
		for (int i = 3; i < max; i++){
			if (isPrime(i, pastPrimes)){
				pastPrimes.add(i);
				
				if (isPalindrome(i)){
					highestFoundPrimePalindrome = i;
				}
			}
		}
		return (highestFoundPrimePalindrome);
	}
	
	/**
	 * Will determine if the given number is a prime based on the past primes
	 * @param num
	 * @param pastPrimes
	 * @return true if the number is a prime or false otherwise
	 */
	public boolean isPrime(int num, List<Integer> pastPrimes){
		for (Integer prime : pastPrimes){
			if (num % prime == 0){
				return (false);
			}
		}
		return (true);
	}
	
	/**
	 * Will determine if the given number is a palidrome or not
	 * @param num
	 * @return true if is is a palindrome or false otherwise
	 */
	public boolean isPalindrome(int num){
		String conversion = Integer.toString(num);
		int numLength = conversion.length()-1;
		for (int i = 0; i < numLength-i; i++){
			if (conversion.charAt(i) != conversion.charAt(numLength-i)){
				return (false);
			}
		}
		return (true);
	}
}
