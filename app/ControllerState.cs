
using System.Runtime.InteropServices;
using System;
using System.Text;

namespace app
{
    [StructLayout(LayoutKind.Sequential)]
    public struct ControllerState
    {

        public int IS_CONNECTED;

        public int A;
        public int B;
        public int X;
        public int Y;

        public int LB;
        public int RB;

        public int LS;
        public int RS;

        public int DPAD_UP;
        public int DPAD_DOWN;
        public int DPAD_LEFT;
        public int DPAD_RIGHT;

        public int START;
        public int SELECT;

        public System.Single LEFT_STICK_X;
        public System.Single LEFT_STICK_Y;

        public System.Single RIGHT_STICK_X;
        public System.Single RIGHT_STICK_Y;

        public System.Single LEFT_TRIGGER;
        public System.Single RIGHT_TRIGGER;

        public override string ToString()
        {
            var sb = new StringBuilder();

            sb.AppendLine("A: " + A);
            sb.AppendLine("B: " + B);
            sb.AppendLine("X: " + X);
            sb.AppendLine("Y: " + Y);

            sb.AppendLine("LB: " + LB);
            sb.AppendLine("RB: " + RB);

            sb.AppendLine("LS: " + LS);
            sb.AppendLine("RS: " + RS);
            sb.AppendLine();

            sb.AppendLine("Left Stick X: " + LEFT_STICK_X + "\t\t");  //Hack to ensure this line gets printed correctly
            sb.AppendLine("Left Stick Y: " + LEFT_STICK_Y + "\t\t");
            sb.AppendLine("Right Stick X: " + RIGHT_STICK_X + "\t\t");
            sb.AppendLine("Right Stick Y: " + RIGHT_STICK_Y + "\t\t");
            sb.AppendLine();

            sb.AppendLine("Left trigger: " + LEFT_TRIGGER + "\t\t");
            sb.AppendLine("Right trigger: " + RIGHT_TRIGGER + "\t\t");
            sb.AppendLine();

            sb.AppendLine("Dpad Up: " + DPAD_UP);
            sb.AppendLine("Dpad Down: " + DPAD_DOWN);
            sb.AppendLine("Dpad Left: " + DPAD_LEFT);
            sb.AppendLine("Dpad Right: " + DPAD_RIGHT);



            return sb.ToString();
        }
    }

    
}