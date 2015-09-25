using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    static void Main(string[] args)
    {
        int L = int.Parse(Console.ReadLine());
        int H = int.Parse(Console.ReadLine());
        string T = Console.ReadLine();
        // Create an array of characters based on the input of T
        char[] cT = T.ToCharArray();
        // Create a position based on the length of cT to determine letters or words
        byte[] pos = new byte[cT.Length];
        // Set the index of the array to be itterated by the loops
        byte index = 0;
        
        // For each character read through the line
        foreach (char c in cT)
        {
            // convert to upper
            pos[index] = (byte)((int)Char.ToUpper(c) - 64);
            
            // If the index is out of bounds convert the data type
            if ((pos[index] <= 0) || (pos[index] > 26))
            {
                pos[index] = (byte)27;
            }
            index++;
        }
        
        // Output the ASCII representation of the text with the correct height
        for (int i = 0; i < H; i++)
        {
            string ROW = Console.ReadLine();
            
            for (int j = 0; j < index; j++)
            {
                Console.Write(ROW.Substring(((pos[j] * L) - L), L));
            }
            
            Console.Write('\n');
        }
    }
}
