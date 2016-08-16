/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package e4;
/**
 *
 * @author student
 */
import javax.swing.*;
import java.security.SecureRandom;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Random ;
import java.io.*;
import java.net.*;
public class server {
      static DataInputStream din;
    static DataOutputStream dout;
public static void main(String a[])throws Exception
{
    server s=new server();
    s.run();
}
public void run()throws Exception
{
    ServerSocket srvsock=new ServerSocket(444);
    Socket sock=srvsock.accept();
    InputStreamReader ir=new InputStreamReader(sock.getInputStream());
    BufferedReader br=new BufferedReader(ir);
    String msg=br.readLine();
    System.out.println(msg);
    if(msg!=null)
    {
        PrintStream ps=new PrintStream(sock.getOutputStream());
        ps.println("message successfully received");
    }
    InputStream in=sock.getInputStream();
     File f=new File("C:\\Users\\student.student-PC\\Documents\\NetBeansProjects\\e4\\src\\e4\\decryptfile.txt");
    FileOutputStream fos=new FileOutputStream(f);
    int x=0;
    while(true)
    {
        x=in.read();
        if(x==-1)break;
        fos.write(x);
    }
    fos.close();
    //String msgin="";
   // try{
     //    din=new DataInputStream(sock.getInputStream());
      //     dout=new DataOutputStream(sock.getOutputStream());
        //    while(!msgin.equals("original"))
        //    {
        //        msgin=din.readUTF();

        //    }
        //   System.out.println(msgin);
     //}catch(Exception e)   {}
}
}
