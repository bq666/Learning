using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using static System.Math;

namespace Snipets
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Single test = Single.MaxValue;
            Console.WriteLine(test);
            float test2 = float.MaxValue;
            Console.WriteLine(test2);
            string test3 = "234";
            long test4 = Convert.ToInt64(test3);

        }

        public static long QueueTime(int[] customers, int n)
        {
            var registers = new List<int>(Enumerable.Repeat(0, n));

            foreach(int cust in customers){
                registers[registers.IndexOf(registers.Min())] += cust;
            }
            return registers.Max();
        }

        public static string isSumOfCubes(string s)
        {
            var cubic = Regex.Matches(s, @"\d{1,3}").Cast<Match>()
                .Select(x => x.Value)
                .Where(x => Math.Abs(x.Select(c => Pow((int)char.GetNumericValue(c), 3)).Sum() - int.Parse(x)) < 0.001)
                .Select(x => int.Parse(x))
                .ToArray();

            return !cubic.Any() ? "Unlucky" : cubic.Aggregate(string.Empty, (a, b) => a + b + ' ') + cubic.Sum() + " Lucky";
        }
    }
//todo    C# is strongly-typed, so it requires us to specify the data types that we’re using.
//todo    It is also statically-typed, which means it will check that we used the correct types before the program even runs.
//todo    Both language features are important because they help write scalable code with fewer bugs.
}