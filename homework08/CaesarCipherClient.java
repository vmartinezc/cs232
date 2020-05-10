/* Homework 8: Caesar Cipher Client
 * Valeria Martinez (vam6)
 * May 9, 2020
 *
 * Client gets the server's hostname and port via command-line arguments.
 */



import java.util.Scanner;
import java.net.Socket;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStream;

public class CaesarCipherClient{
    public static void main(String[] args){
        System.out.print("Hello how r u");
        
        //check if argument is valid
        if(args.length!=2){
            System.out.println("Wrong number of arguments!");
            System.out.println("Usage: java CaesarCipherClient [arg1] [arg2]");
            System.exit(1)
        }
        String host = args[0];
        Integer port;

        try{
            //check if second argument is a valid integer
            port = Integer.parseInt(args[1]);
        }
        catch(NumberFormatException e){
            System.err.println("Port number must be an integer");
            System.exit(1);
        }

        System.out.println("Welcome to Caesar Cipher Client");
        System.out.println("Enter a rotation between 1 and 25 ");

        Scanner userInput = new Scanner(System.in);
        Integer rotationInt = getInput.nextInt();


        //Check if the integer is positive and less than 25

        if(rotationInt < 1 || rotationInt > 25){
            System.out.println("Rotation number must be a positive whole number less than 25");
            System.exit(1);
        }

        try (
            Socket CaesarServerSocket = new Socket(host, port);
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(CaesarServerSocket.getOutputStream()); 
            BufferedReader in = new BufferedReader (new InputStreamReader(CaesarServerSocket.getInputStrem()));
            
        )
        {
            System.out.println("Connected to" +host+ "on port" + port);
            System.out.println("Type quit to exit");
            out.println.(String.valueOf(rotationInt));
            System.out.println(in.readLine());



            while (true){

            }



        }
    



    }
}

