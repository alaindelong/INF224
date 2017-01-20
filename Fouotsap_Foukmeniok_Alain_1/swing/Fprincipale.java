

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;

/**
 * classe principale qui interagit avec le serveur et gère aussi l'interface graphique: ouverture connexion avec le serveur,
 * envoie requête, afficher la reponse du serveur, fermer la connexion, ajouter les lignes de texte sur l'écran 
 * @author fouotsap
 *
 */
public class Fprincipale extends JFrame {
	
	
	//private static final long serialVersionUID = 1L;
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;
	private Socket sock;
	private BufferedReader input;
	private BufferedWriter output;

	private static final long serialVersionUID = 1L;
	private static final int l = 50;
	private static final int c = 80;
	private JTextArea jTextArea;
	private JButton button1;
	private JButton button2;
	private JButton button3;
	private JButton button4;
	private JPanel panel;
	private JScrollPane scrollPane;
	private JMenuBar jMenuBar;
	private JMenu jMenu;
	private JToolBar jToolBar;
	private JMenuItem jMenuItem1;
	private JMenuItem jMenuItem2;
	private JMenuItem jMenuItem3;
	private JTextField jTextField;
	private String str;
	private String host = DEFAULT_HOST;
	 int port = DEFAULT_PORT;
	public static void main(String[] argv) {
		
		String host1 = DEFAULT_HOST;
		 int port1 = DEFAULT_PORT;
		 if (argv.length >=1) host1 = argv[0];
		 if (argv.length >=2) port1 = Integer.parseInt(argv[1]);
		 
		
			try {
				new Fprincipale(host1,port1);
			} catch (IOException e) {
				
				e.printStackTrace();
				System.err.println("Client: Couldn't connect to "+host1+":"+port1);
				   System.exit(1);
			}
			//System.out.println("Client connected to "+host+":"+port);
		 

	}
	/**
	 * 
	 * @param host adresse du serveur
	 * @param port port sur lequel le serveur est en écoute
	 * @throws UnknownHostException
	 * @throws IOException
	 */
  public Fprincipale(String host, int port) throws UnknownHostException, IOException{
	  panel = new JPanel();
	  jTextField = new JTextField(10);
	  jTextArea = new JTextArea(l,c);
	  button1 = new JButton("click to connect");
	  button2 = new JButton("Add ligne");
	  button3 = new JButton("Close");
	  button4 = new JButton("Enter");
	  scrollPane = new JScrollPane(jTextArea);
	  jMenuBar = new JMenuBar();
	  jMenu = new JMenu("Menu");
	  jToolBar = new JToolBar();
	  jMenuItem1 = new JMenuItem("Add ligne");
	  jMenuItem2 = new JMenuItem("Add ligne");
	  jMenuItem3 = new JMenuItem("Close");
	  
	 add(panel,BorderLayout.SOUTH);
	 add(scrollPane,BorderLayout.CENTER);
	 
	 jMenuBar.add(jTextField);
	 jMenuBar.add(jToolBar,BorderLayout.NORTH);
	 jToolBar.add(new AddItMenu("Addline1"));
	 jToolBar.add(new AddItMenu("AddLine2"));
	 jToolBar.add(new AddItMenu("Addline3"));
	 jMenu.add(jMenuItem1);
	 jMenu.add(jMenuItem2);
	jMenu.add(jMenuItem3);
	 
	jMenuItem1.setAction(new AddItMenu("Add1"));
	jMenuItem2.setAction(new AddItMenu("Add2"));
	jMenuItem3.setAction(new CloseMenu("Close"));
	
	 setJMenuBar(jMenuBar);
	 jMenuBar.add(jMenu);//jTextArea.append("Client connected to "+host+":"+port);
	 
	  panel.add(button1);
	  panel.add(button2);
	  panel.add(button3);
	  panel.add(button4);
	  
	  button1.addActionListener(new Connect());
	  button2.addActionListener(new Bt2());
	  button3.addActionListener(new CloseIt());
	  button4.addActionListener(new EnterIt());
	 
	  setDefaultCloseOperation(EXIT_ON_CLOSE);
	 pack();
	 
	 setVisible(true);
	
  }
  
