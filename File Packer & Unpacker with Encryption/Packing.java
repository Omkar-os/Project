/////////////////////////////////////////////////////////////////////////
//
//  File Name   : FilePacker.java
//  Author      : Omkar Pramod Sudrik
//  Date        : 10/02/2026
//  Description : 
//      This application packs all .txt files from a given directory
//      into a single packed file.
//
//      Each file is stored in the following format:
//      ------------------------------------------------
//      | Header (100 bytes) | Encrypted File Data |
//      ------------------------------------------------
//
//      Header contains:
//      - File name
//      - File size
//
//  Encryption  : XOR Encryption using single-byte key (0x11)
//
//  Purpose     : Demonstrates file handling, directory traversal,
//                byte-level operations, and basic encryption.
//
//  Platform    : Java (JDK 8+)
//
/////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//
// Required Header Files
//
/////////////////////////////////////////////////////////////////////////

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Scanner;


/////////////////////////////////////////////////////////////////////////
//
// Class Name : FilePacker
// Description: Packs multiple text files into a single encrypted file
//
/////////////////////////////////////////////////////////////////////////
/// 
class FilePacker
{
    private static final int HEADER_SIZE = 100;
    private static final byte ENCRYPTION_KEY = 0x11;
    private static final int BUFFER_SIZE = 1024;

    public static void main(String[] args) throws Exception
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the name of folder : ");
        String folderName = scanner.nextLine();

        System.out.print("Enter the name of packed file : ");
        String packedFileName = scanner.nextLine();

        File folder = new File(folderName);

    
        if (!folder.exists() || !folder.isDirectory())
        {
            System.out.println("Error: Folder does not exist.");
            scanner.close();
            return;
        }

        File packedFile = new File(packedFileName);
        packedFile.createNewFile();

        FileOutputStream packStream = new FileOutputStream(packedFile);

        File[] fileList = folder.listFiles();
        System.out.println("Number of files found : " + fileList.length);

        byte[] buffer = new byte[BUFFER_SIZE];

        for (File file : fileList)
        {
            if (file.getName().endsWith(".txt"))
            {
                packSingleFile(file, packStream, buffer);
            }
        }

        packStream.close();
        scanner.close();

        System.out.println("Packing completed successfully.");
    }

/////////////////////////////////////////////////////////////////////////
//
// Function Name : packSingleFile
// Input         : File file, FileOutputStream out
// Output        : void
// Description   : Writes header and encrypted file data into packed file
//
/////////////////////////////////////////////////////////////////////////

    private static void packSingleFile(File file, FileOutputStream packStream, byte[] buffer)
            throws Exception
    {
        FileInputStream inputStream = new FileInputStream(file);

        // Create fixed-size header
        String header = file.getName() + " " + file.length();
        StringBuilder headerBuilder = new StringBuilder(header);

        while (headerBuilder.length() < HEADER_SIZE)
        {
            headerBuilder.append(" ");
        }


        packStream.write(headerBuilder.toString().getBytes(), 0, HEADER_SIZE);

        int bytesRead;

       
        while ((bytesRead = inputStream.read(buffer)) != -1)
        {
            encryptBuffer(buffer, bytesRead);
            packStream.write(buffer, 0, bytesRead);
        }

        inputStream.close();
    }

    private static void encryptBuffer(byte[] buffer, int length)
    {
        for (int i = 0; i < length; i++)
        {
            buffer[i] = (byte) (buffer[i] ^ ENCRYPTION_KEY);
        }
    }
}

/////////////////////////////////////////////////////////////////////////
//
// End of File
//
/////////////////////////////////////////////////////////////////////////

