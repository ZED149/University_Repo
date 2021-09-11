using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace calculator_in_c_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            char operation = '\0';
            Console.WriteLine("Answer is: " + calculator(ref operation) + " and the operation was " + operation);
            Console.ReadLine();
        }

        //Calculator Method
        static double calculator(ref char operation)
        {
            //This is a simple caculator written in c sharp


            //Printing Menu
            Console.WriteLine("There are total of five operations");
            Console.WriteLine("1. Addition (+)\n2. Subtraction(-)\n3. Muliplication(*)\n4. Division(/)\n5. Remainder(%)");
            //decalring variables
            /*char operation;*/
            Console.Write("Enter operation ");
            operation = Convert.ToChar(Console.ReadLine());

            //declaring variables
            double num1, num2;
            if (operation == '+' || operation == 49)
            {
                //Addition Operation
                Console.Write("Enter number 1 ");
                num1 = Convert.ToDouble(Console.ReadLine());
                Console.Write("Enter number 2 ");
                num2 = Convert.ToDouble(Console.ReadLine());

                //performing operation
                double result = num1 + num2;
                return result;
                //Console.WriteLine("Result of " + num1 + " + " + num2 + " = " + result);
            }
            else if (operation == '-' || operation == 50)
            {
                //Subtraction Operation
                Console.Write("Enter number 1 ");
                num1 = Convert.ToDouble(Console.ReadLine());
                Console.Write("Enter number 2 ");
                num2 = Convert.ToDouble(Console.ReadLine());

                //performing operation
                double result = num1 - num2;
                return result;
                //Console.WriteLine("Result of " + num1 + " - " + num2 + " = " + result);
            }
            else if (operation == '*' || operation == 51)
            {
                //Multiplication Operation
                Console.Write("Enter number 1 ");
                num1 = Convert.ToDouble(Console.ReadLine());
                Console.Write("Enter number 2 ");
                num2 = Convert.ToDouble(Console.ReadLine());

                //performing operation
                double result = num1 * num2;
                return result;
                //Console.WriteLine("Result of " + num1 + " x " + num2 + " = " + result);
            }
            else if (operation == '/' || operation == 52)
            {
                //Division Operation
                Console.Write("Enter number 1 ");
                num1 = Convert.ToDouble(Console.ReadLine());
                Console.Write("Enter number 2 ");
                num2 = Convert.ToDouble(Console.ReadLine());

                //performing operation
                double result = num1 / num2;
                return result;
                //Console.WriteLine("Result of " + num1 + " / " + num2 + " = " + result);
            }
            else if (operation == '%' || operation == 53)
            {
                //Modulus Operation
                Console.Write("Enter number 1 ");
                num1 = Convert.ToDouble(Console.ReadLine());
                Console.Write("Enter number 2 ");
                num2 = Convert.ToDouble(Console.ReadLine());

                //performing operation
                double result = num1 % num2;
                return result;
                //Console.WriteLine("Result of " + num1 + " % " + num2 + " = " + result);
            }
            else
            {
                Console.WriteLine("Invalid Operation");
                return -999999999;
            }
        }
    }
}