  /**
   * cette classe permet d'établir une connexion avec le serveur quand on clique sur le bouton connect
   * @author fouotsap
   *
   */
 
  class Connect implements ActionListener{

	
	public void actionPerformed(ActionEvent e) {// TODO Auto-generated catch block
		 try {
			   sock = new java.net.Socket(host, port);
			   jTextArea.append("Client connected to "+host+":"+port+"\n");
			 }
			 catch (java.net.UnknownHostException ex) {
			   jTextArea.append("Client: Couldn't find host "+host+":"+port+"\n");
			   
			   try {
				throw ex;
			} catch (UnknownHostException e1) {
				
				e1.printStackTrace();
			}
			 }
			 catch (java.io.IOException ex) {
			   jTextArea.append("Client: Couldn't reach host "+host+":"+port+"\n");
			   try {
				throw ex;
			} catch (IOException e1) {
				
				e1.printStackTrace();
			}
			 }
			 
			 try {
			   input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
			   output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
			 }
			 catch (java.io.IOException ex) {
			   jTextArea.append("Client: Couldn't open input or output streams\n");
			   try {
				throw ex;
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			 }
		//jTextArea.append("une ligne ajoutée\n");
	}
	  
  }
  /**
   * cette classe permet de fermer la fênetre donc fermer la connexion avec le serveur quand on clique sur close
   * @author fouotsap
   *
   */
  class CloseIt implements ActionListener{

	
	public void actionPerformed(ActionEvent e) {
		
		System.exit(0);
	}
	  
  }
  /**
   * permet d'ajouter une ligne de texte sur l'écran
   * @author fouotsap
   *
   */
  
  class AddItMenu extends AbstractAction{

	private static final long serialVersionUID = 1L;

	AddItMenu(String texte){
		super(texte);
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		
		jTextArea.append("ajoutée ligne bouton menu\n");
	}
	  
  }
  /**
   * ferme la connexion et la fenêtre quand on clique sur le bouton close du menu 
   * @author fouotsap
   *
   */
  class CloseMenu extends AbstractAction{

	
	private static final long serialVersionUID = 1L;

	/**
	 * 
	 * @param texte
	 */
	CloseMenu(String texte){
		super(texte);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		
		System.exit(0);
	}
	  
  }
  /**
   * 
   * @author fouotsap
   * Classe qui permet de récupérer la requête et de l'envoyer au serveur
   */
   class EnterIt implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		
		
		str=jTextField.getText();
		if(!str.isEmpty()){
			
		//jTextArea.append(str+"\n");
			try {
				jTextArea.append(send(str)+"\n");
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			//send(str);
		
		}else{
			jTextArea.append("no request done! enter something in the text field\n");
		}
	}
	
   }
   /**
    * 
    * @param request string contenant la requête du client
    * @return null en cas d'érreur
    * @throws java.io.IOException
    */
   public String send(String request) throws java.io.IOException {
	   // Envoyer la requete au serveur
	   try {
	     request += "\n";  // ajouter le separateur de lignes
	     output.write(request, 0, request.length());
	     output.flush();
	   }
	   catch (java.io.IOException e) {
	     jTextArea.append("Client: Couldn't send message: " + e+"\n");
	     return null;
	   }
	   
	   // Recuperer le resultat envoye par le serveur
	   try {
	     return input.readLine();
	   } catch (java.io.IOException e) {
		   jTextArea.append("Client: Couldn't receive message: " + e+"\n");
		   return null;
		 }
	  }
   /**
    * 
    * @author fouotsap
    * Bt2 permet d'ajouter un ligne de texte à l'écran quand on clique sur un bouton de jToolBar
    *
    */
   class Bt2 implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		jTextArea.append("i have nothing to do\n");
	}
	   
   }
  
}
