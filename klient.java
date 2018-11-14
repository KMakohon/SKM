import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;
import java.io.DataOutputStream;
import java.io.*;

class Pro {
    public static void main(String[] args) throws IOException, ConnectException {

        Socket socket = new Socket("150.254.79.86" , 5002 );
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        DataInputStream ans = new DataInputStream(socket.getInputStream());

        Scanner scan = new Scanner(System.in);

        int num = scan.nextInt();
        out.writeInt(num);

        //String s = ans.readUTF();
        //System.out.println("Serwer powiedzial: "+s);

        out.close();
        //ans.close();
        socket.close();
           

// 2 zapis pliku będzie musiał wysłać nazwe  i wysłać zipa (branie ścieżki jako wejścia) 
    }
}

/*
            out.println(userInput);
            System.out.println("received: " + in.readLine());

*/
