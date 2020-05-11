
/* Homework 8: Caesar Cipher Server
 * Valeria Martinez (vam6)
 * May 9, 2020
 *
 * Client gets the server's hostname and port via command-line arguments.
 * Followed  tutorial & algorithm from JavaWorld (https://www.javaworld.com/article/2853780/socket-programming-for-scalable-systems.html)
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

    public static void mai(String[] args){
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

             while(true){
                 Socket clientSocket = serverSocket.accept();
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

        BufferedReader input = new BufferedReader(new InputStreamReader(msSocket.getInputStream()));
        PrintWriter dataOut = new PrintWriter(msSocket.getOutputStream(), true);

        String line;
        line = input.readLine();
        int rotationNumber = Integer.valueOf(line);

        if (rotationNumber < 1 || rotationNumber > 25){
            dataOut.print("Please enter a postive whole number less than 25.");
            msSocket.close();

        System.out.println(new Date().toString() + " Disconnected. Invalid Rotation "+ msSocket.getRemoteSocketAddress().toString());


        }
       
        





    }






}
        
      