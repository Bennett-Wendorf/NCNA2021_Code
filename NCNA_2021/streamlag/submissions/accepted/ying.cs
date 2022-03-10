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
            string line1 = Console.ReadLine();
            int n = Convert.ToInt32(line1);
            int[] receivedTime = new int[n + 1]; //n max is 1000

            for (int i = 0; i < n; i++)
            {
                string[] line = Console.ReadLine().Split(" ");
                int timeStamp = Convert.ToInt32(line[0]);
                int content = Convert.ToInt32(line[1]);
                receivedTime[content] = timeStamp;
            }

            int ans = SteamLagSolution(n, receivedTime);
            Console.WriteLine(ans);
        }

        public static int SteamLagSolution(int n, int[] receivedTime)
        {
            int time = 0;// time now
            for (int i = 1; i < n + 1; i++)
            {
                if (receivedTime[i] > time) time = receivedTime[i];
                else time++;
            }
            return time - n;
        }
    }

}

