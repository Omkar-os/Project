/////////////////////////////////////////////////////////////////////////
//
//  File Name   : FileUnpacker.java
//  Author      : Omkar Pramod Sudrik
//  Date        : 13/01/2026
//  Description : 
//      This application unpacks files from a single packed file created
//      by the FilePacker utility.
//
//      Packed file format:
//      ------------------------------------------------
//      | Header (100 bytes) | Encrypted File Data |
//      ------------------------------------------------
//
//      Header contains:
//      - Original file name
//      - Original file size
//
//  Decryption  : XOR Decryption using single-byte key (0x11)
//
//  Purpose     : Demonstrates file handling, byte processing,
//                header parsing, and basic decryption logic.
//
//  Platform    : Java (JDK 8+)
//
/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
//
// Required Header Files
//
/////////////////////////////////////////////////////////////////////////

import java.io.*;     
import java.util.*; 


/////////////////////////////////////////////////////////////////////////
//
// Class Name : FileUnpacker
// Description: Extracts individual files from a packed file
//
/////////////////////////////////////////////////////////////////////////

class FileUnpacker
{
    public static void main(String args[]) throws Exception
    {
        /////////////////////////////////////////////////////////////////////
        // Variable Declarations
        /////////////////////////////////////////////////////////////////////

        int fileSize = 0;
        int bytesRead = 0;
        int i = 0;

        byte encryptionKey = 0x11;

        String packedFileName = null;
        String header = null;
        String tokens[] = null;

        Scanner scanner = null;

        File packedFile = null;
        File extractedFile = null;

        FileInputStream packInputStream = null;
        FileOutputStream fileOutputStream = null;

        byte headerBuffer[] = new byte[100];
        byte dataBuffer[] = null;


        /////////////////////////////////////////////////////////////////////
        // Accept Packed File Name
        /////////////////////////////////////////////////////////////////////

        scanner = new Scanner(System.in);

        System.out.print("Enter the name of packed file : ");
        packedFileName = scanner.nextLine();

        packedFile = new File(packedFileName);

        if (packedFile.exists() == false)
        {
            System.out.println("Error : Packed file does not exist");
            return;
        }

        packInputStream = new FileInputStream(packedFile);


        /////////////////////////////////////////////////////////////////////
        // Read Header + Extract Files
        /////////////////////////////////////////////////////////////////////

        while ((bytesRead = packInputStream.read(headerBuffer, 0, 100)) != -1)
        {
            // Convert header bytes to string
            header = new String(headerBuffer).trim();

            // Split header into filename and filesize
            tokens = header.split(" ");

            System.out.println("Extracting file : " + tokens[0]);
            System.out.println("File size       : " + tokens[1]);

            extractedFile = new File(tokens[0]);
            extractedFile.createNewFile();
        }
    }
}

////////////////////////////////////////////////////////////////////////
//
// End of File
//
/////////////////////////////////////////////////////////////////////////