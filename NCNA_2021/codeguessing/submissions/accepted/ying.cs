using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Text;
using System.Linq;

namespace MidAtlantic
{
    public class Program
    {
        static void Main()
        {
            string[] line1 = Console.ReadLine().Split(' ');
            int a1 = Convert.ToInt32(line1[0]);
            int a2 = Convert.ToInt32(line1[1]);
            string cards = Console.ReadLine();

            CodeGuessingSolution(a1, a2, cards);
            if (canUniquelyDetermin)
            {
                foreach (var i in result) Console.Write(i + " ");
            }
            else Console.WriteLine(-1);
        }

        static List<int> result = new List<int>();
        static bool canUniquelyDetermin = false;
        public static void CodeGuessingSolution(int a1, int a2, string cards)
        {
            List<int> digits = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            digits.Remove(a1);
            digits.Remove(a2);

            int small = Math.Min(a1, a2);
            int big = Math.Max(a1, a2);
            List<int> candidateDigits = new List<int>();
            switch (cards)
            {
                case "ABBA":
                    candidateDigits = digits.Where(x => x > small && x < big).ToList();
                    break;

                case "ABAB":
                    candidateDigits = digits.Where(x => x > small && x < big || x > big).ToList();
                    break;

                case "AABB":
                    candidateDigits = digits.Where(x => x > big).ToList();
                    break;

                case "BAAB":
                    candidateDigits = digits.Where(x => x < small || x > big).ToList();
                    break;                

                case "BBAA":
                    candidateDigits = digits.Where(x => x < small).ToList();
                    break;               

                case "BABA":
                    candidateDigits = digits.Where(x => x > small && x < big || x < small).ToList();
                    break;
            }

            if (candidateDigits.Count == 2)
            {
                canUniquelyDetermin = true;
                result = candidateDigits;
            }
        }
    }

}

