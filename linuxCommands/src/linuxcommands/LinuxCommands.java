/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linuxcommands;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author katearzate
 */
public class LinuxCommands {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        
        String command, directy = "";
        int c = 0;
        command = read.nextLine();
        
        String[] datos = command.split(" ");

        for(String item : datos)
        {
          if(c == 1){
              directy = item;
          }
          //System.out.println(item);
          c++;
        }
        
        
        File directorio = new File(directy); //directorio a listar                                             
        String[] lista = directorio.list();
        if(lista == null){
            System.out.println("no hay");
        }else{
            for (int i = 0; i < lista.length; i++) {
                System.out.println(lista[i]);
            }
        }
        
        
        /*
        window w = new window();
        w.setTitle("Terminal Simulation");
        w.setLocationRelativeTo(null);
        w.setVisible(true);
        */
    }
    
}
