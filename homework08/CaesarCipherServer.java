
/* Homework 8: Caesar Cipher Server
 * Valeria Martinez (vam6)
 * May 9, 2020
 *
 * Client gets the server's hostname and port via command-line arguments.
 */




import java.util.Scanner;
import java.net.Socket;
import java.net.ServerSocket;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class CaesarCipherServer{

    public static void mai(String[] args){
        if (args.length!=1){
             System.out.println("Wrong number of arguments!");
            System.out.println("Usage: java CaesarCipherServer [portNumber]");
            System.exit(1);
        }
    }
}