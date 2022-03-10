using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Text;

namespace MidAtlantic
{
    public class Program
    {
        static void Main()
        {
            string[] line1 = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(line1[0]);
            int s = Convert.ToInt32(line1[1]);
            string[] orders = new string[n];
            for (int i = 0; i < n; i++)
            {
                orders[i] = Console.ReadLine();
            }
            int ans = EspressonSolution(n,s,orders);
            Console.WriteLine(ans);
        }

        public static int EspressonSolution(int n, int s, string[] orders)
        {
            int waterOZ = 0;
            int countRefill = 0;

            for (int i = 0; i < n; i++)
            {
                string cur = orders[i];
                waterOZ += (cur[0] - '0');// [1 - 4]: only 1 digit
                if (cur.Length > 1) waterOZ++;

                if (waterOZ > s)
                {
                    countRefill++;
                    waterOZ -= s;
                }
            }

            return countRefill;
        }
    }

}