/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package e4;

/**
 *
 * @author student
 */
import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.CipherOutputStream;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESKeySpec;
import java.io.*;
import java.net.*;
public class client {
       static DataInputStream din;
    static DataOutputStream dout;
public static void main(String a[])throws Exception
{
    client c=new client();
    c.run();
}
public static void encrypt(String key, InputStream is, OutputStream os) throws Throwable {
		encryptOrDecrypt(key, Cipher.ENCRYPT_MODE, is, os);
	}

	public static void decrypt(String key, InputStream is, OutputStream os) throws Throwable {
		encryptOrDecrypt(key, Cipher.DECRYPT_MODE, is, os);
	}

	public static void encryptOrDecrypt(String key, int mode, InputStream is, OutputStream os) throws Throwable {

		DESKeySpec dks = new DESKeySpec(key.getBytes());
		SecretKeyFactory skf = SecretKeyFactory.getInstance("DES");
		SecretKey desKey = skf.generateSecret(dks);
		Cipher cipher = Cipher.getInstance("DES"); // DES/ECB/PKCS5Padding for SunJCE

		if (mode == Cipher.ENCRYPT_MODE) {
			cipher.init(Cipher.ENCRYPT_MODE, desKey);
			CipherInputStream cis = new CipherInputStream(is, cipher);
			doCopy(cis, os);
		} else if (mode == Cipher.DECRYPT_MODE) {
			cipher.init(Cipher.DECRYPT_MODE, desKey);
			CipherOutputStream cos = new CipherOutputStream(os, cipher);
			doCopy(is, cos);
		}
	}

	public static void doCopy(InputStream is, OutputStream os) throws IOException {
		byte[] bytes = new byte[64];
		int numBytes;
		while ((numBytes = is.read(bytes)) != -1) {
			os.write(bytes, 0, numBytes);
		}
		os.flush();
		os.close();
		is.close();
	}
public void run()throws Exception
{
    Socket sock=new Socket("localhost",444);
    PrintStream ps=new PrintStream(sock.getOutputStream());
    ps.println("Hello to Server from Client");
    InputStreamReader ir=new InputStreamReader(sock.getInputStream());
    BufferedReader br=new BufferedReader(ir);
    String msg=br.readLine();
    System.out.println(msg);
    OutputStream out=sock.getOutputStream();
 
    try {
			String key = "aymanmir123"; // needs to be at least 8 characters for DES

			FileInputStream fis = new FileInputStream("C:\\Users\\student.student-PC\\Documents\\NetBeansProjects\\e4\\src\\e4\\original.txt");
			FileOutputStream fos = new FileOutputStream("C:\\Users\\student.student-PC\\Documents\\NetBeansProjects\\e4\\src\\e4\\encrypted.txt");
			encrypt(key, fis, fos);

			FileInputStream fis2 = new FileInputStream("C:\\Users\\student.student-PC\\Documents\\NetBeansProjects\\e4\\src\\e4\\encrypted.txt");
			FileOutputStream fos2 = new FileOutputStream("C:\\Users\\student.student-PC\\Documents\\NetBeansProjects\\e4\\src\\e4\\decrypted.txt");
			decrypt(key, fis2, fos2);
		} catch (Throwable e) {
			e.printStackTrace();
		}
    File f=new File("C:\\Users\\student.student-PC\\Documents\\NetBeansProjects\\e4\\src\\e4\\encrypted.txt");
    FileInputStream fis=new FileInputStream(f);
    int x=0;
    while(true)
    {
        x=fis.read();
        if(x==-1)break;
        out.write(x);

    }
        out.close();

    InputStream in=sock.getInputStream();
    File f1=new File("C:\\Users\\student.student-PC\\Documents\\NetBeansProjects\\e4\\src\\e4\\plain.txt");
    FileOutputStream fos=new FileOutputStream(f1);
    int x1=0;
    while(true)
    {
        x1=in.read();
        if(x1==-1)break;
        fos.write(x1);
    }
    fos.close();

      /*  try{
            din=new DataInputStream(sock.getInputStream());
            dout=new DataOutputStream(sock.getOutputStream());
        String msgout="Enter filename to download";
       // msgout=msg_text.getText().trim();
        dout.writeUTF(msgout);
        }catch(Exception e){}*/


    /*System.out.println("Enter 1 to recieve the file from server");
    msg=br.readLine();
    int a=String.ParseInt()
    System.out.println(msg);
   out=sock.getOutputStream();
    out.write();
    out.close();*/


}
}
