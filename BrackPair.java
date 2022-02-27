import java.util.*;
import java.util.concurrent.atomic.AtomicLong;

public class BrackPair {
    public static final Character[] OPEN_BRACKETS = {'{', '<', '[', '('};
    public static final Character[] CLOSE_BRACKETS = {'}', '>', ']', ')'};
    public static final Map<Character, Character> BRACKET_PAIRS = new HashMap<>();

    // TODO: ACCOUNT FOR THE ONE OFFS...

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        for (int i = 0; i < OPEN_BRACKETS.length; i++) {
            BRACKET_PAIRS.put(OPEN_BRACKETS[i], CLOSE_BRACKETS[i]);
        }

        while (s.hasNext()) {
            System.out.println(solve(s.nextLine()));
        }

    }

    public static long solve(String s) {
        var stack = new Stack<Character>();
        var number_of_singles = 0;
        Map<Integer, Integer> things = new HashMap<>();

        var current_qs = 0;

        for (char c : s.toCharArray()) {

            if (c != '?' && current_qs > 0) {
                // If odd, make it even, but account for the lone star.
                if (current_qs % 2 == 1) {
                    number_of_singles++;
                    current_qs--;
                }

                if(current_qs != 0) {
                    // Add the collection of qs to map.
                    if (things.containsValue(current_qs))
                        things.put(current_qs, things.get(current_qs) + 1);
                    else things.put(current_qs, 1);

                    // reset the consecutive qs.
                    current_qs = 0;
                }
            }

            if (BRACKET_PAIRS.containsKey(c)) {
                stack.push(c);
            } else if (BRACKET_PAIRS.containsValue(c)) {
                var v = stack.pop();
                if (v != BRACKET_PAIRS.get(c)) {
                    stack.push(v); // push it back
                    // TODO: May have to think about (??} case
                    if (number_of_singles > 0){
                        number_of_singles--;
                    }
                    else if (!things.keySet().isEmpty()){

                    } else {
                        return 0;
                    }
                }
            } else {
                current_qs++;
            }
        }

        // It is valid, and now we need to find how many combinations.
        AtomicLong number_of_combinations = new AtomicLong(1); // The full thing is valid.

        things.keySet().forEach(number_of_qs -> {
            var frequency = things.get(number_of_qs);
            var cs = getCombinations(number_of_qs);

            number_of_combinations.updateAndGet(v -> (long) (v * Math.pow(cs, frequency)));
        });

        return number_of_combinations.longValue();
    }

    public static long getCombinations(int number_of_qs){
        return (long) Math.pow(2, number_of_qs) * (number_of_qs / 2);
    }
}
