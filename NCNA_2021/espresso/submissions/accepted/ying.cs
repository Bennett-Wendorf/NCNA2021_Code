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
            int waterInTank = s;
            int countRefill = 0;

            for (int i = 0; i < n; i++)
            {
                string order = orders[i];
                int waterNeed = (order[0] - '0') + ((order.Length > 1) ? 1 : 0);

                if (waterInTank < waterNeed)
                {
                    countRefill++;
                    waterInTank = s - waterNeed;
                }
                else waterInTank -= waterNeed;
            }
            return countRefill;
        }
    }

}

