using System.Runtime.InteropServices;
using System;

namespace app
{
    public class XinputController
    {
        [DllImport("..\\..\\..\\debug\\xinput.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern ControllerState getControllerState(Int32 controller);


    }
}