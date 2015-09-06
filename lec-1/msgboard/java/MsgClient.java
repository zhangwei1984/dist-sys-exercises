// CS 6421 - Simple Message Board Client in Java
// Authors: Chenghu He ang Wei Zhang
// Compile with: javac MsgClient
// Run with:     java MsgClient

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.lang.Object;

public class MsgClient {
    public static void main(String[] args) {
        String host = "gwutestbench.koding.io";
        int portnum = 5555;

        // Your code here!
        String name = "Chenghu & Wei";
        String msg = "Welcome to dist-sys class!";
        Socket sock = null;

        System.out.printf("%d %s\n", args.length, args[0]);
        if (args.length < 3) {
            System.out.printf("Usage: %s hostname name msg\n", args[0]);
            System.exit(1);
        }
        // get host, name ang msg from command line
        host = args[0];
        name = args[1];
        msg = args[2];

        try {
            //create socket and connect to the server
            sock = new Socket(host, portnum);

        } catch (IOException e) {
            e.printStackTrace(); 
        }

        try {
            PrintWriter out = new PrintWriter(sock.getOutputStream(), true); 

            //write name and msg to the server
            System.out.printf("name:%s\n", name);
            out.println(name);
            System.out.printf("msg:%s\n", msg);
            out.println(msg);

            out.close();
            sock.close();
        
        } catch(UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
