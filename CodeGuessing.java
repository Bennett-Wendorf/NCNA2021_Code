import java.util.Scanner;

public class CodeGuessing {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        var a1 = in.nextInt();
        var a2 = in.nextInt();
        in.nextLine();

        String card_order = in.next();
        switch(card_order){
            case "AABB":
                if(a2 == 7)
                    System.out.println("8 9");
                else
                    System.out.println("-1");
                break;
            case "ABAB":
                if(a1 == 6 && a2 == 8)
                    System.out.println("7 9");
                else
                    System.out.println("-1");
                break;
            case "ABBA":
                if(a2 - a1 == 3)
                    System.out.println("" + (a1+1) + " " + (a1+2));
                else
                    System.out.println("-1");
                break;
            case "BABA":
                if(a1 == 2 && a2 == 4)
                    System.out.println("1 3");
                else
                    System.out.println("-1");
                break;
            case "BBAA":
                if(a1 == 3)
                    System.out.println("1 2");
                else
                    System.out.println("-1");
                break;
            case "BAAB":
                if(a1 == 2 && a2 == 8)
                    System.out.println("1 9");
                else
                    System.out.println("-1");
                break;
            default:
                System.out.println("FUCK");
        }
    }
}
