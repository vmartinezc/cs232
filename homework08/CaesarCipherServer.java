
/* Homework 8: Caesar Cipher Server
 * Valeria Martinez (vam6)
 * May 9, 2020
 *
 * Client gets the server's hostname and port via command-line arguments.
 * Followed  tutorial & algorithm from JavaWorld (https://www.javaworld.com/article/2853780/socket-programming-for-scalable-systems.html)
 * and tutorial from https://www.codejava.net/java-se/networking/java-socket-server-examples-tcp-ip
 *
 */

import java.util.Scanner;
import java.net.Socket;
import java.net.ServerSocket;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.util.Date;
import java.text.DateFormat;
import java.io.InputStreamReader;
import java.io.IOException;
import java.text.SimpleDateFormat;

public class CaesarCipherServer{

    public static void main(String[] args){
        if (args.length!=1){
            System.out.println("Wrong number of arguments!");
            System.out.println("Usage: java CaesarCipherServer [port]");
            System.exit(1);
        }

        //Get port from the user
        int port = Integer.parseInt(args[0]);

         try(
            //check if  argument is valid
            ServerSocket serverSocket = new ServerSocket(port);
         )
         {
             System.out.println("Start server on port: " + port);
             System.out.println("Connecting...");

             while(true){
                 System.out.println("Connecting pt 2...");
                 Socket clientSocket = serverSocket.accept();

              //   System.out.println("Connecting pt 3...");

                 System.out.println(new Date().toString() + ": connected to"+ clientSocket.getRemoteSocketAddress().toString());
                 new MultiServerThread(clientSocket).start();
             }
           
         }

             catch (IOException e ){
                 System.out.println("IOException when trying to listen on port "+ port);
                 System.out.println(e.getMessage());
             }
        
    }



}

class MultiServerThread extends Thread {
    private Socket msSocket;

    public MultiServerThread(Socket msSocket){
        this.msSocket = msSocket;
    }

    //code.java.net Java Server Multi thread Algorithm and tutorial
    public void run(){
        try{

        BufferedReader userInput = new BufferedReader(new InputStreamReader(msSocket.getInputStream()));
        PrintWriter dataOut = new PrintWriter(msSocket.getOutputStream(), true);

        String line;
        line = userInput.readLine();
        int rotationNumber = Integer.valueOf(line);

        if (rotationNumber < 1 || rotationNumber > 25){
            dataOut.print("Please enter a postive whole number less than 25.");
            msSocket.close();

        System.out.println(new Date().toString() + "Disconnected. Invalid Rotation: "+ msSocket.getRemoteSocketAddress().toString());
        } 
        dataOut.println("Rotation: " + rotationNumber + " Encrypting...");
        String lineRead = userInput.readLine();

        //check if input is not empty or == quit 
        while(lineRead != null  && !lineRead.isEmpty() && !line.equals("quit")){
            dataOut.println(encryptText(line, rotationNumber));
        }

        msSocket.close();
        System.out.println(new Date().toString() + ": connected to"+ msSocket.getRemoteSocketAddress().toString() + " :Socket closed");

    }catch (IOException ex){
        System.err.println("IO Exception" + ex.getMessage());
        System.exit(1);


            
        }
}


private static String encryptText(String line, int rotationNumber){
    String encryptedText =""; //initialize to empty string
    char character = '\0';

    for(int i = 0; i < line.length(); i++){
        //capitalized
        if(character >= 'A' && character <= 'Z'){
            character = (char)(character + rotationNumber);

            if(character > 'Z'){ //loop around
                character = (char)(character - 'Z' + 'A' - 1);
            }
            encryptedText+= character; 
        }

        //not capitalized
        else if(character >= 'a' && character <= 'z'){
            character = (char)(character + rotationNumber);
            
            if(character > 'Z'){ //loop around
                character = (char)(character - 'Z' + 'A' - 1);

            }
            encryptedText += character; 

    } 
    else{
        encryptedText += character;
    }
    }
        return encryptedText;
       
    }

}
       

        
      
