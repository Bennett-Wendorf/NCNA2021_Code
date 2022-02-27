import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class subprime {
    public static void main(String[] args){
        List<BigInteger> primes = new ArrayList<>();
        BigInteger current = BigInteger.ONE;

        while(primes.size() < 100000){
            if(current.isProbablePrime(1)){
                primes.add(current);
            }

            current = current.add(BigInteger.ONE);
        }
    }
}
