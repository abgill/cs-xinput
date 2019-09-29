using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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

            while (true)
            {
                state = XinputController.getControllerState(0);

                Console.Out.WriteLine(state.ToString());
            }
        }
    }
}
