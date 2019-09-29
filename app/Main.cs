using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using app;

using System.Runtime.InteropServices;

namespace app
{
    class MainClass
    {

        
        static void Main(string[] args)
        {
            // Display the number of command line arguments:

            Console.Out.WriteLine(System.AppDomain.CurrentDomain.BaseDirectory);

            ControllerState state = XinputController.getControllerState(0);
            System.Console.WriteLine(args.Length);

            Console.CursorVisible = false;

            while (true)
            {
                state = XinputController.getControllerState(0);

                Console.SetCursorPosition(0, 1);

                Console.Out.WriteLine(state.ToString());

            }
        }
    }
}
