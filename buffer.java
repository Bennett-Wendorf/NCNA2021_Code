import java.util.*;

public class buffer {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        long current_time = 1, next_packet = 1;
        Set<Long> packets_buffered = new HashSet<>();

        long number_of_packets = s.nextLong();
        long lag = 0;

        while(s.hasNext()){
            long toa = s.nextLong(), packet = s.nextLong();

            if(toa > current_time){
                lag += toa - current_time;
                current_time = toa;
            }

            if(packet == next_packet){
                current_time = toa + 1;
                next_packet++;
            } else {
                packets_buffered.add(packet);
            }

            while(packets_buffered.contains(next_packet)){
                packets_buffered.remove(next_packet);
                current_time++;
                next_packet++;
            }
        }

        System.out.println(lag);
    }
}
